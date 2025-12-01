# 2일차
## 5. 사용자와 사용자 그룹
### 사용자
#### 사용자의 종류
- root 사용자 : 리눅스 시스템의 모든 권한을 가진 관리자 계정
- 시스템 사용자 : 리눅스 시스템에서 만든 사용자
- 일반 사용자 : root사용자와 시스템 사용자를 제외한 모든 사용자

#### root 사용자
- 권고 사항
1. root 사용자의 비밀번호를 복잡하게 설정하고 주기적으로 변경하라
2. 시스템 외부에서 root 사용자로 로그인하지 못하게 설정하라

#### su 명령어


```bash
cat /etc/password
ottl:x:1000:1000:ottl,,,:/home/ottl:/bin/bash
```
- 의미


#### 사용자 그룹
```bash
cat /etc/group
ottl:x:1000:
```

#### 사용자 추가 및 삭제하기
```bash
adduser
deluser
```

## 6. 소유권과 권한
### 소유권
```bash
-rw-rw-r-- 1 ottl ottl 0 11월 27 10:05 1
-rw-rw-r-- 1 ottl ottl 0 11월 27 10:05 2
-rw-rw-r-- 1 ottl ottl 0 11월 27 10:05 3 # type/User/Group/Others

iam@ottl-VirtualBox:~$ echo hello >> 1
bash: 1: Permission denied
```

```bash
chown -r
```
### 파일 권한
chmod 
r: 4
w: 2
x: 1


### 디렉토리 권한
r: 폴더 내용 확인
w: 폴더 내 파일 생성
x: 폴더 열기

- .
- source

## 7. 프로세스 관리
### 프로세스란
- linux is process oriented
    - 스케줄링 엔티티
        - process : {user process}
        - thread  : {user pthread / kenal kthread}

    - "task_struct" : task(process) control bock
        - 프로세스 상태를 관리하기 위한 구조체
        - PCB(Process Controll Block)

    - instance(windows)


- active process 
- passive process



- $ps
    - -l
    - -e : entire
    - -f
- $pstree

```bash
$ ps -elf | head
F S UID          PID    PPID  C PRI  NI ADDR SZ WCHAN  STIME TTY          TIME CMD
4 S root           1       0  0  80   0 - 42394 -      08:57 ?        00:00:22 /sbin/init splash
1 S root           2       0  0  80   0 -     0 -      08:57 ?        00:00:00 [kthreadd]
1 I root           3       2  0  60 -20 -     0 -      08:57 ?        00:00:00 [rcu_gp]
1 I root           4       2  0  60 -20 -     0 -      08:57 ?        00:00:00 [rcu_par_gp]
1 I root           5       2  0  60 -20 -     0 -      08:57 ?        00:00:00 [slub_flushwq]
1 I root           6       2  0  60 -20 -     0 -      08:57 ?        00:00:00 [netns]
1 I root           8       2  0  60 -20 -     0 -      08:57 ?        00:00:00 [kworker/0:0H-events_highpri]
1 I root          10       2  0  60 -20 -     0 -      08:57 ?        00:00:00 [mm_percpu_wq]
1 S root          11       2  0  80   0 -     0 -      08:57 ?        00:00:00 [rcu_tasks_rude_]
```

- [] = 커널 쓰레드
- PID 1 : systemd : sbin/init splash
    - 부팅할 때 초기화를 담당
    - SysV init를 업그레이드 한 버전
- PID 2 : [kthreadd]


```bash
ottl@ottl-VirtualBox:~$ ps -l

F S   UID     PID    PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  115160  115159  0  80   0 -  3019 do_wai pts/0    00:00:00 bash
0 R  1000  115736  115160  0  80   0 -  3179 -      pts/0    00:00:00 ps
```
- S : 상태
- PID : process ID
- PID : Parents process ID
- PRI & NI : 우선순위

- $ sleep 100

- $ kill -l
    - $ kill -3 {PID}

### 프로세스의 생애주기
1. fork();

### 프로세스 스케줄링

### 프로세스의 상태
실행 또는 대기
중단
깨어나지 않는 수면 상태
깨어날 수 있는 수면 상태
종료


### 파일 디스크립터와 표준 스트림
파일 입출력의 종류
    1. 저수준 파일 입출력
        - 버퍼 x : for device
        - 버퍼 o : for application
    2. 고수준 파일 입출력
        - 버퍼 o : for application

