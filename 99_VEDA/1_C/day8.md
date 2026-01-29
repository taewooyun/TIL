### 조건부 컴파일 지시자

- 일반 조건문과 달리 조건에 따라 컴파일 자체를 할 지 말 지 판단할 수 있음
- #if / #ifdef / #ifndef / #else / #endif
    - # ifdef == #if defined(전처리 상수값)

### #pragma 지시자

- pack
    - 패킹(구조체의 패딩을 조절)을 지시함
    - #pragma pack(push, 1) ~ #pragma pack(pop)

---

### + 추가

- #pragma 나머지 메서드?
    - warning
    - once : 헤더파일을 합치는 과정에서 같은 내용의 코드가 중복되더라도 한번만 선언
- #undef
- #error
- #line
- 기타

## 분할 컴파일

- .pdb 디버그 모드에서만 → 릴리즈 시 exe 파일도 용량이 줄어듬

### extern과 static의 용도

- 

## 과제

### 문제

```
Level 1.

1. 학생 구조체를 생성합니다.  이름과 나이, 점수를 저장할 수 있으며,
이름은 40자 이내, 나이는 정수, 점수는 실수로 표기합니다.

2. 10명의 학생 정보를 입력받아 저장할 수 있도록 배열을 생성합니다.

3. 생성된 배열을 이용하며 반복문으로 입력장치로 부터 해당 정보를 입력합니다.

4. 반복문을 이용하여 해당 배열의 내용을 출력합니다.
반복문에서는 구조체 배열의 이름을 직접 사용하여 출력합니다.

Level 2.

1. 동일한 구조체와 배열을 이용합니다.

2. 10명의 학생 정보를 프로그램에서 초기화 하여 지정합니다.

3. 포인터 변수를 선언하고 반복문에서 포인터 변수를 이용하여
배열 인덱스 방법과 주소 + 연산의 두 방법으로 동일하게 출력을 작성합니다.

Level 3.

1. 동일한 구조체를 이용합니다.

2. 10명의 학생 정보를 저장할 수 있는 구조체 포인터 배열을 선언합니다.

3. 동적할당을 이용하여 학생정보를 저장할 수 있는 공간을 생성합니다.

4. 반복문을 이용하여 학생의 정보를 입력받습니다.

5. 반복문을 이용하여 입력받은 학생의 정보를 출력합니다.
이때 포인터의 ++ 연산을 사용합니다.

6. 과목의 평균을 구하여 출력합니다.

```

### 과제 제출

```c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define N 10

typedef struct {
    char name[40];
    int age;
    double score;
} Student;

void level_one();
void level_two();
void level_three();

int main(void) {
    char level;

    while (1) {
        puts("-------------------------------------------");
        puts("[select level]");
        puts("1: level 1\n2: level 2\n3: level 3\n0: exit");
        scanf("%c", &level);

        switch (level)
        {
        case '1' :
            level_one(); // level 1
            break;
        case '2' :
            level_two(); // level 2
            break;
        case '3' :
            level_three(); // level 3
            break;
        default:
            return 0;
        }

        getchar(); // 개행 문자 제거
    }

    return 0;
}

void level_one() {
    Student students[N];
    int i;

    // 학생 정보 입력
    printf("%d명의 학생정보를 입력합니다.\n\n", N);
    for (i = 0; i < N; ++i) {
        printf("[%2d번 째 학생]\n", i + 1);
        printf("이름 : ");
        scanf("%s", students[i].name);
        printf("나이 : ");
        scanf("%d", &students[i].age);
        printf("점수 : ");
        scanf("%lf", &students[i].score);
    }

    // 학생 정보 출력
    puts("\n[전체 학생 목록]");
    for (i = 0; i < N; ++i) {
        printf("%d.\n이름: %s\n나이: %d\n점수: %.1lf\n",
            i + 1, // 0번 째 -> 1번 째 부터 시작
            students[i].name,
            students[i].age,
            students[i].score);
    }
}

void level_two() {
    Student students[N];
    int i;

    // 학생 정보 입력
    printf("%d명의 학생정보를 입력합니다.\n\n", N);
    for (i = 0; i < N; ++i) {
        printf("[%2d번 째 학생]\n", i + 1);
        printf("이름 : ");
        scanf("%s", students[i].name);
        printf("나이 : ");
        scanf("%d", &students[i].age);
        printf("점수 : ");
        scanf("%lf", &students[i].score);
    }

    // 학생 정보 출력
    Student* ps = students; // 배열 포인터 선언
    puts("\n[전체 학생 목록]");
    for (i = 0; i < N; ++i) {
        printf("%d.\n이름: %s\n나이: %d\n점수: %.1lf\n",
            i + 1, // 0번 째 -> 1번 째 부터 시작
            ps[i].name,
            (*(ps + i)).age,
            (ps + i)->score);
    }
}

void level_three() {
    Student* ps[N];
    int i;

    // 동적 할당
    for (i = 0; i < N; ++i) {
        ps[i] = (Student*)malloc(sizeof(Student));
    }

    // 학생 정보 입력
    printf("%d명의 학생정보를 입력합니다.\n\n", N);
    for (i = 0; i < N; ++i) {
        printf("[%2d번 째 학생]\n", i + 1);
        printf("이름 : ");
        scanf("%s", ps[i]->name); // 멤버 name은 값이 아닌 char 배열의 주소
        printf("나이 : ");
        scanf("%d", &ps[i]->age);
        printf("점수 : ");
        scanf("%lf", &ps[i]->score);
    }

    // 학생 정보 출력
    Student** pps = ps; // 증감 연산자로 접근하기 위해 포인터 배열을 가리키는 이중 포인터 선언
    puts("\n[전체 학생 목록]");
    for (i = 0; i < N; ++i) {
        printf("%d.\n이름: %s\n나이: %d\n점수: %.1lf\n",
            i + 1, // 0번 째 -> 1번 째 부터 시작
            (*pps)->name,
            (*pps)->age,
            (*pps)->score);
        pps++;
    }

    // 과목 평균 출력
    double avg = 0;
    for (i = 0; i < N; ++i) {
        avg += ps[i]->score;
    }
    printf("\n[과목 평균] %.2lf\n\n", avg / N);

    for (i = 0; i < N; ++i) {
        free(ps[i]);
    } // 포인터 배열 메모리 할당 해제
}
```

