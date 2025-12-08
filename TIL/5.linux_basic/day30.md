# 4일차

## 11. 확장과 쉘 옵션

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


## 13. 시스템 관리
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

### .bashrc를 이용한 개인화

#### .profile과 .bashrc
.profile은 로그인을 하면 실행되는 설정파일
.bashrc는 프롬프트가 하나 생성되면서 실행됨

.profile을 실행하면 .bashrc가 실행된다


#### .bashrc의 역할
- 다른 파일을 읽어들인다
- 변수를 설정한다
- alias를 설정한다
- bash 셸 옵션을 설정한다
- 편의를 위한 개인 설정 모음 파일


```bash
$ alias [설정] # alias 목록 생성, 열람
```

## 14. 필수 커맨드라인 툴

### 1) grep
- Global Regular Expression Print
- 표준 입력이나 텍스트 파일에서 특정 패턴이나 문자열을 검색하는 커맨드라인 툴
```bash
$ grep [옵션] 패턴 [파일]

$ cat [파일] | grep [옵션] 검색어 # 파이프라인과 결합하여 사용
```

#### 옵션 목록

| 옵션     | 의미                  | 예시               |                   
| ------ | ------------------- | ------------------------------------- |
| `-r`   | 디렉토리 **재귀 검색**      | `grep -r "main" src/` |                   
| `-i`   | **대/소문자 무시**        | `grep -i "error" log.txt`       |
| `-v`   | **매칭 제외**           | `grep -v "DEBUG" server.log`|
| `-n`   | **줄 번호 출력**         | `grep -n "TODO" *.c`                  | 
| `-c`   | **매칭된 라인 개수**       | `grep -c "ERROR" access.log`          | 
| `-l`   | **매칭된 파일명만**        | `grep -l "main" *.c`           |    
| `-L`   | **매칭되지 않은 파일명만**    | `grep -L "TODO" *.c`|    
| `-E`   | **확장 정규표현식 사용**     | `grep -E "ERROR WARN" system.log` |
| `-o`   | **매칭된 부분만 출력**      | `echo "v1.2.3" \| grep -o "[0-9.]\+"` | 
| `-A N` | **매칭된 라인 이후 N줄 표시** | `grep -A 3 "panic" kernel.log`        | 


### 2) find
- 파일이나 디렉터리를 검색하는 커맨드라인 툴
```bash
$ find [옵션] [경로] [표현식]
```
- $ find -L : 심볼릭 링크를 쫓아가 링크에 해당하는 파일들에 대해 작업
- P find -P : 심볼릭 링크 자체에 대해 작업 (default)

#### 주요 표현식
| 표현식           | 의미                | 예시                                             |
| ------------- | ----------------- | ---------------------------------------------- |
| `-name`       | 파일명 패턴 매칭 (와일드카드) | `find . -name "*.c"` |
| `-iname`      | 대소문자 무시 파일명 매칭   | `find . -iname "*.png"`|
| `-type`       | 파일 타입 조건| `find . -type f` (파일)|
| `-size`       | 파일 크기 조건          | `find . -size +10M`        |
| `-mtime`      | 수정 시간 (일 단위)      | `find . -mtime -3` (최근 3일)     |
| `-mmin`       | 수정 시간 (분 단위)      | `find . -mmin -60` (지난 1시간) |
| `-user`       | 특정 사용자 소유  | `find /var -user root`         |
| `-group`      | 특정 그룹 소유   | `find /data -group dev`       |
| `-perm`       | 퍼미션 조건             | `find . -perm 644`    |
| `-exec`       | 찾은 결과에 명령 실행 | `find . -name "*.log" -exec rm {} \;`    |
| `-maxdepth`   | 검색할 디렉터리의 최대 깊이 | `find . -maxdepth 1 \;`    |
| `-mindepth`   | 검색할 디렉터리의 최소 깊이 | `find . -mindepth 3 \;`    |
| `-not` or `!` | 조건 부정             | `find . ! -name "*.c"`          |
| `-or`         | OR 조건             | `find . -name "*.c" -or -name "*.h"`    |
| `-and`        | AND 조건(기본)        | `find . -type f -and -size +1M`|


### 3) stat
- 파일이나 파일 시스템의 상세 정보를 표시하는 커맨드 라인 툴
```bash
$ stat [옵션] [파일]
```
Access : 파일을 사용한(읽어본) 시점
Modify : 파일의 내용이 변경
Change : 파일의 메타데이터가 변경


### wc
- 
```bash
$ wc [옵션] [파일]
```

### df
- 
```bash

```

### du
- 
```bash

```

### tar
- 
```bash
$ tar [옵션] [-f 아카이브파일] [파일]
```
- 


### read
- 
```bash
$ read [옵션] [변수]
```

### tr
- 
```bash
$ tr [옵션] 문자1 [문자2]
```











---

### memo
- 
