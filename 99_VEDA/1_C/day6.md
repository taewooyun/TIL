## 포인터 배열

- 배열 주소의 계산법
    - arr+1 : +원소 크기*1 만큼 더함
    - &arr+1 : +주소 크기*1 만큼 더함
- arr[3][4]
    - arr[0] : 첫번 째 원소, 2차원 배열 전체의 주소
    - arr[1] : arr[1][0] ~ arr[1][3] 의 주소
- 배열 포인터의 선언
    - int* pa[4] : int형 포인터 변수 4개
    - int(* pa)[4] : 크기가 4인 배열을 가리키는 포인터 변수 1개
- 미리 선언된 상수 값은 동일하면 여러번 호출하더라도 같은 주소에 저장되어 있음

## 함수 포인터

- 예시
    - int sum(int, int);
        
        int (*fp)(int, int);
        
        - fp = sum;
        - fp(10, 20);
    - void func(int (*fp)(int, int));
        - func(sum);

## void 포인터

- void *vp
- *(int *)vp
- void 포인터는 간접 참조 연산과 주소에 대한 정수 연산이 불가능하다

## 동적 메모리 할당

- malloc
    - int *p;
        
        p = (int *)malloc(sizeof(int));
        
    - int *p = (int *)malloc(sizeof(int));
- calloc
    - int *p = (int *)calloc(size, sizeof(int));
- realloc
    - int *p = (int *)realloc(p, size * sizeof(int));

---

## 자습

- 포인터를 사용하는 이유
    - 더블 포인터를 사용해야만하는 상황, 활용법