### 과제 일지

## 1.

```c
Student(* ps)[sizeof(Students)] = students;
```

- Level 2 구조체 배열을 가리킬 포인터 변수를 선언하는 과정에서 포인터 선언을 위와 같이 선언하였다.
- 구조체 배열은 이미 선언이 되어있는 상태, 이를 인덱스로 접근하기 위해 메모리 구조 관점에서 2차원 배열 = 구조체의 배열 이라 생각했고 이에 1차 배열에 해당하는 구조체 자체를 가리킬 필요가 있다고 판단했다.

```c
Student* ps = students;
```

→ 이미 Student로 선언되어 포인터 변수는 구조체의 크기 단위로 바라보고 있기 때문에 students의 첫 원소 주소만 입력해주면 인덱스나 주소 연산으로 접근 가능해 해당 코드로 해결할 수 있는 문제였다.

## 2.

```c
Student *ps[n];
Student *s = ps;
int i=0;
while (s++ != NULL){
    printf("%d.\n이름: %s\n나이: %d\n점수: %.1lf\n",
            (i++)+1,
            s->name,
            s->age,
            s->score);
}
```

- Level 3 구조체 포인터 배열을 증감연산자로 순회하기 위해 위와 같이 코드를 작성하였다
- 의도했던바는 Level 2처럼 s가 ps 배열의 첫번째를 가리키게하고 s를 증가시켜 순회하려고 하였지만 문제가 있었다
    1. while문의 탈출조건에서 s는 ps(주솟값)에서 시작하여 NULL을 만날 확률이 거의 없다는것
    2. 단일 포인터로 선언된 s는 구조체 하나만을 가리킬 수 있기 때문에 포인터 배열인 *ps에 접근하기 위해서는 이중 포인터로 받아야 한다는것

```c
Student *ps[n];
Student** pps = ps;

for (i = 0; i < N; ++i) {
    printf("%d.\n이름: %s\n나이: %d\n점수: %.1lf\n",
        i + 1, // 0번 째 -> 1번 째 부터 시작
        (*pps)->name,
        (*pps)->age,
        (*pps)->score);
    pps++;
}
```

→ 따라서 이중 포인터를 사용하여 포인터 배열에 접근하고 기준을 횟수로 잡아 해결할 수 있었다

---

### 느낀 점

- 이번 과제를 통해 포인터, 포인터 배열과 배열 포인터의 관계, 각각의 문법을 습득해보면서 기대한 동작과 실제 코드 동작과의 차이점을 느껴보고 포인터에 대한 이해도를 높일 수 있었다

---

## 자습

- 디버그 모드에서만 실행되는 코드
- 외부 작업 공유 시 → 헤더파일(함수의 프로토타입) + obj
    - 라이브러리의 형태로도 공유
-