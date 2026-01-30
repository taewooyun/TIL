## 🚩 특징

> 호스트가 다른 3종(리눅스 서버 / 임베디드 리눅스 / 펌웨어) 이 한 레포에 공존하는 전형적인 임베디드 실무형 모노레포
> 

---

## ✅ 전체 전략 요약

> 모노레포 유지 + “레이어 기준 분리”
> 
- Issue → 무엇을 왜 하는지 (요구사항/버그/작업 단위)
- Label → 어느 호스트 + 성격
- Project → 현재 작업 흐름
- Milestone → 시점/릴리즈/단계
- Commit message → 어디를 무엇 때문에 바꿨는지

---

## 📁 1. 전제: 레포 구조 (중요)

```
repo/
 ├─ server/          # 리눅스 서버 (API, DB, MQTT 등)
 ├─ embedded-linux/  # Yocto, BSP, 드라이버, 앱
 ├─ firmware/        # MCU 펌웨어
 ├─ ml/              # YOLO 학습
 └─ docs/
```

---

## 🏷 2. Issue 라벨 설계 (핵심 중의 핵심)

### (1) 호스트 라벨 (필수, 단일 선택)

```
host:server
host:embedded-linux
host:firmware
host:ml
host:cross (여러 개 연동)
```

- 1개 이상 붙이기
    
    → 나중에 필터링, 프로젝트 자동화 가능
    

### (2) 작업 성격 라벨

```bash
type:feature             # 새 기능 추가
type:fix                 # 버그 수정 
type:docs                # 문서 변경
type:style               # 코드 포맷팅
type:refactor            # 리팩토링
type:test                # 테스트 추가/수정
type:chore               # 기타 작업
type:perf                # 성능 개선
```

### 📌 라벨 규칙

- 색상 통일 (host=파랑, type=초록)
- 한 이슈당:
    - host:* 1개
    - type:* 1개
    - 나머지는 선택

---

## 🧩 3. Issue 작성 템플릿 (강추)

```
Template name
🚀 Feature Request

About
새로운 기능 구현을 위한 이슈입니다.

Template Content
## 📌 기능 요약
> 무엇을 왜 만드는지 한 줄로 설명해주세요. (예: 센서 데이터 실시간 모니터링 기능 구현)

## 작업 대상
- Host: server / embedded-linux / firmware
- 관련 모듈:

### 🎯 목표
- [ ] 할 일 1
- [ ] 할 일 2

### ✅ 수락 기준 (Acceptance Criteria)
이슈를 닫기 위해 반드시 충족해야 하는 조건입니다.
- [ ] STM32: 센서 데이터 UART 전송 로직 구현 완료
- [ ] RPi: 파이썬 파싱 스크립트 검증 완료
- [ ] Qt: 실시간 그래프 UI 반영 완료

### 🔗 관련 이슈
Closes #
```

---

## 🧱 4. Project 설계

### 📌 단일 프로젝트

## 컬럼 구성

```
Todo
In Progress
Done
```

---

## 5. Milestone 설계 (시간 기준)

### 단계/릴리즈 마일스톤

### 구조

```
M1: 기본 통신 성공
M2: 기능 연동 완성
M3: 안정화 & 리팩토링
v1.0
```

📌 한 마일스톤 안에:

- server + embedded-linux + firmware 이슈 같이 있음
- → 실제 시스템 개발 흐름 그대로

---

## ✍️ 6. 커밋 메시지 규칙

### 🔥 Conventional Commits + host prefix

```
[host] type: message (issue)
```

### 예시

```
[firmware] feat: add uart packet parser (#23)
[embedded-linux] fix: resolve i2c timing issue (#31)
[server] refactor: split mqtt handler (#40)
[host:cross] feat: end-to-end data flow (#52)
```

### type 목록

| Type | 설명 | 사용 예시 |
| --- | --- | --- |
| `feat` | 새 기능 추가 | YOLO 모델 통합, 새 API 추가 |
| `fix` | 버그 수정 | RTSP 연결 끊김 수정, UART 통신 오류 해결 |
| `docs` | 문서 변경 | README 업데이트, API 명세서 작성 |
| `style` | 코드 포맷팅 | 공백 정리, 세미콜론 추가 (기능 변경 없음) |
| `refactor` | 리팩토링 | 코드 구조 개선 (기능 변경 없음) |
| `test` | 테스트 추가/수정 | 단위 테스트 작성, 통합 테스트 추가 |
| `chore` | 기타 작업 | 빌드 스크립트, 설정 파일, 의존성 업데이트 |
| `perf` | 성능 개선 | 프레임 처리 속도 향상, 메모리 최적화 |

📌 커밋 메시지만 봐도:

- 어느 호스트?
- 무슨 성격?
- 어떤 이슈?
    
    → 다 보이게
    

---

# 🔗 7. Issue ↔ PR ↔ Commit 연결 규칙

- PR 제목:

```
[firmware] feat: uart protocol implementation
```

- PR 설명:

```
Closes #23
```

- 커밋:

```
(#23)
```

👉 이슈 → PR → 커밋 → 머지

👉 추적 완벽

---

# 💼 8. 취준 관점에서 이 구조가 좋은 이유

면접에서 이렇게 말할 수 있음:

> “서버·임베디드 리눅스·펌웨어가 공존하는 모노레포에서
> 

> 호스트 라벨, 커밋 규칙, 마일스톤 기반으로
> 

> 시스템 단위 협업을 설계했습니다.”
> 

이 말 한 방이면:

- 협업 이해도
- 실무 감각
- 시스템 사고
    
    👉 다 보여줌
    

---

### ❕ 요약

- Issue = 작업 단위
- Label = 호스트 + 성격
- Project = 흐름 (1개)
- Milestone = 단계/릴리즈
- Commit = [host] type: msg (#issue)

---