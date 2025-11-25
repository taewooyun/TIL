# 2일차

## 임베디드 시스템 이해

### 컴파일러의 각 단계별 작업 옵션

# ✅ gcc 컴파일 4단계 & 확인 명령어 정리

gcc는 내부적으로 아래 순서로 동작해:

1. **전처리(Preprocessing)** → `.i`

2. **컴파일(Compilation)** → `.s`

3. **어셈블(Assembly)** → `.o`

4. **링크(Linking)** → 실행파일

각 단계 결과를 확인하려면 아래처럼 옵션을 주면 돼.

---

# 1) 🔹 전처리 단계 결과 확인 (`-E`)

### ✔ 명령어

`gcc -E main.c -o main.i`

### ✔ 결과

- 전처리된 파일 `main.i` 생성

- `#include`가 실제 코드로 펼쳐지고, `#define` 매크로가 치환된 상태

### ✔ 확인

`less main.i`

---

# 2) 🔹 컴파일 단계 결과 확인 (`-S`)

### ✔ 명령어

`gcc -S main.c -o main.s`

### ✔ 결과

- C 코드가 **어셈블리 코드(.s)** 로 변환됨

- 아직 기계어는 아님

### ✔ 확인

`less main.s`

---

# 3) 🔹 어셈블 단계 결과 확인 (`-c`)

### ✔ 명령어

`gcc -c main.c -o main.o`

### ✔ 결과

- **목적파일(.o)** 생성

- 기계어(binary)이므로 일반 문서처럼 열어보면 깨진 문자처럼 보임

### ✔ 내용 구조 확인

`objdump -d main.o`

또는

`readelf -h main.o readelf -s main.o`

---

# 4) 🔹 링크 단계 결과 확인 (링크만 수행)

### ✔ 명령어

`gcc main.o -o main`

### ✔ 결과

- 실행파일 `main` 생성됨

### ✔ 바이너리 구조 확인

`readelf -h main readelf -S main`

### ✔ 디스어셈블

`objdump -d main`

---

# ⭐ gcc 전체 빌드 플로우를 명령어로 직접 따라보기

## 1) 전처리

`gcc -E main.c -o main.i`

## 2) 컴파일

`gcc -S main.i -o main.s`

## 3) 어셈블

`gcc -c main.s -o main.o`

## 4) 링크

`gcc main.o -o main`

---

# 📌 핵심 요약 테이블

| 단계  | gcc 옵션 | 결과물  | 확인 명령어                        |
| --- | ------ | ---- | ----------------------------- |
| 전처리 | `-E`   | `.i` | `less main.i`                 |
| 컴파일 | `-S`   | `.s` | `less main.s`                 |
| 어셈블 | `-c`   | `.o` | `objdump -d main.o`           |
| 링크  | (없음)   | 실행파일 | `objdump -d main` 또는 `./main` |

a.out
---

### nucleo 구조

SoC : ST32F401 RE - SoC(Chip)
        ARM coretex M4 - processor
                core M

iROM : 0x0800:0000 0x8:0000(512KB)
iRAM : 0x2000:0000 0x1:8000(64KB + 32KB)

devx

### ELF 메모리 섹션 구조

a.out(ELF) - sectionS
    .TEXT
        - 정의 : 실행 코드 저장 영역
        - 특징 : 읽기 전용, 실행 가능
        - 예시 : 함수, 로직 등
    .CONST(.rodata)
        - 정의 : 초기값이 있고 읽기 전용인 데이터를 저장하는 영역
        - 특징 : 읽기 전용
        - 예시 : 문자열 리터럴, const 전역/정적 변수
    .DATA
        - 정의 : 초기값이 있는 전역/정적 변수 저장
        - 예시 : `int x = 10;`
    .BSS
        - 정의 : 초기값이 없는 전역/정적 변수 저장
        - 실제 파일 크기에는 포함되지 않고, 실행 시 0으로 채워짐
        - 예시 : `int counter;`

- ROM에 적재된 프로그램을 Program Counter(Instruction Pointer)가 Cpu에게 전달한다?
- LMA(Load Memory Address)와 VMA(Virtual Memory Address)
- startup.o(Startup Code)의 역할
    - .data의 변수와 값을 ROM에서 RAM으로 카피한다
    - .bss의 변수 정보만 ROM에서 RAM으로 카피한 후 초기화 한다
- RAM에 적재된 프로그램을 Stack pointer가 가리킨다
- 변수의 속성
    - 라이프 타임
        - 
    - 스코프
        - 링키지?


### 로케이터
- 

### 마이크로 프로세서의 버스 요소
- address bus - 어드레스 다발
- data bus -
- controll bus - 
- 예시
    - RS232 / RS485
    - PCI Express SATA i^2C SPI I2S CAN 
### 버스 핸드쉐이킹
- Master와 Slave간에 통신 채널을 유지하기 위해 주고 받는 프로토콜
- HW vs SW handshaking
- Bus master가 주도
- 버스 사이클을 완성하기 위한 handshaking을 bus handshaking이라 함
- Wait 신호를 이용한 버스 핸드쉐이킹

## 시스템 메모리
- Volatile
    - DRAM
    - SRAM
- Non Volatile
    - ROM, Flash, HDD, CD, DVD
    - Ng : FeRAM, CBRAM, PRAM, SONOS, RRAM,Racetrack memory

