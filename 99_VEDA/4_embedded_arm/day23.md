# 1일차

---

## 임베디드 개요

- Qt - for GUI MMI HMI

- 임베디드 하드웨어의 발전
  
  - embedded -> micro controller -> MCU(~32bit) -> SoC(64bit~)

- architecture
  
  - core(@MCU) -> 종류
    
    1. x86   i386
    
    2. x86   i586    @ PC --> @embedded
    
    3. MIPS : PC -> Net -> Phone -> ...
    
    4. PPC              @ PC --> @embedded(network / areospace & defense, industry, medical, game)
    
    5. ARM @ mobile
    
    6. TriCore : auto -> ARM
    
    7. ...

- 임베디드 시스템 구성 요소
  
  - SoC(MCU) - (ARM)
    
    - ARM : 32bits(stm32F401re @Nucleo), 64bits(BCM7112 @rpi 4b+)
  
  - ROM
  
  - RAM
  
  - device(peripherals)

## 임베디드 시스템의 이해

### Embedded System 정의

- DEFINITION
  
  - 컴퓨터 시스템
  
  - dedicated function
  
  - within a lager mechanical or eletrical system

- EMBEDDED
  
  - 더 큰 시스템의 일부로 내장

- PC 이외의 CPU가 달린 모든 전자장치

### 임베디드 시스템의 특징

- 특정 기능을 수행

- 하드웨어 + 소프트웨어로 구성

- 하드웨어 변경 쉽지 않음

- 제한적인 자원

- 고 신뢰성, 실시간성의 요구

### 임베디드 시스템 개발 프로세스

- 시스템 요구분석
  
  - 시스템 요구사항 검사

- 시스템 설계
  
  - 시스템 설계 검사

- 개발
  
  - 하드웨어 파트 개발
  
  - 소프트웨어 파트 개발
    
    - 인터페이스 항목 개발
    
    - 응용 소프트웨어 항목 개발
  
  - 기능적 물리적 검사

- 시스템 통합 및 테스팅
  
  - 품질 검사

- 평가 및 인수

- 유지보수 및 기능 추가

- 임베디드 시스템 생산 및 판매

SoC <----------------- Program memory

                                data Memory

                                --------------------------

Peripherals            I/O Interface

입력 장치 -> 프로세서(<-> 메모리) -> 출력 장치

Itel MCS-4 Chipset

4001: ROM

4002: RAM

4003: I/O Interface

4004: CPU### CPU Operating mode

- USR for App
- SVC - Kernel for OS
- HYP

### SMP vs AMP

- Symmetric Multi-Processing
  
  - SMP은 두 개 이상의 동일한 프로세서가 하나의 메모리, I/O 디바이스, 인터럽트 등의 자원을 공유하여 단일 시스템 버스를 통해, 각각의 프로세서는 다른 프로그램를 실행하고 다른 데이터를 처리하는 시스템을 의미합니다. 달리 얘기하면, 두 개 이상의 프로세서가 하나의 컴퓨터 시스템 아키텍쳐를 공유하도록 연결되어 있으며, 각각의 프로세서는 독립적으로 자신의 작업을 처리한다는 의미가 됩니다. 아래의 그림에서 SMP 시스템을 봅시다.

- Asymmetric Multi-Processing
  
  - AMP는 두 개 이상의 각각의 프로세서가 자신만의 다른 특정 기능을 수행하는 아키텍쳐를 의미합니다. 예를 들어, 하나의 프로세서가 메인 운영체제를 실행하도록 하고 다른 프로세서는 I/O 오퍼레이션 기능을 전용으로 수행하는 형태의 아키텍쳐로 존재할 수 있습니다. 이때, 두 개의 프로세서는 메인 메모리에서 자신의 커널 이미지를 실행하고 주소 공간 역시 분리되어 있는 컨셉이라고 볼 수 있지요. 여기서 커널 이미지는 동일하거나 서로 다른 것으로 사용될 수 있습니다.

### FPU & SIMD

- FPU(Floating Point Unit)
  
  - 실수 연산

- SIMD(Single Instruction Mutilple Data)
  
  - 병렬 처리 기법
  
  - 예시 : vector
    
    - Z : complex number 복소수 연산
      
      - 허수연산
  
  - LANE 끼리 연산

- 구조
  
  - ARM - main processor
    
    - CP15
    
    - CP14
    
    - ...
    
    - CP1
      
      - as a coprocessor = VFPU == SIMD : Signal 처리, 멀티미디어 처리

- SIMD programming
  
  - 코드상으로 코프로세서에게 연산을 직접 지시할 수 있다

- GPU computing
  
  - 어플리케이션의 연산집약적인 부분을 GPU로 넘기고 나머지 코드만을 CPU에서 처리하는 GPU 가속 컴퓨팅

