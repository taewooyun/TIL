## 1. **ADC (Analog to Digital Converter)**

- 아날로그 → 디지털 변환 장치
- 전압을 숫자로 변환
- MCU 내부 하드웨어 모듈

아날로그 센서에서 나오는 연속적인 전압(0~3.3V)을

MCU가 처리 가능한 숫자 데이터(0~4095 등)로 변환해준다.

---

## 2. ADC 기본 개념

| 항목 | 내용 |
| --- | --- |
| 해상도 | 보통 12bit |
| 출력 범위 | 0 ~ 4095 |
| 기준전압 | Vref (대부분 3.3V) |
| 변환 방식 | 샘플링 → 양자화 → 디지털 변환 |

변환 공식:

ADC값 = (입력전압 / 기준전압) × (2^해상도 - 1)

예 (12bit, 3.3V):

- 1.65V → 약 2048
- 3.3V → 4095

---

## 3. ADC 핀 구조

STM32 핀은 기능에 따라 모드 변경 가능

| 설정 | 기능 |
| --- | --- |
| GPIO_Input | 디지털 입력 |
| ADC_INx | 아날로그 입력 |

예:

- PA0 → ADC1_IN0
- PA1 → ADC1_IN1

GPIO 모드면 ADC 동작 안 됨

---

## 4. ADC 동작 개념

전압 입력 → 샘플링 → ADC 변환 → 숫자 출력

즉:

센서 전압 → ADC → 숫자 데이터

---

## 5. CubeIDE 설정 순서

### 1) ADC 활성화

- ADC1 Enable
- Mode: Independent
- Scan Mode: Disable (단일 채널일 때)

### 2) Channel 설정

사용할 핀 → ADC Channel 연결

예: PA0 → Channel 0

### 3) Sampling Time

처음 권장값:

239.5 Cycles

→ 노이즈 감소 효과 큼

### 4) GPIO 설정

ADC 핀 → Analog Mode

---

## 6. 코드 흐름 (HAL 기준)

기본 변환 순서:

Start → Wait → Read → Stop

기본 개념:

1. HAL_ADC_Start()
2. HAL_ADC_PollForConversion()
3. HAL_ADC_GetValue()
4. HAL_ADC_Stop()

---

## 7. 전압 변환 (필수)

ADC값 → 실제 전압 계산

공식:

voltage = (ADC값 / 4095) × 3.3

예:

- ADC = 2048 → 1.65V

센서 분석할 때 반드시 필요

---

## 8. 평균 필터 (노이즈 제거)

실무에서 거의 필수

동작 방식:

N번 측정 → 합산 → 평균

예:

10회 측정 → 평균 → 사용

효과:

- 값 튐 감소
- 안정성 증가

---

## 9. 연속 변환 / DMA 모드 (고급)

구조:

ADC → DMA → Buffer → 처리

특징:

- CPU 개입 최소화
- 실시간 센싱 가능
- 그래프 / MQTT 전송에 적합

실시간 모니터링 시스템에서 주로 사용

---

## 10. ADC + 센서 연결 예

예: MQ-135 / 가변저항

- AO → PA0 (ADC)
- VCC → 3.3V
- GND → GND

⚠️ 5V 출력 센서는 분압 필요

---

## 11. HAL_ADC 주요 함수

자주 쓰는 함수:

- HAL_ADC_Start()
- HAL_ADC_Stop()
- HAL_ADC_PollForConversion()
- HAL_ADC_GetValue()

---

### HAL_ADC 반환값

| 값 | 의미 |
| --- | --- |
| HAL_OK | 정상 |
| HAL_TIMEOUT | 시간 초과 |
| HAL_BUSY | 사용 중 |
| HAL_ERROR | 오류 |

---

## 12. ADC 사용 패턴

### 단일 측정

Start → Read → Stop

### 평균 처리

N회 측정 → 평균 → 사용

### 실시간 처리

ADC + DMA + Timer

---

## 13. 자주 발생하는 문제

### 항상 0 나올 때

- 핀 설정 오류
- 배선 문제
- ADC 미활성화

### 항상 4095 나올 때

- 과전압 입력
- 쇼트

### 값이 튈 때

- 샘플링 시간 짧음
- 필터 없음

---

## 14. 실전 활용 패턴

센서

↓

ADC

↓

평균 필터

↓

UART

↓

MQTT

↓

GUI