### ROM
- Read Only Memory
- MASK ROM
- PROM : Programmable ROM
    - 한번만 쓸 수 있다(OTP)
- EPROM : (UV) Erasable Programmable ROM
    - 
- EEPROM : Electrically Erasable Programmable ROM
    - 
- Flash memory
    - NOR type
        - INTEL series
        - AMD series
            - Spansion
            - Atmel / Sharp / ...
        - INTERFACE : A-D-C
    - NAND type
        - Samsung / SK-Hynix / Toshiba / Micron /
        - IINTERFACE : ALE, CLE DATA8 pins


### 마이크로 프로세서 버스 구조
- addr bus
- data bus

### 메모리 맵
버스 통신 예시
RAM 3번지의 값에 접근할때
0b 00 0011 

1000011 = 67

A0
A1
A2
A3
..
CS : ChipSelect

CS를 둬서 0~63 까지는 ROM, 64~127 까지 RAM에 접근할 수 있도록 함
- Address Decoder
    - 2-4 MUX
    - 이 비트의 명칭이 있는가
    - 주소 버스를 통해 CPU에서 들어온 CS(=CE)값을 분배해주는 역할 

### 메모리 계층 구조
- 지역성 
    - 시간적 지역성(temporal)
        - 접근한 쪽을 다시 접근할 확률이 높다
    - 공간적 지역성(spacial)
        - 접근한 쪽의 주변에 접근할 확률이 높다
- register
- cache
    - 메모리의 지역성으로 자주 쓰는 데이터를 저장
    - 여러개의 요청도 한번에 가져옴 - line fill

#### instruction 실행
IFe
ID

- 

#### SRAM vs DRAM
- SRAM
    - 6개의 Tr로 구성됨
    - Word Line과 Bit Line으로 구성됨
    - WordLine에 의해 Bit line이 선택됨
    - 속도가 DRAM에 비해 빠름
- DRAM
    - 1개의 Tr과 1개의 Cap으로 구성됨
    - Word Line과 Bit Line으로 구성됨
    - 속도가 SRAM에 비해 느림
    - 읽고 나면 다시 값을 복구 시켜줘야 함
    - 가만 있을 때도 값이 사라짐. Refresh 해야 함


- ram
- rom

## 프로세서의 구성 요소
- LoadStore : 변수를 읽고 저장
- FetchUnit : instruction을 가져옴
    - program counter
        - instruction을 가져올 주소
- DecoderUnit
- IC
- 

### ARM Core Companions
- Core

### Cache
- Direct Maped Cache
    - tag, v 사용 매핑
- 2-way set associative cache
    - 매핑된 2개의 세트를 사용해서 같은 주소의 값이라도 한 층을 더 확보
- n-way set assciative cache

- dirty bit와 clean

### MMU와 MPU
- MPU : Memory Protection Unit
    - CPU와 메모리 사이에서 CPU가 주소에 접근하기 전에 해당 프로세스에서 허용된 주소인지 판단
    - Partition
    - Region
    - FreeRTos
- MMU : MPU(+Virtual Address) Management Unit
    - MPU 기능 포함(유효한 주소인지 판단)
    - 프로세스마다 부여된 Translation Table을 사용. 실행중인 프로세스를 기준으로해서 가상주소(VA)를 물리주소(PA)로 변경해서 접근
    - Translation Table(Page Table)
    - Linux



## register and instruction
### register
1. system register
    GPR(General purpose reg)
        r0-r12 : scratch pad register (by ALU)
    SPR(Special purpose reg)
        r13 : stack pointer register - point at top of stack(full decrement)
            - stack pointer가 가리키는 값은 항상 차있음
            - 스택이 쌓일 때 마다 주소는 감소
        r14 : link(return address) register
            - 함수가 실행될 때 돌아올 주소가 저장된다
        r15 : program counter register
    
    core register = {r0, r1, ..... r12, r13, r14, r15}
    
2. device register
    주소 있음 - 메모리맵
    SFR(Special fucntion reg) 
        1. configuration
            UART, GPI
        2. control
            turn on/off
        3. data
            read/write from and to
        4. status


### instruction
디버깅할 때 컴파일러가 ASM 확인



---

### memo
- 스캐터 로딩
- cpu가 instruction을 가져온다
- 프로그램 카운트와 패치 유닛
- 64bit 운영체제의 주소체계 6비트?
- FPGA
- inconsistans 상태?
- 왜 RTos는 MPU를 사용해야하는가. 프로세서에 할당된 주소가 연속적으로 있어서?

● 저장 클래스(storage class)
auto
static
register
extern

● 타입 수식어(type qualifier)
const
volatile
restrict


- 데이터섹션이 램으로 올라가는 과정
- text는 안올라간다?
- text, data, rodata, bss

- startupcode의 역할
- 주소연산자가 참조하는
    - 값 =? ROM의 주소
    - 값 =? RAM의 주소
- 함수의 주소는?

- instruction

- Stack pointer가 가리키는 값
- peripheral
- ARM(32bit) = ALU word의 사이즈







- memory storage
Storage class

in C :

int i; 
auto int i; // @ stack
static int i; // @ .BSS
static int i = 0; // @ .DATA
register int i; // @ register

pipeline
- 분업으로 퍼포먼스를 올릴 수 있음
- 스루 풀? 을 높일 수 있다

IF - ID - IE(overwraped pipeline)

IF ID IE MA(LS) WR(by)