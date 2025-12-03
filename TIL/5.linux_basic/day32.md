# 6일차
# + 추가
# 리눅스 개발환경 도구

## Compiler

gcc(gnu c compiler -> gnu compiler collection)
.c --> c compiler
.s --> assembler
확장자에따라 알아서해줌

cpp : c preprocessor
cc1 : c compiler
g++ : c++ compiler
gas : gnu assembler
anm : name
gdb : debugger
ld  : linker (collect)

전체를 다 합해서 툴체인이라한다?

### Native & Cross
#### native compiler
- host   : x86_64 build
- target : x86_64 run

ie, gcc hello.c

ie, $file hello
   -> ELF: x86_64
#### cross compiler
- host   : x86_64 build
- target : aarch64 run @rasberrypi

ie, ${CROSS_COMPILE}-gcc hello.c
   =="arm-linux-gnu"
ie, $file hello
   -> ELF: aarch64

## Build
build process
`$ file hello.c`
`$ objdump -h hello`

1. preprocess : 전처리
    - .c (C source) -> .i
    - 전처리 지시자, 헤더 파일 치환
    `$ gcc -E hello.c > hello.i`
2. compile : 
    - .i (C source) -> .s (ASM source)
    `$ gcc -S hello.i > hello.s`
3. assemble
    - .s -> .o (object file)
    `$ gcc -c hello.s > hello.o`
    `$ objdump -h hello.o`
    `$ size hello.o`
4. locate
    - .o (relocatable) -> located
    location = address
    - 데이터 섹션이 메모리 맵의 어떤 주소로 올라갈지 미리 논리적 배치. 메모리 주소의 설계도

    - `by ld hello.o` -> .ld
    - 명령어가 있나

    - PC에서는 표준화 된 주소로 지정해준다
    - 임베디드 시스템, on board 에서는 rom인지 ram인지 다 지정해줘야한다
    
5. link
    hello.o
    startup.o
    math.a(sin.o, cos.o, tan.o)
    `gcc -o hello hello.o startup.o math.a` - ?
    
    object file들을 연결해 실행파일로 만든다

6. elf2bin // elf2hex
    .bin
    .hex (ROMable file) by rom writer (JTAG debugger), ISP...
    `$ objcopy`
    -> .text .rodata -> rom
    -> .data .bss -> rom -> vma: ram



## Debugging
### gdb

#### core dump
- 정의 
- segmentation fault: SIGSEGV
- `$ ulimit`

#### 디버그 타겟 파일 만들기
- dwarf-2
`$ nm`
`$ gcc -g`
ojbdump 

#### gcc 사용법

심볼정보 == identifier ??

`(gdb) help`

`(gdb) help status`

`(gdb) help list`

`(gdb) list`

`(gdb) frame` (==`(gdb) f`)

`(gdb) run` (==`(gdb) r`)

`(gdb) backtrace` (==`(gdb) bt`)

`(gdb) file`

`(gdb) breakpoints` (==`(gdb) b`)

`(gdb) step` (==`(gdb) s`)

`(gdb) next` (==`(gdb) n`)

`(gdb) set`

`(gdb) display`

`(gdb) disable`

`(gdb) delete`

`(gdb) display`



## library

{body + libs} == 정적
{body} + {libs} == 공유/동적
{body} 실행 --> {libs} 찾아 -> 공유 실행 시
{body} 실행 --> 찾을 시점을 결정함


### static lib
- 정적 라이브러리
`$ ar r libmylib.a mylib.o`
- .a 아카이브 파일과 오브젝트 파일의 차이
`$ cc main.o -Llib -lmylib` : lib경로의 libmylib.a 파일을 등록


### shared lib
- 공유 라이브러리 
- Position Independent Code

로더? ld면 링크해주는애아닌가

  + 공유 오브젝트

`$ export LD_LIBRARY_PATH` : 환경 변수 설정


### dynamic lib
- 동적 라이브러리
- 공유 라이브러리를 사용, 실행 시간에 동적으로 로드/언로드






## make
- Makefile

## cmake
- CmakeLists.txt

## git
- github

## docker
- 

---

## memo
- 각 데이터의 섹션이 메모리에 적재되는 과정. bss가 공간할당없이 주소만 올라가던가 했던거
