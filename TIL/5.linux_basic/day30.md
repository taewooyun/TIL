# 4일차

## 확장과 쉘 옵션

### 확장
- 셸이 명렁을 해석하고 실행하기 전에 명령에 포함된 문자열, 수, 와일드카드 패턴 등을 변환하는 과정

() : parenthesis
[] : bracket
<> : angle bracket, chevrons
{} : curly brace
'' : single quote
"" : double quote
`` : grave accent
~ : tilde

#### brace expansion
- {} 를 사용해 문자열 시퀀스나 조합을 생성하는 것
```bash
echo {1..5} # 1부터 5까지 변환
1 2 3 4 5
echo {A..Z..2} # A부터 Z까지 증분 2
A C E G I K M O Q S U W Y
```

#### tilde expansion
- ~가 홈 디렉토리로 변환되는 것

#### 명령어 치환
- $()로 둘러싸인 명령어를 실행하고, 그 결과를 현재 셸의 명령어나 스크립트에서 사용할 수 있게 하는 것
```bash
#func_com_sub.sh
function magic_box_with_progress()
{
        input="$1"
        let "result = input + 8"
        echo "$input + 8 = $result"
        return $result
}

progress=$(magic_box_with_progress "7")
result=$?

echo "progress: $progress" # 표준 출력이 저장 된다
echo "result is $result"

#bash
$ ./func_com_sub.sh 
progress: 7 + 8 = 15
result is 15

```
```bash
~$ echo "current time is $(date +"%Y-%m-%d %H:%M:%S")" # 띄어쓰기 주의
current time is 2025-12-01 10:13:33
```

#### 산술 확장
- $(())나 이중괄호 (())로 감싼 표현식을 산술 연산해 그 결과를 스크립트에서 사용할 수 있게 하는것
- 정수형 변수의 산술 연산
    - declare -i로 변수 선언
- 산술 연산자
    - +, -, *, /, %, ++, -- : C언어와 동일
    - ** : 제곱, 2**2(=2²)
- 비교, 논리, 비트, 대입 연산자
    - C언어와 동일
 
 #### 서브스트링 확장
 - 변수에 저장된 문자열의 특정 부분을 추출하는 기능

 ```bash
# ${변수:오프셋:길이}
$ string="hello world!"
$ echo ${string: 1} # 앞에서 시작해 1부터 출력
ello world!
$ echo ${string: 1: 3} # 앞에서 시작해 1부터 3까지 출력
ell
$ echo ${string: -5} # 뒤에서 시작해 5부터 출력
orld!
$ echo ${string: -5: 3} # 뒤에서 시작해 5부터 3까지 출력
orl
 ```

#### 문자열 변경
```bash
# ${변수/패턴/문자열}
$ music="mi re do re mi mi mi"
$ echo ${music/mi/Mi} # 처음으로 발견되는 mi를 Mi로 변경
Mi re do re mi mi mi
$ echo ${music//mi/Mi} # 발견된 모든 mi를 Mi로 변경
Mi re do re Mi Mi Mi
$ echo ${music/#mi/MI~} # 해당 패턴으로 시작될 때만 변경
mi re do re mi mi mi
$ echo ${music/%mi/MI~} # 해당 패턴으로 끝날 때만 변경
mi re do re mi mi MI~

```
#### 대소문자 바꾸기

#### 변수 값에 따른 확장
- 빈 값일 때 지정한 값 사용하기
```bash
$ ${변수:-문자열}
```

- 빈 값일 때 지정한 값 사용하고 저장하기
```bash
$ ${변수:=문자열}
```

- 빈 값일 때 지정한 값 사용하고 저장하기
```bash
$ ${변수:?문자열}
```

- 빈 값이 아닐 때 지정한 사용하기
```bash
$ ${변수:+문자열}
```

#### 간접 확장
```bash
$ ${!변수}
```

#### 일치하는 패턴 제거

#### 확장 연산자

### 쉘 옵션


## 패키지 관리 시스템
### 패키지와 패키지 관리 시스템
패키지 : 소프트웨어 프로그램과 관련 파일들을 포함한 묶음
패키지 관리 시스템 : 패키지의 설치 업데이트 구성 제거를 자동화하고 관리하는 시스템

### systemd
user space
service > system-V init

systemctl
책 확인


staus
start
stop
restart




#### 데몬 프로세스




#### 유닛 파일
유닛파일을 만드는 방법




















---

### memo
- 