#### file descriptor
```c
    int fd = open(); // read(), write(), close()
    printf("%d", fd); // 3 ...4...5 ~
```
stdin  0
stdout 1
sdderr 2
이미 3가지의 파일이 open되어 있음

#### file stream
```c
    FILE* fp = fopen(); // fread(), fwirte(), ..., fclose()
```

### Foreground와 Background 프로세스
- $ jobs
- $ fg {jos number *ex %3*}

#### fg
stdin 가능
stdout 가능
stderr 가능

#### bg
stdin 불가
stdout 가능
stderr 가능

#### $ ping
ICMP 에코 요청 및 응답

#### $ jobs
- 실행중인 유저 프로세스?

### IPC
- Inter Process Communication : 프로세스 간 통신에 사용하는 도구

#### 파이프
- 단방향

- pipe : 두 프로세스 간 데이터를 전송할 때 사용하는 IPC
- named pipe : 파일 형식의 이름을 부여할 수 있는 파이프
#### 메시지 큐
- 단방향

#### 소켓
- 양방향?

- 소켓 : 
- 인터넷 소켓 : 
- 유닉스 도메인 소켓

#### 공유 메모리
각자의 가상메모리로 동일한 물리 메모리에 접근하여 통신하는 방식?

#### 세마포어
- 카운팅 세마포어
- 바이너리 세마포어


## 8. 시그널 송수신
- 특정 프로세스에게 어떤 이벤트가 발생했음을 알려줌
```bash
$ kill -l;
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX
```

커널 -> 프로세스
프로세스 <-> 프로세스
프로세스 자신

에게 송신할 수 있다


POSIX



# 리눅스 활용

## 9. Bash: 조건문과 테스트 연산자
### 변수 in Bash
```bash
$ V1 = test
$ echo $V1
test
```

let "표현식"
expr 표현식



### 조건문과 테스트 연산자
#### if문
if
then
elif
then
else
fi

if()와 if(( a < b ))


#### if문의 조건
- True  : 프로세스 종료 코드로 0을 리턴 받았을 때
- False : 0이 아닌 값을 받을 때

#### 문자열 테스트 연산자

#### 산술 테스트 연산자

#### 파일 테스트 연산자

#### 논리 테스트 연산자

#### case문


## 10. Bash: 반복문, 함수, 변수, 배열, 쿼팅

### 반복문

#### for문
```bash
// 기본 형식
for 변수 in 목록
do
    명령
done

// C언어 스타일
for((초기식; 조건식; 증감식))
do
    명령
done
```

#### while문
- 조건이 참인 동안 반복
```bash
while 조건식
do
    명령
done
```

#### until문
- 조건이 거짓인 동안 반복
```bash
until 조건식
do
    명령
done
```

#### break와 continue
- break : 반복을 중단
- continue : 다음 반복으로 건너뜀

### 함수

#### 함수 작성

#### 함수의 반환값과 출력값
- 반환값 : 
    
- 출력값

- 명령어 치환


### 변수 심화

#### 매개변수
- 위치 매개변수

- 특수 매개변수
    - $# : 매개변수의 갯수
    - $0 : 실행중인 스크립트 파일의 이름
    - $* : 모든 위치 매개변수를 하나의 열로 인식 - 개별 접근시 하나로 인식
    - $@ : 모든 위치 매개변수를 하나의 열로 인식 - 개별 접근시 개별로 인식
    - $? : 최근에 실행된 명령이나 함수, 스크립트의 프로세스 종료 코드 또는 반환값
    - $$ : 현재 실행중인 셸의 PID

#### 변수의 범위
- 변수에 접근해 사용할 수 있는 코드 영역 또는 코드 영역의 범위

- 함수 로컬 변수: 함수안에서 로컬이라는 키워드와 함께 선언된 변수
- 글로벌 변수: 함수로컬변수를 제외한 모든 변수

- 쉘 변수
-    set

- 환경 변수
    - env
    - $ export
        - 쉘에서 선언한 변수를 새로운 스크립트에서도 사용할 수 있게 함
    - 주요 환경 변수
    - HOME
    - PATH
        ```bash
        /usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/
        local/games:/snap/bin
        ```
        - 명령어를 찾는 위치
    - PWD
    - USER
    - SHELL
    - LANG
    - TERM
    - PS1
    - HOSTNAME



