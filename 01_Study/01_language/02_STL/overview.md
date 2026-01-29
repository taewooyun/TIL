
## 🔷 STL 구성 요소 요약

| 대분류          | 주요 구성 요소 예시                         | 설명                                 |
|------------------|--------------------------------------------|--------------------------------------|
| Containers       | `vector`, `map`, `set`, `deque` 등          | 데이터를 저장하고 관리하는 자료구조 |
| Algorithms       | `sort`, `find`, `accumulate`, `remove` 등  | 컨테이너 데이터를 처리하는 함수들   |
| Iterators        | `begin()`, `end()`, `advance()` 등          | 컨테이너 내부 데이터를 순회하는 도구|
| Function Objects | `less`, `greater`, `function`, 람다         | 함수처럼 동작하는 객체               |
| Utilities        | `pair`, `tuple`, `optional`, `variant` 등   | STL 사용을 보조하는 도구들          |
| Adapters         | `stack`, `queue`, `priority_queue`          | 특정 자료구조를 쉽게 사용할 수 있도록 구성된 어댑터 |

---

## 📦 STL 컨테이너 분류

| 분류                        | 컨테이너 예시                             |
|-----------------------------|-------------------------------------------|
| Sequence Containers          | `vector`, `deque`, `list`, `array`        |
| Associative Containers       | `set`, `map`, `multiset`, `multimap`      |
| Unordered Associative        | `unordered_set`, `unordered_map` 등       |
| Container Adapters           | `stack`, `queue`, `priority_queue`        |

---

## ⚙️ STL 알고리즘 분류

| 범주          | 함수 예시                                      |
|---------------|------------------------------------------------|
| 정렬           | `sort`, `stable_sort`, `nth_element`           |
| 검색           | `find`, `binary_search`, `count`               |
| 수정           | `reverse`, `remove`, `unique`                 |
| 누적/반복       | `accumulate`, `for_each`, `transform`         |
| 조건 판단       | `all_of`, `any_of`, `none_of`                 |

> 사용 시 `<algorithm>` 헤더 필요

---

## 🔁 이터레이터 종류

| 종류             | 예시 컨테이너       | 특징                          |
|------------------|----------------------|-------------------------------|
| 입력 반복자        | `istream_iterator`   | 한 방향 입력                  |
| 출력 반복자        | `ostream_iterator`   | 한 방향 출력                  |
| 전방 반복자        | `forward_list`       | 한 방향 여러 번 순회 가능     |
| 양방향 반복자      | `list`, `set`        | 앞뒤 이동 가능                |
| 임의 접근 반복자   | `vector`, `deque`    | 인덱스 기반 접근              |

---

## 🧩 함수 객체 & 람다

| 항목           | 예시                              | 설명                     |
|----------------|------------------------------------|--------------------------|
| 비교 함수 객체  | `greater<int>`, `less<int>`        | 정렬 기준 변경에 사용     |
| 람다 표현식     | `[](int x){ return x % 2 == 0; }`  | 즉석 함수 선언 가능       |
| std::function | `std::function<void(int)>`         | 함수 객체 래퍼           |

---

## 🔧 유틸리티 도구

| 도구           | 예시                      | 설명                           |
|----------------|---------------------------|--------------------------------|
| `pair`         | `pair<int, string>`        | 두 값 묶기                      |
| `tuple`        | `tuple<int, string, bool>` | 여러 값 묶기                    |
| `optional`     | `optional<int>`            | 값이 없을 수도 있는 객체        |
| `variant`      | `variant<int, string>`     | 여러 타입 중 하나를 담는 객체   |

---