### Interface Segregation Principle

- 인터페이스는 작고 섬세해야 하고, 클래스는 필요한 인터페이스만 구현해야 한다
- SRP와 연관해서
    - SRP - 클래스는 한 가지 기능만 수행해야 하고 한 가지 이유로만 변경해야한다
    - 클래스가 여러 인터페이스를 상속 받으면 SRP를 위반
    - 인터페이스가 여러 목적을 정의하여도 SRP를 위반
- ISP를 만족시키기 위한 객체지향 프로그래밍의 특성
    - 인터페이스는 반드시 최소한의 인터페이스만을 상속 받아서 구현해야 함
    - 여러 기능이 필요한 클래스라면 ‘has-a’로 직접 구현이 아닌 멤버로 포함해야 함

### Defendency Inversion Principle

- 상위 수준 모듈은 하위 수준의 모듈에 의존해서는 안 되며 상위 하위 수준 모두 추상 레이어(인터페이스)에 의존해야 한다
- DIP를 만족시키기 위한 객체지향 프로그래밍
    - SRP와 연관, 하위 모듈이라는게 존재하나? → 하위 모듈에 상위 모듈이 의존해서는 안된다

# 10. 템플릿

## 함수 템플릿

### 템플릿으로 범용 함수 만들기

- 범용 함수 만들기
    - 다양한 데이터 형식의 매개변수를 2개 입력 받아서 덧셈하는 범용 함수
    - 데이터 형식별로 거의 동일한 코드를 반복해서 만들어야 함
    - 처리할 수 있는 데이터 형식을 추가하려면 함수도 함께 추가 해야 함
- 선언
    
    ```cpp
    template<typename T>
    T sum(T operand1, T operand2){
        return operand1 + operand2;
    }
    ```
    
- 템플릿 함수는 컴파일 단계에서 바디를 만듬

### 템플릿 특수화

```cpp
template<>
double sum(double operand1, double operand2){
    return (int)operand1 + (int)operand2;
}
```

## 클래스 템플릿

- 선언

```cpp
template<typename Type1, typename Type2>
class TemplateClass {
	public :
		TemplateClass(Type1 t1, Type2 t2) : first(t1), second(t2){}
	private : 
		Type1 first;
		Type2 second;
}
```

### 부분 특수화

```cpp
template<typename Type1, typename Type2>
class TemplateClass<string, Type1> { // 부분 특수화
	public :
		TemplateClass(string t1, Type2 t2) : first(t1), second(t2){}
	private : 
		string first;
		Type1 second;
}
```

### 중첩 클래스 템플릿

### default parameter

- void function(int a, int b=10){}

## 클래스 템플릿 프렌드

- 

# 라이브러리 활용

## 표준 라이브러리 구성과 사용법

### 표준 라이브러리 구성

- 프로그램시 활용 가능한 범용 라이브러리의 집합체
    - 100여개가 넘는 헤더파일로 구성되어있으며 꾸준히 업데이트
- 주요 가능
    - 입출력 : 입출력 스트림을 사용하여 파일, 키보드, 화면과의 상호작용
    - 문자열 처리 : 문자열 조작, 검색, 대소문자 변환 등
    - 컨테이너 : 벡터, 리스트, 큐, 스택 등의 자료 구조
    - 알고리즘 : 검색, 정렬, 변환 그래프 알고리즘 등을 제공
    - 기타 유틸리티 : 다양한 도구와 유틸리티 함수를 제공, 작업을 단순화하고 생산성을 높임

### SLL과 DLL

- 표준라이브러리
    - SLL
- DLL

## 문자열 라이브러리

- #include <string>
    - size() : 메모리 사이즈
    - length() : 문자열의 길이
    - find()
    - replace()

### 반환형이 참조 변수가 아니라면 새로운 객체를 만들어서 준다

### wstring

---

## 자습

- DIP 예시
- 생성자를 정적vs동적 호출
    
    [내용](https://www.notion.so/2a22071f55fa80b18284e56934c16295?pvs=21)
    
- 배열의 이름은 원소의 첫번째 값의 주소다

---

## 교과 시험 공지

- C ~10장 / C++ ~10장
- C 10점 C++ 10점
- 문제 유형 : 단답형(C), 객관식
    - 이론
        - 개념 위주
    - 코딩(잘못된 부분, 결과값)
        - 해당 코드에서 무슨 에러가 나오는지
- 하 3문제
- 중 16문제
- 상 1문제