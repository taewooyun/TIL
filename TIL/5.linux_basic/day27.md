# 1일차
## 리눅스 프로그래밍

kernel < shell(bash) < user
장치드라이버는 커널의 일부분
리눅스는 모든걸 파일로 관리한다
cpu : --> program
program
	1. a.out @ hdd	- passive process		// 실행 중이지 않은 프로세스
	2. a.out @ RAM	- active process		// 실행 중인 프로세스
cpu의 자원은 프로세스가 사용
cpu의 자원을 어느 프로세스에 할당할건지 정하는게 스케줄링 그걸 하는 주체가 스케줄러
스케줄링 알고리즘은 여러 개가 있고 OS마다 다름
여러 프로세스를 동시에 실행하면 멀티 태스킹
인터럽트 : 하드웨어가 소프트웨어에 보내는 신호

## 1장
## 2장
설치

## 3. 터미널과 셸
### 터미널
- 컴퓨터가 사용자와 상호작용할 수 있는 하드웨어
### 셸
- 운영체제와 사용자와 상호작용할 수 있는 소프트웨어

- 운영체제가 제공하는 명령어 기반 인터페이스

### 셸 스크립트
- 셸에서 동작 가능한 명령을 모아놓은 파일
- .sh
- 한 번에 여러 명령을 수행
```bash
$ echo echo hello world >> hello.sh
$ . hello.sh
$ hello world
```

### 리눅스 기본 명령어
- man [옵션] [섹션] 페이지
- ls : 파일 목록 확인
    - -a : 숨김 파일 확인
    - -l : 상세 내용 확인
    - -i : 
- cd
    - change dir
- pwd
    - print working dir
    - 현재 절대 경로 표시
- cat
    - concatenate
    - 파일의 내용을 연결하거나 조회하는 명령어


- set
- grep
- wc
    - word count
- | 키워드

- mkdir
    - -p
- rmdir
    - 비어있는 디렉토리 삭제
- mv
    - 파일 위치를 변경
    - mv 원본 복사본 : 이름 변경
- rm
    - -r
    - -f
- cp

- mount

- w
- stat


## 파일 시스템

### 리눅스 시스템 구성 요소
1. bootloader(u-boot)
2. kernel
3. device tree
4. root file system
#### Root file System
mount ?
#### 가상파일시스템

### 리눅스 파일 시스템

ext4
vfat

### 파일의 종류
- 일반 파일 : -
- 디렉터리 : d
- 심볼릭 링크 파일 : l
- 블록 디바이스 파일 : b
- 문자 디바이스 파일 : c
- 파이프 파일 : p
- 소켓 파일 : s
### 디렉토리
#### 루트 디렉터리 하위 주요 디렉터리
/bin
- 기본 실행 명령어
/dev
- 디바이스 파일
/etc
- 시스템 설정 파일
/home
- 사용자 홈 디렉터리
/lib
- 시스템 라이브러리
/mnt
- 시스템에 디스크 등을 임시로 마운트할때 사용
/proc
- porcfs가 마운트
- 커널이 정보를 오픈해놓는곳
/root
- 루트 사용자의 홈 디렉터리
/sbin
- 시스템 관리용 명령어
/sys
- sysfs가 마운트
- 디바이스 드라이버들이 정보를 오픈
/tmp
- 시스템 임시 파일
/usr
- 시스템 소프트웨어

### 소프트링크와 하드링크
- ln
    - 하드 링크

```bash
$ls -l
-rw-rw-r-- 2 ottl ottl 18 11월 26 16:09 a
-rw-rw-r-- 1 ottl ottl  6 11월 26 16:04 ac
-rw-rw-r-- 2 ottl ottl 18 11월 26 16:09 al
```

```bash
$stat a
  File: a
  Size: 18              Blocks: 8          IO Block: 4096   regular file
Device: 805h/2053d      Inode: 1572877     Links: 2
Access: (0664/-rw-rw-r--)  Uid: ( 1000/    ottl)   Gid: ( 1000/    ottl)
Access: 2025-11-26 16:09:18.124124032 +0900
Modify: 2025-11-26 16:09:12.312094124 +0900
Change: 2025-11-26 16:09:12.312094124 +0900
 Birth: -
```
- 메타데이터 확인

- ln -s
    - 소프트 링크
```bash
$ls -l
total 16
-rw-rw-r-- 2 ottl ottl 18 11월 26 16:09 a
-rw-rw-r-- 1 ottl ottl  6 11월 26 16:04 ac
-rw-rw-r-- 2 ottl ottl 18 11월 26 16:09 al
lrwxrwxrwx 1 ottl ottl  1 11월 26 16:14 as -> a
-rw-rw-r-- 1 ottl ottl 74 11월 26 14:44 hello.c
```

디렉토리에다 링크를 걸수있는건 symbolic link(soft link)만 가능


소프트링크 하드링크

대상 파일의 확인

대상 파일의 범위

대상 파일과 링크 파일의 결합도



#### inode
- 실제 파일의 정체(이름?)







---

### memo
- mcu와 pc용 프로세스의 차이
    - mcu는 직렬 pc는 병렬?
- 하이퍼바이저 의미
- 