- .profile
- .bashrc

### 쿼팅

- single ' ' : 문자 그대로 출력
- double " " : 변수, 탈출문 등을 반영시키고 출력
- escape \




## 리디렉션과 파이프라인

### 리디렉션
#### 출력 리디렉션
```bash
>
>>
```
- > : write
- >> : append

- 표준 에러 리디렉션

#### 입력 리디렉션


#### here documents
#### here strings


### 파이프라인










---

# memo
- !$

- () (()) [] [[]] 차이
---

# ✅ 조건식

## `[` … `]`  또는  `[[` … `]]`

조건 판단용(참/거짓)

```bash
if [ "$a" -gt 3 ]; then
    echo "bigger"
fi
```

```bash
if [[ $str == foo* ]]; then
    echo "starts with foo"
fi
```

* `[ ]` = POSIX test → 엄격, 공백 중요
* `[[ ]]` = Bash 확장 → 안전하고 기능 많음

---

# ✅ 산술식

## `(( ))`

**정수 연산 + 대입 + 조건**

```bash
((x = 3 + 5))
((x++))
if ((x > 10)); then echo hi; fi
```

* `$` 없이 변수 직접 변경 가능
* 결과는 **참/거짓**으로도 사용됨

---

# ❗ `$(( ))` — 계산 결과를 **값으로 반환**

출력용 또는 대입에 사용

```bash
sum=$((3 + 5))
echo $((x * 10))
```

* `(( ))`과 다르게 “값을 문자열로 반환”함

---

# 📌 완벽 정리

| 구문       | 의미      | 용도                |
| -------- | ------- | ----------------- |
| `[ ]`    | test 명령 | 조건 비교 (POSIX)     |
| `[[ ]]`  | 확장 test | 조건 비교 (문자열/패턴/안전) |
| `(( ))`  | 산술 평가   | 정수 연산·대입·조건       |
| `$(( ))` | 산술 확장   | 정수 계산 결과 반환       |

---

## 한 줄 요약

> 조건 판단은 `[ ]` / `[[ ]]`,
> 숫자 계산은 `(( ))` 또는 `$(( ))`.

- 환경변수
---

# 🔥 1) **환경 변수(PATH, LANG 등) → `.profile`**

이유:

* **로그인 시 1번만 실행**
* **자식 프로세스 전체가 공유해야 하는 값**에 적합

예:

```bash
export PATH="$HOME/bin:$PATH"
export JAVA_HOME="/usr/lib/jvm/java-17"
```

---

# 🔥 2) **개발 편의 / 셸 기능(alias, 함수) → `.bashrc`**

이유:

* **새 터미널 열 때마다 실행**
* 인터랙티브 셸 환경 개선 목적

예:

```bash
alias ll='ls -alF'
export PS1="\u@\h:\w$ "
```

---

# 🔥 “export한 걸 저장” 관점에서 요약

* **단순히 export 명령만 입력** → 현재 세션에만 반영 = 터미널 닫으면 사라짐
* **설정 파일에 적어두면** → 다음 로그인/터미널부터 자동 적용

---

# 💡 어디에 넣을지 빠른 판단

| 성격                  | 파일                                          |
| ------------------- | ------------------------------------------- |
| 시스템 전체/환경변수         | `.profile`, `.bash_profile`, `/etc/profile` |
| 사용자 편의/alias/prompt | `.bashrc`                                   |
| GUI 로그인 전역 변수       | `~/.profile` 또는 `/etc/environment`          |

---

# ✔️ 실전 예시

👉 PATH 유지하고 싶다

### ❌ 그냥 터미널에서

```bash
export PATH=$HOME/bin:$PATH
```

→ 세션 종료 시 날아감

### ✔️ 영구 적용

**`~/.profile`** 또는 `~/.bash_profile`에 추가

```bash
export PATH="$HOME/bin:$PATH"
```

---

# 🤔 왜 `.profile` vs `.bashrc`가 나뉨?

* 환경 변수는 **로그인 시 한 번**만 설정하면 충분
* alias/프롬프트는 **매 인터랙티브 세션마다** 적용되면 편함

그래서:

> **환경 = profile, 편의 = bashrc**

---

## 📌 결론

**export 값 영구 적용하려면 설정 파일에 저장해야 한다.**

* **환경 변수 → `.profile` 권장**
* **alias, prompt → `.bashrc`**
