## 1. **I2C (Inter-Integrated Circuit)**

- **동기식 직렬 통신**
- **Master–Slave 구조**
- **2선 통신 방식**
- **주소 기반 통신**

👉 여러 디바이스를 **2개 선으로 동시에 연결**하는 방식

---

UART처럼 1:1 ❌

SPI처럼 선 많이 필요 ❌

→ **센서/EEPROM/RTC용 표준 통신**

---

## 2. I2C 신호선

| 신호 | 의미 | 설명 |
| --- | --- | --- |
| **SCL** | Serial Clock | 클럭 (Master 생성) |
| **SDA** | Serial Data | 데이터 송수신 |

📌 **반드시 Pull-up 저항 필요**

보통:

- 4.7kΩ ~ 10kΩ → 3.3V 연결

(모듈에 이미 달려있는 경우 많음)

---

### 🔹 특징

### SCL

- 클럭선
- 통신 타이밍 기준

### SDA

- 데이터선
- 양방향 (TX/RX 겸용)

---

## 3. 동작 개념 (한 줄 요약)

```
START
주소 전송
ACK
데이터 송수신
STOP

```

---

### 실제 흐름

```
SDA ↓ (SCL High) → START
주소 + R/W 전송
ACK 응답
데이터 교환
SDA ↑ (SCL High) → STOP

```

👉 **START / STOP 조건이 핵심**

---

## 4. I2C 주소 구조 (중요 ⭐)

### ✔ 7bit 주소 (대부분 사용)

```
[ A6 A5 A4 A3 A2 A1 A0 ] [ R/W ]

```

- R/W: 0=Write, 1=Read
- HAL에서는 **R/W 제외한 주소만 사용**

예:

```
디바이스 주소: 0x68
→ HAL에는 0x68 << 1 사용

```

📌 이거 헷갈리면 통신 100% 실패함

---

## 5. CubeIDE 설정 순서 (중요 ⭐)

### 1️⃣ I2C 활성화

- I2C1 / I2C2 선택
- Mode: I2C

---

### 2️⃣ Parameter 설정

| 항목 | 설정 |
| --- | --- |
| Speed Mode | Standard (100kHz) |
| Duty | Default |
| Addressing | 7bit |

👉 처음엔 무조건 100kHz 추천

---

### 3️⃣ GPIO 설정

| 핀 | 설정 |
| --- | --- |
| SDA | AF + OpenDrain |
| SCL | AF + OpenDrain |

📌 Push-Pull ❌ → 반드시 Open-Drain

---

## 6. 코드 흐름 (HAL 기준)

---

## ✅ 기본 Write (레지스터 쓰기)

```c
uint8_t data[2];

data[0] = 0x10;   // 레지스터 주소
data[1] = 0x55;   // 값

HAL_I2C_Master_Transmit(
    &hi2c1,
    0x68 << 1,
    data,
    2,
    HAL_MAX_DELAY
);

```

---

## ✅ 기본 Read (레지스터 읽기)

```c
uint8_t reg = 0x10;
uint8_t value = 0;

/* 주소 지정 */
HAL_I2C_Master_Transmit(
    &hi2c1,
    0x68 << 1,
    &reg,
    1,
    HAL_MAX_DELAY
);

/* 데이터 수신 */
HAL_I2C_Master_Receive(
    &hi2c1,
    0x68 << 1,
    &value,
    1,
    HAL_MAX_DELAY
);

```

👉 이게 가장 기본 패턴

---

## ✅ HAL 편의 함수 (실무에서 더 많이 씀)

### 메모리 Read

```c
HAL_I2C_Mem_Read(
    &hi2c1,
    0x68 << 1,
    0x10,
    I2C_MEMADD_SIZE_8BIT,
    &value,
    1,
    HAL_MAX_DELAY
);

```

### 메모리 Write

```c
HAL_I2C_Mem_Write(
    &hi2c1,
    0x68 << 1,
    0x10,
    I2C_MEMADD_SIZE_8BIT,
    &value,
    1,
    HAL_MAX_DELAY
);

```

👉 센서/EEPROM용 표준 방식 ⭐⭐⭐⭐⭐

---

## 7. 주요 HAL 함수

### HAL_I2C_Mem_Read

```c
HAL_StatusTypeDef HAL_I2C_Mem_Read(
  I2C_HandleTypeDef *hi2c,
  uint16_t DevAddress,
  uint16_t MemAddress,
  uint16_t MemAddSize,
  uint8_t *pData,
  uint16_t Size,
  uint32_t Timeout
);

```

| 인자 | 의미 |
| --- | --- |
| DevAddress | 슬레이브 주소 |
| MemAddress | 레지스터 주소 |
| Size | 데이터 길이 |

---

### 반환값

| 값 | 의미 |
| --- | --- |
| HAL_OK | 성공 |
| HAL_BUSY | 사용중 |
| HAL_ERROR | 오류 |
| HAL_TIMEOUT | 응답없음 |

---

## 8. I2C 사용 패턴

---

### ▶ 센서 읽기 패턴

```
START
주소+W
레지스터
RESTART
주소+R
데이터
STOP

```

---

### ▶ EEPROM 쓰기

```
주소 → 메모리주소 → 데이터 → 대기

```

쓰기 후 Delay 필요 ⚠️

---

### ▶ 다중 슬레이브

```
MCU
 ├─ 온도센서 (0x48)
 ├─ RTC     (0x68)
 └─ EEPROM  (0x50)

```

같은 SDA/SCL 공유 가능

---

## 9. SPI vs I2C 비교

| 항목 | SPI | I2C |
| --- | --- | --- |
| 배선 | 많음 | 적음 |
| 속도 | 빠름 | 느림 |
| 주소 | 없음 | 있음 |
| 다중슬레이브 | 어려움 | 쉬움 |
| 용도 | 고속 | 센서용 |

---

## 10. 자주 터지는 문제 (현업 기준)

### ❌ 통신 안 됨 (80%)

- Pull-up 없음
- 주소 shift 안 함
- 핀 Push-Pull 설정

---

### ❌ ACK 안 옴

- 주소 틀림
- 전원 안 들어감
- 다른 장치 충돌

---

### ❌ 계속 BUSY

```c
__HAL_I2C_CLEAR_FLAG(&hi2c1, I2C_FLAG_BUSY);
```

또는 재초기화

---

### ❌ 값이 이상함

- 레지스터 주소 틀림
- MSB/LSB 순서 오류

---

## 11. 요약

> I2C는 SDA/SCL 두 선으로
> 
> 
> 여러 디바이스를 주소 기반으로 제어하는
> 
> 센서/메모리 표준 통신 방식이며,
> 
> HAL_I2C_Mem_Read/Write가 실무 표준이다.
>