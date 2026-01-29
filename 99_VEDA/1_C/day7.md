### main 함수의 명령행 인수 사용

```c
int main(int argc, char** argv){
	for(int i=0; i<argc; i++){ // 인자의 개수
		printf("%s\n", argv[i]); // 인자로 전달된 문자열 접근
	}
}
```

- 실행결과

```bash
> test.exe first_arg second_arg
test.exe
first_arg
second_arg
```

## 구조체

- 구조체는 실행 효율을 위해 패딩 바이트를 넣어 바이트 정렬을 한다
    - 64비트(8바이트) 주소체계 기준
    - 8바이트 단위로 잘라서 메모리에 배치
    - 따라서 구조체의 전체 크기는 컴파일러의 정렬 정책에 따라 커질 수 있다
- (*ps).member == ps→member

### 자기 참조 구조체

- 연결 리스트

### 공용체

- union
    - 하나의 메모리를 여러 멤버(타입, 이름)로 사용할 수 있음

## 파일 개방과 입출력

- FILE *fp = fopen(”a.txt”, “r”);
    - 해당 모드로 해당 파일의 통로를 연다
        - “r” “w” “a”
        - 
- fclose(fp);
- EOF
    - End of File(= \z)
    - 텍스트 파일은 무조건 들어감
- fgetc, fputc 활용
    - stdin, stdout?
- getchar, putchar 활용

### 텍스트 파일과 바이너리 파일

- 모드에 따라, putc와 puts 등등의 차이에서 다르지 않는가

### 개방 모드, fseek, rewind, feof

- fseek(FILE* stream, long offset, whence)
    - whence(기준 위치)
        - SEEK_SET : 파일의 처음
            - 오프셋 : 양수만 가능
        - SEEK_CUR : 파일의 현재 위치
            - 오프셋 : 음수, 양수 둘다 가능
        - SEEK_END : 파일의 끝
            - 오프셋 : 음수만 가능
    - fseek(fp, 0, SEEK_SET) == rewind(fp)

### fgets / fputs : 한 줄씩 입출력

- fgets
    - gets : 개행문자를 자동으로 NULL문자로 변환
    - fgets : 자동 변환 X

### fscanf / fprintf : 다양한 형태의 입출력

- 비추

### fflush

### fread, fwrite

---

# 19장 - 전처리 지시자

- #include : 헤더파일 임포트
    - <> : 시스템 표준 헤더파일
    - “” : 주로 사용자 헤더파일
- #define : 매크로명 만들기
    - 컴파일 전에 수행
    - 가독성, 편의성 증가
    - 코드를 대치하기만 하기 때문에 매크로 함수의 계산식에서 우선 순위가 기대한 값이 나오지 않을 수 있음
        - 괄호로 우선순위를 꼭 잡아주자
- 이미 정의 된 매크로도 있음
    - __FILE__ 등등
- #과 ##
    - 합치는것과 대치?

---

## 자습

- 포인터 변수를 배열 인덱스로 접근했을 때
- 매개변수로 배열을 받을 때는 무조건 포인터로 해야하는가
- struct의 포인터 표현식
    - list[i].name, (*(list+i)).age, (list+i)->tel
- 헤더, 바디, 매크로 함수 등의 컴파일링 순서와 메모리 상관 관계
-