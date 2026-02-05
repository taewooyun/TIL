### 테스트 데이터

- **/root**

![image.png](attachment:4d7d272a-088c-4c35-8b9b-e8032289dbe5:image.png)

- **/sample**

![image.png](attachment:2c0269e7-9e8b-455f-9648-630209212df3:image.png)

## CubeMX 설정

### 1. SPI 설정

- 기반 Connectivity: SPI 통신 기반으로 SD카드에 데이터를 씀
- 프로젝트 사용 패리패럴: SPI2
- Mode : Full-Duplex Master 모드 선택 (전이중 통신 Master)

![image.png](attachment:2cbc97b5-660c-4406-9561-b5cad6661132:image.png)

---

### 2. fatfs 설정

- `Pin out & Configuration`  - `Middleware`
    - Mode `User-defined` 체크
- `Locale and Namespace Parameters` - `USE-LFN`
    - `Enabled with static working buffer on the BSS` 선택
- `Phsical Drive Parameters` - `MAX_SS` : 4096
    - 한 번에 최대 4KB의 데이터 읽기/쓰기 가능

---

### 3. 멀티 파일 설정

- `Project Manager`  - `Code Generator`
    - **Generate peripheral initialization as a pair of ‘.c/.h’ files per peripheral** 체크

**결과**

![image.png](attachment:0b140437-8d82-4d12-beae-cad091942655:image.png)

- 각 장치들이 Src 폴더 내 파일로 위치하여 헤더파일로 접근할 수 있다

---

### 4. Generate Code

![image.png](attachment:2630ecf7-f2fb-4922-b9da-9ab65a3df7c5:image.png)

- `FATFS` 및 `Middlewares` 생성

---

## SPI 기본 테스트

---

## SD card Command

### 기본 흐름

```c
전원 ON
  ↓
CMD0     → 리셋 (IDLE 진입)
  ↓
CMD8     → 버전 확인
  ↓
ACMD41   → 내부 초기화
  ↓
CMD58    → 상태 확인
  ↓
사용 가능
```

### CMD0을 입력해도 정상 값인 01이 안찍힘

---

## 트러블 슈팅

### 문제 : SD카드에 CMD0을 입력해도 정상 리셋 값인 01이 안찍힘

![image.png](attachment:1a5a19ef-37cd-4a60-bee9-5b89e89d045e:image.png)

**시도 했던 조치 방법**

- 5V 모듈에 VCC 3.3 공급  → 5V로 공급
- MISO 핀에 5V 입력으로 Overvoltage 우려, 10kΩ 2개로 분압 회로 구성

### 해결

![image.png](attachment:1b2ac70a-4c9d-4b6f-b32a-cefc7ce00573:image.png)

- 문제 파악
    - 5V 입력
    - 초기화 더미 클럭 수
    - 

---

### 문제 : main() 여러번 호출

```c
Start
SD Init Start
CMD0 : 00
CMD0 : 00
CMD0 : 00
CMD0 : 00
CMD0 : 00
CMD0 : 00
Start
SD Init Start
CMD0 : 00
CMD0 : 00
CMD0 : 00
CMD0 : 00
CMD0 : 00
CMD0 : 00
```