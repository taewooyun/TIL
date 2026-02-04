## [STM32F401RB 데이터 시트](https://www.st.com/resource/en/datasheet/stm32f401re.pdf)

`TABLE 9. Alternate function mapping`

---

| **장치** | **명칭** | **통신 방법** | **비고** |
| --- | --- | --- | --- |
| LED MATRIX | HPRO-0063 | HUB75 인터페이스 | [레퍼런스](https://www.waveshare.com/wiki/RGB-Matrix-P2.5-64x64) |
| 스피커 및 앰프 모듈 | SY-SPK059 | I2S |  |
| - | MAX98357A | - |  |
| SD카드 소켓 | SZH-EKBZ-005 | SPI |  |
| 유해가스 센서(Co2 | MQ-135  | ADC | 예열 / 외부 전원 필요 |
| 일산화탄소 센서 | MQ-7 | ADC | 예열 / 외부 전원 필요 |

## SPI

## 1. **SPI (Serial Peripheral Interface)**

- **동기식 직렬 통신**
- **Master–Slave 구조**
- **클럭은** **Master가 생성**

![image.png](attachment:b6ca8eb7-07ef-4537-9110-02e22de35604:image.png)

기존 시리얼 통신에서 사용하던 start bit와 stop bit를 사용하지 않고 클럭 선을 두어 라이징(low에서 HIGH로)신호, 또는 폴링(HIGH에서 LOW로)신호에 맞춰 동기식으로 데이터를 읽어 온다.

---

## 2. SPI 신호선

| 신호 | 의미 | 설명 |
| --- | --- | --- |
| **SCK** | Serial Clock | 클럭 (Master → Slave) |
| **MOSI** | Master Out Slave In | Master → Slave 데이터 |
| **MISO** | Master In Slave Out | Slave → Master 데이터 |
| **CS / NSS** | Chip Select | Slave 선택 (보통 Active Low) |
- SCK
    - 이 클럭의 엣지(상승/하강)에 맞춰 데이터 샘플링
    - CPOL / CPHA 설정에 따라 언제 읽고 쓰는지가 달라짐
        - CPOL : 클럭이 idle(대기) 상태일 때의 레벨
            - 0 → 클럭이 Low 상태로 쉬고 있음
            - 1 → 클럭이 High 상태로 쉬고 있음
        - CPHA
            - 
- MOSI
    - 
- MISO
    - 
- CS / NSS
    - 

---

## 3. 동작 개념 (한 줄 요약)

```
CS ↓
SCK 토글
MOSI/MISO 동시에 한 비트씩 교환
CS ↑
```

- **풀듀플렉스** (보내면서 동시에 받음)
- 클럭 1번 = 데이터 1비트

---

## 4. SPI 모드 (CPOL / CPHA)

| Mode | CPOL | CPHA | Idle Clock | 데이터 샘플링 | 비고 |
| --- | --- | --- | --- | --- | --- |
| 0 | 0 | 0 | Low | Rising edge | 가장 흔함 |
| 1 | 0 | 1 | Low | Falling edge |  |
| 2 | 1 | 0 | High | Falling edge |  |
| 3 | 1 | 1 | High | Rising edge |  |

---

## 5. CubeIDE 설정 순서 (중요 ⭐)

### ✅ 1. SPI 활성화

- `SPI1` or `SPI2`
- **Mode**: Full-Duplex Master
- **Hardware NSS** ❌
    
    → **Software NSS** ✅ (CS는 GPIO로 직접 제어)
    

### ✅ 2. 파라미터

- Data Size: **8-bit**
- First Bit: **MSB**
- Prescaler: **64 or 128** (처음엔 느리게)
- Clock Polarity / Phase: **Slave 맞춰서**

### ✅ 3. GPIO

- SCK / MOSI / MISO → **Alternate Function**
- CS → **GPIO Output**

---

## 6. 코드 흐름 (HAL 기준)

### 🔹 기본 송신

```c
uint8_t tx = 0x9A;
HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
HAL_SPI_Transmit(&hspi1, &tx, 1, HAL_MAX_DELAY);
HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
```

### 🔹 송수신 (실전에서 제일 많이 씀)

```c
uint8_t tx = 0x00;
uint8_t rx = 0x00;

HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
HAL_SPI_TransmitReceive(&hspi1, &tx, &rx, 1, HAL_MAX_DELAY);
HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
```

📌 **SPI는 항상 클럭을 줘야 받는다**

→ 그래서 “읽기”도 더미 데이터 전송 필요

---

## 7. SPI 사용 패턴

### 레지스터 읽기 패턴

```c
CS ↓
WRITE: (READ_CMD | addr)
READ: dummy → data
CS ↑
```

### 레지스터 쓰기 패턴

```c
CS ↓
WRITE: (WRITE_CMD | addr)
WRITE: data
CS ↑
```

---

```c
int _write(int file, char *ptr, int len)
{
    HAL_UART_Transmit(&huart2, (uint8_t*)ptr, len, HAL_MAX_DELAY);
    return len;
}

uint8_t tx_data = 0xA5;
uint8_t rx_data = 0x00;
int main(void)
{
	...
  while (1)
  {
    /* USER CODE END WHILE */
		rx_data = 0x00;
	
		HAL_SPI_TransmitReceive(
			&hspi2,
			&tx_data,
			&rx_data,
			1,
			HAL_MAX_DELAY
		);
	
		printf("rx_data: %d\r\n", rx_data);
		HAL_Delay(1000);
  }
  ...
}
```




## 더미데이터의 필요성
이 질문이 **SPI를 소프트웨어 관점에서 보다가 → 하드웨어 관점으로 넘어가는 지점**이야.
지금 헷갈린 포인트를 정확히 짚고 있어 👍

결론부터 말하면:

> **SCK는 “비트 타이밍 신호”이고,
> MOSI/MISO는 “데이터 스트림”이 맞다.
> 그런데 대부분 MCU에서는 SCK를 ‘데이터 전송 엔진’이 같이 만들어서
> 클럭만 따로 줄 수 없게 설계돼 있다.**

차근차근 풀자.

---

## 1️⃣ 물리적으로는 다른 신호선이 맞음

핀 레벨로 보면:

* SCK → 클럭 스트림
* MOSI → 데이터 스트림
* MISO → 데이터 스트림

👉 **완전히 독립된 선**이고
👉 전기적으로 “같은 스트림”은 절대 아님

그래서 **이론적으로는**

* SCK만 토글하고
* MOSI는 고정
* MISO만 읽기

도 **가능해 보임**

---

## 2️⃣ 그런데 MCU 내부 구조가 문제의 핵심

대부분 MCU의 SPI는 이렇게 생겼어:

```text
[ TX Shift Register ] → MOSI
          ↓
        (동시에)
          ↓
[ Clock Generator ] → SCK
          ↑
[ RX Shift Register ] ← MISO
```

📌 핵심 포인트:

* **TX 시프트가 돌아갈 때만**
* **SCK가 자동으로 생성됨**

즉,

> **“클럭 생성기 = 전송 로직에 묶여 있음”**

---

## 3️⃣ 그래서 “더미 데이터”가 필요한 이유

SPI 하드웨어 입장에서 보면:

* “전송할 바이트가 있다”
  → TX 레지스터에 값이 있음
  → 시프트 시작
  → SCK 발생

* “전송할 게 없다”
  → ❌ 시프트 안 함
  → ❌ SCK 안 나옴

👉 **클럭만 달라고 할 방법이 없음**

그래서 소프트웨어가 하는 꼼수(?)가:

```c
SPI_DR = 0xFF;   // 의미 없는 값
// ↓
하드웨어: "아 전송이구나!"
// ↓
SCK 8번 생성
// ↓
MISO에서 진짜 데이터 수신
```

이걸 우리가 말로 줄여서
👉 **“더미 데이터로 클럭을 만든다”**
라고 부르는 거야.

---

## 4️⃣ 그럼 MOSI는 왜 상관없냐?

읽기 동작에서:

* Slave는 보통

  * “클럭만 들어오면 MISO로 데이터 내보내라”
* MOSI 값은 무시하거나
* 단순히 내부 시프트만 맞추는 용도

그래서:

* MOSI에 0x00이 나가든
* 0xFF가 나가든
* 떠 있지 않고 안정적이기만 하면 됨

---

## 5️⃣ 만약 SCK만 따로 제어할 수 있으면?

이론적으로는 가능해.

* GPIO로 SCK 토글
* MOSI 고정
* MISO 샘플링

👉 이걸 **비트뱅잉 SPI**라고 함

하지만:

* CPU 점유율 ↑
* 타이밍 불안정
* 고속 불가

그래서 하드웨어 SPI는

> **“전송 = 클럭 생성”**으로 묶어버린 것

---

## 한 줄로 정확히 정리

> **SPI에서 더미 데이터가 필요한 이유는
> MOSI/MISO가 SCK와 같은 스트림이라서가 아니라,
> MCU SPI 하드웨어가 ‘전송 없이는 클럭을 안 만들어주기 때문’이다.**

이 개념 잡았으면
이제 SPI DMA, full-duplex, RX only 같은 레지스터 옵션도 다 이해됨 👍
여기까지 왔는데, 다음은 뭐 더 파볼까?