### 임베디드 시스템 소프트웨어 구성

- Processor
  
  - App
  
  - Hypervisor - type 1
    
    - OS
      
      - VM - type 2
      
      - App
      
      - OS
        
        - APP

- momory

- I/O

### 개발환경 요소

#### Host

- 하드웨어 / 소프트웨어 개발 용 컴퓨터

#### Target

- 개발 대상이 되는 임베디드 보드

#### Toochain

- Host에 설치하여 사용하는 개발 프로그램들로서

- Target용 실행파일을 생성할 수 있는

- Compiler, Assembler, Linker 및 bin utilities등을 칭함
  
  - Windriver DIAB compiler
  - GNUARM Cross toolchain

#### IDE

- 통합 개발 환경
- ARM-MDK, IAR Embedded Workbench 등

#### Debugger

- ### 실시간 시스템

- RTOS
  
  - deterministic : 결정적
  - 일정 시간마다 수행되는것을 보장함
  - ie, FreeRTos, vxWorks, QNX 등

- NON RTOS
  
  - Windows / Linux

- 실시간 시스템
  
  - 외부 이벤트를 일정한 시간 내에 처리해야 하는 시스템
    
    - 작업 완료 기준 : 일정 시간 내에 작업을 완료
    - 작업 시작 기준

- 경성(Hard) 실시간 시스템
  
  - 시간 제약의 위반이 심각한 결과를 초래
  
  - 시간 제약은 반드시 지켜져야함
    
    - 무기 체계 시스템, 발전 제어 시스템 등

- 연성(Soft) 실시간 시스템
  
  - 시간 제약의 위반이 QoS의 저하를 유반
  
  - 시간 제약은 가급적 지켜져야함
    
    - 오디오, 통신기기 등

## 임베디드 시스템 개발 환경

- PC Application 개발 환경
- Embedded System Application 개발 환경

### 구성 요소

- 호스트 시스템

- 툴체인
  
  - .h
    
    - pre-process : .h -> .c
  
  - .c
    
    - compile : .c -> .s
  
  - .s
  
  - ---------- ASCII - human readable
  
  - ---------- ELF
    
    - assemble : .s -> .o
  
  - .o (ELF)
    
    - locate / link : .i -> .out
    - excutable
  
  - .out(ELF) - linux / .exe - windows
    
    - object copy : .out -> .bin (선택)
  
  - .bin(plat binary)
    
    - ROM write by ROM writer
    - bin2hex : .bin -> .hex (선택)
  
  - .hex
    
    - ROM writer format

- 디버거

- 타겟시스템

### cube MX : configurator

- ncleo 401

- ## Features
  
  - Common features
    - STM32 microcontroller in an LQFP64 or  
      LQFP48 package
    - 1 user LED shared with ARDUINO®
    - 1 user and 1 reset push-buttons
    - 32.768 kHz crystal oscillator
    - Board connectors:
      - ARDUINO® Uno V3  
        expansion connector
      - ST morpho extension pin headers for  
        full access to all STM32 I/Os
    - Flexible power-supply options: ST-LINK  
      USB VBUS or external sources
    - Comprehensive free software libraries and  
      examples available with the STM32Cube MCU Package
    - Support of a wide choice of Integrated  
      Development Environments (IDEs) including IAR Embedded  
      Workbench®, MDK-ARM, and STM32CubeIDE
  - Features specific to some of the boards  
    (refer to the ordering information section of the data brief for  
    details)
    - Second user LED
    - External or internal SMPS to generate Vcore  
      logic supply
    - 24 MHz or 48 MHz HSE
    - User USB Device full speed, or USB  
      SNK/UFP full speed
    - Cryptography
    - CAN FD transceiver
    - Board connectors:
      - External SMPS experimentation  
        dedicated connector
      - USB Type-C®,  
        Micro-B, or Mini-B connector for the ST-LINK
      - USB Type-C® user  
        connector
      - MIPI® debug connector
      - CAN FD header
    - On-board ST-LINK (STLINK/V2-1,  
      STLINK-V3E, STLINK-V2EC, or STLINK-V3EC) debugger/programmer  
      with USB re-enumeration capability: mass storage, Virtual  
      COM port, and debug port

- PC13 : pin C group number 13

- USART_TX & RX : serial transport

#### Pinout & Configuration

- System Core
  
  - DMA
  - GPIO
  - IWDG
  - NVIC
  - RCC
  - SYS
  - WWDG

### Clock Configuration

- 32.768 kHz crystal oscillator(NUCLEO-F401RE 기준)

- 부로직 회로(active low)
  
  - 0일때 참(버튼이 눌림)
  - 전기적으로 유리하기 때문에 사용한다

### mVision : IDE

---

### memo

- 오실로스코프
- 회로도
- 촬영한 화면을 2d이미지로 변환하는것
- 
