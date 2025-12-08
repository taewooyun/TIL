# 7일차


## 리눅스 개발환경 도구
### Make / make
    in embedded system -> **C** /C++
    각각의 c 파일들을 자동으로 빌드하기 위한 시스템
    일종의 인터프리터 언어

#### Rule
```bash
target : prerequisites(=dependency)
    recipes # bash가 실행하는 파일
```
```bash
helloworld :
    @echo hello world
```


all 타겟 : 디폴트 타겟
```bash
all: bar baz
#       @echo foo

bar: 
        @echo bar

baz: 
        @echo baz
```

#### default makefile
1. GNUmakefile
2. makefile
3. Makefile

- -f : 파일 지정

#### make DB
- make가 관리하는 내부 database
- -p : 내부 DB를 print
```bash
$ make -p | grep -w CC
```

#### makefile debug
```bash
$ make -d
```

#### makefile 작성
```bash
VAR = world # 매크로 변수

hello:$(VAR)
    @echo hello \  # '\' 의미
    $(VAR)

:execute

$ make
helloworld
```

`$()` :  스크립트랑 다른거 맞나

```make
$(MAKE) -C subbir --no-print-directory
```

`:=` 는 뭐야

#### 하위 makefile과 연결
- 상속
- 포함

#### 파일 타겟

so trivial

#### 빌드
- 파일 타겟
- hello.c : 소스 코드
- hello.o - 목적 코드
- hello : 실행 코드(타겟)
- 의존 관계의 파악


#### 더미 타겟
- all:


#### 포니 타겟
- phony : 가짜, 위장, 사기 , 장난
- 동일한 이름의 파일이 있으면 더미 타겟으로 쓸 수 없는것을 해결

```bash
.PHONY
```

#### forced target
- 의존 더미 타겟

#### 2차 타겟
- 이차적 고려 대상의 중간 타겟


#### 싱글 첨자
-  싱글 서픽스 타겟

`SUFFIXES: .k`
임의의 확장자를 어떻게 처리할것인지
```bash
.c:
```

#### 더블 첨자
- 더블 서픽스 타겟
```bash
.c.o :          # .c파일로부터 .o파일을 만드는방법을 정의
```

#### Rule
- explict 
    - single suffix  rule   ie,     .c:
    - double suffix  rule   ie,   .c.o:
    - single pattern rule   ie,   %o %c
    - double pattern rule

- implict 
    - single suffix  rule
    - double suffix  rule
    - single pattern rule
    - double pattern rule


#### 내용 없는 규칙
#### 내용 추가
#### 내용 함수
#### 루프
#### 조건 실행
- makefile 문법


#### 정의 실행


### cmake
### git / github
### Docker


---

### memo
- 
