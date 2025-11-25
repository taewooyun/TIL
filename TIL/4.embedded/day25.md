# 3일차
## ARM 아키텍처의 이해
### version과 family name
- v1, v2, v3

- v4
    - ARM7 - low end
- v5
    - ARM9 - middle end
- v6
    - ARM11 - highend

- v7
    - cortex A - highend : mobile phone
    - cortex R : A와 유사

    - cortex M - low end : widespreaded embedded system
        - M3
        - M4 - F401RE
        - M7

- v8
    - aarch32, aarch64

## cortex M


auth
    privileged
    non-privileged
mode
    thread mode =  {NP, P}
        - 초기실행시 P모드로 수행
        - 운영체제로 시작되면 NP로 수행
    handler mode = {    P}
stack
    main stack : P mode(thread, handler)
    process stack : NP thread mode


Excution state
- ARM (32bits) : 4Byte instruction
- Thumb(16bits) : 2Byte instruction
- Debug(stop fetching instruction)

T bit always 1

### PSR
Program Status Register
- N
    - 음수, 보다 작은(<)
- Z
    - 0
- C
    - Carry bit
    - C == 0 (== borrow)
        - 빼기 연산에서 작은 수에서 큰 수를 뺄 때 borrow가 발생하지 않았다 == Carry bit 1
- V
    - Overflow

### Instruction
ADD
ADDs report to flag @ ALU -> flag(NZCV...)

#### 데이터 이동
- MOV
#### 논리 연산
- TST
- TEQ
- AND
- EOR
- ORR
- BIC
#### 비교
- CMP
- CMN
#### 더하기
- ADD
- ADC
- QADD
- QDADD
#### 빼기
- SUB
- SBC
- RSB
- RSC
- QSUB
- QDSUB
#### 곱하기
- MUL

#### Count roading zero

#### 브랜치
- B

#### Supervisor Call
- SVC

#### NOP
- NOP

#### 로드
- **LDR**
    LDR r0, [r1, #option];
    r0로 가져오는것
- LDM

#### 저장
- **STR**
    LDR r0, [r1, #option];
    r0를 내보내는것

#### 조건필드 - M series 사용 X?
flag를 보고 판단
파이프라인이 깨지는것을 방지
- EQ
- NE
- CS / HS
- CC / LO

모든 ARM 어셈블리 명령어는 조건부 실행이 가능하다

## GPIO 회로

*채워야함

push pull 회로
pull up pull down

input 회로

### Schmitt Trigger
기존 값을 인정 해줌
IH에서 IL 로 도달한 시점부터 0으로 인식
IL에서 IH 로 도달한 시점부터 1으로 인식


## GPIO 레지스터와 설정

### GPIOx MODER
- GPIO 모드 설정
mode register
MODER[1:0]
00 input
01 general purpose output mode
10 alternate function
11 analog mode

### GPIOx OTYPER
### GPIOx PUPDR
00 nopullup pulldown
01 pull up
10 pull down
11 reserved

### GPIOx IDR
### GPIOx ODR
### GPIOx BSRR
- IDR, ODR 값을 세팅 해줌


---
실습
LED 장착해보기

Clock을 먼저 공급


레지스터 레벨 코드
```c
	RCC->AHB1ENR |= (1<<0); // GPIOA(0) clock enable
	GPIOA->MODER &= ~(3<<(2*9)); // PA9 clear
	GPIOA->MODER |= (1<<(2*9)); // mode for PA9 : output
	
	RCC->AHB1ENR |= (1<<2); // GPIOC clock enable
	GPIOC->MODER &= ~(3<<(2*7)); // PC7 clear : mode input
	GPIOC->PUPDR &= ~(3<<(2*13)); // PC13 clear : mode no pullup no pulldown

    if(GPIOC->IDR & (1<<7)){
        GPIOA->BSRR = (1<<9);
    } else{
        GPIOA->BSRR = (1<<(9+16));
    }
    
    if(GPIOC->IDR & (1<<13)){
        GPIOA->BSRR = (1<<(9+16));
    } else{
        GPIOA->BSRR = (1<<9);
    }
    
```
- clock enable을 안해도 되는건가
- 같이 구성하면 안되는건가


```
if((GPIOC->IDR & (1<<7)) || (GPIOC->IDR & (1<<13))){
			GPIOA->BSRR = (1<<(9+16));
		} else{
			GPIOA->BSRR = (1<<9);
		}
```
- 오류 : 작동 안함



---

### memo
- instruction을 각 구성요소(load store / fetch unit / decoder)중 누가 수행하는지
- 비트 마스크 clr filter
- 부로직을 쓰는 이유
- 