# DAY 1

---

## What is "Qt" ?

핀란드의 Qt Group이 1990년대 부터 개발해온 C++ 기반 크로스플랫폼 프레임워크

데스크탑·모바일·임베디드 환경을 지원하는 통합 개발 도구

### Target Platform

| 플랫폼                                   | 출력 파일 형식                | 예시                                          |
| ------------------------------------- | ----------------------- | ------------------------------------------- |
| **Windows**                           | `.exe`, `.dll`          | Visual Studio, MinGW 기반                     |
| **Linux**                             | 실행 파일 (ELF)             | `./app`                                     |
| **macOS**                             | `.app` (번들 구조)          | macOS 전용 GUI 앱                              |
| **Android**                           | `.apk`, `.aab`          | Qt for Android                              |
| **iOS**                               | `.ipa`, `.app`          | Qt for iOS                                  |
| **WebAssembly (WASM)**                | `.html`, `.wasm`, `.js` | 브라우저에서 Qt 앱 실행                              |
| **Embedded (예: STM32, Raspberry Pi)** | `.elf`, `.bin`          | Qt for Embedded Linux, Qt Quick Ultralite 등 |

### Build System

| 빌드 시스템    | 설명                                   |
| --------- | ------------------------------------ |
| **qmake** | Qt 고유의 전통적인 빌드 시스템 (`.pro` 파일 기반)    |
| **CMake** | 현대 Qt(특히 Qt 6 이후) 표준. 범용 오픈소스 빌드 시스템 |
| **Qbs**   | 과거 실험적 Qt 빌드 시스템 (현재 비권장)            |

### Output Type

| 유형                                   | 결과물                         | 설명                      |
| ------------------------------------ | --------------------------- | ----------------------- |
| **Application (Qt Widgets / Quick)** | 실행 파일 (`.exe`, `.app`)      | 일반 데스크탑/모바일 앱           |
| **Library (Static / Shared)**        | `.lib`, `.a`, `.dll`, `.so` | 모듈화된 라이브러리              |
| **Plugin**                           | `.dll`, `.so`               | Qt 확장용 플러그인 (예: QML 모듈) |
| **Console Application**              | 실행 파일                       | GUI 없는 CLI 프로그램         |
| **Test Project**                     | 실행 파일                       | `QtTest` 기반 단위 테스트용     |
| **QML Module**                       | `.qmltypes`, `.so`          | QML에서 import 가능한 모듈     |

### 활용 분야

- **데스크탑 소프트웨어**: Photoshop Elements, VirtualBox, Maya 등

- **임베디드 기기 UI**: 자동차 인포테인먼트, 산업용 패널, 의료기기

- **모바일 앱**: 크로스플랫폼 앱 개발(Android/iOS)

- **IoT 및 HMI (Human-Machine Interface)**: Qt for Device Creation, Qt Quick Ultralite 등

## Build System 이란?

> 빌드 시스템은 “프로젝트의 설계도(CMakeLists.txt, .pro)”를 읽어 컴파일러와 링커를 자동으로 호출하고, 플랫폼별로 일관된 빌드 결과물을 생성하는 **자동화된 엔진**

### 주요 역할

| 구분                                            | 설명                                                                                        |
| --------------------------------------------- | ----------------------------------------------------------------------------------------- |
| **의존성 관리 (Dependency Management)**            | 여러 소스 파일 간의 관계를 자동으로 추적해 수정된 파일만 다시 컴파일하도록 지시 <br/>→ `main.cpp`만 수정하면 관련된 부분만 다시 빌드       |
| **컴파일 및 링크 자동화 (Build Automation)**           | 여러 명령(`gcc`, `link`, `ar` 등)을 수동으로 입력하지 않아도 자동으로 실행되도록 함<br/> → `Makefile` 한줄로 프로젝트 빌드 가능 |
| **플랫폼별 설정 관리 (Cross-Platform Configuration)** | OS나 컴파일러에 따라 다른 옵션·경로를 자동으로 처리<br/>→ Windows, Linux, macOS용 빌드를 쉽게 전환                     |
| **외부 라이브러리 연동 (Library Integration)**         | Qt, OpenCV, Boost 같은 외부 라이브러리를 자동으로 임포트                                                   |
| **빌드 아티팩트 관리 (Artifacts Management)**         | 결과물(exe, dll, so, lib 등) 및 중간 산출물(obj, o, pch 등)을 정리하고 경로를 일관성 있게 유지                      |
| **테스트 및 배포 자동화 (Optional)**                   | 단위 테스트 실행, 패키징, 설치 스크립트 실행 가능                                                             |

#### 흐름 예시

```shell
CMakeLists.txt → (CMake 실행) → Makefile/Ninja 파일 생성 → 빌드 도구(make/ninja) → 컴파일러(g++, clang 등) 호출 → 실행 파일 생성
```

## 실습 환경

- Target : `Qt Widget Application(Desktop)`

- Build System : `Cmake for Qt 6`

- Base class : `QWidget`

#### Cmake 프로젝트 기본 구조

```perl
package/                  # 프로젝트 루트 디렉터리
├─ CMakeLists.txt         # CMake 설정 파일 (프로젝트 전체 빌드 설정 진입점)
│
└─ project/               # 실제 코드와 리소스가 포함된 폴더
    ├─ Forms/             # Qt Designer에서 만든 UI 폼 파일 저장
    │   └─ widget.ui      # Qt 위젯 배치 정보 (.ui XML 형식)
    │
    ├─ Header Files/      # 헤더 파일 (.h) — 클래스 선언, 인터페이스 정의
    │   └─ widget.h       # Widget 클래스의 선언부 (signals/slots 포함)
    │
    └─ Source Files/      # 소스 파일 (.cpp) — 실제 구현 코드
        ├─ main.cpp       # 프로그램 진입점 (QApplication, 메인 윈도우 실행)
        └─ widget.cpp     # Widget 클래스의 구현부 (이벤트 처리, UI 로직 등)
```

#### CMakeLists.txt

```cmake
# CMake 최소 요구 버전 지정
cmake_minimum_required(VERSION 3.16)

# 프로젝트 이름, 버전, 사용 언어 설정
project(daily_project VERSION 0.1 LANGUAGES CXX)

# Qt 자동화 설정
# UIC (User Interface Compiler): .ui 파일 자동 변환
set(CMAKE_AUTOUIC ON)
# MOC (Meta-Object Compiler): signals/slots 등 Qt 확장 문법 자동 처리
set(CMAKE_AUTOMOC ON)
# RCC (Resource Compiler): .qrc 리소스 파일 자동 처리
set(CMAKE_AUTORCC ON)

# C++ 표준 설정 (C++17 필수)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt 버전에 따라 Widgets 모듈 찾기 (Qt5 또는 Qt6 호환)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 프로젝트에 포함될 소스 목록 정의
set(PROJECT_SOURCES
    main.cpp       # 진입점
    widget.cpp     # 위젯 클래스 구현부
    widget.h       # 위젯 클래스 헤더
    widget.ui      # Qt Designer로 만든 UI 파일
)

# Qt 6 이상 버전일 경우 qt_add_executable() 사용
# (Qt6에서는 qt_add_executable을 통해 자동 처리)
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(daily_project
        MANUAL_FINALIZATION      # 수동으로 qt_finalize_executable() 호출 필요
        ${PROJECT_SOURCES}
    )

# Qt 5 이하 버전용 (Qt 6 이전 버전에서는 add_executable/add_library 사용)
else()
    if(ANDROID)
        # Android 빌드일 경우 공유 라이브러리(.so)로 빌드
        add_library(daily_project SHARED
            ${PROJECT_SOURCES}
        )
        # ANDROID_PACKAGE_SOURCE_DIR 경로 설정 예시 (주석)
        # set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        # 일반 데스크탑 환경 빌드 (Windows/Linux/macOS)
        add_executable(daily_project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Qt 위젯 모듈과 링크 (QtCore, QtGui, QtWidgets 등)
target_link_libraries(daily_project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# macOS/iOS용 번들 ID 설정 (앱 서명 및 배포 시 필요)
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.daily_project)
endif()

# 타겟 속성 설정
# - macOS 번들 식별자
# - 버전 정보
# - GUI 실행 파일 여부
set_target_properties(daily_project PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE             # macOS .app 번들 생성
    WIN32_EXECUTABLE TRUE          # Windows 콘솔창 없는 GUI 실행 파일
)

# 설치 경로 설정
include(GNUInstallDirs)
install(TARGETS daily_project
    BUNDLE DESTINATION .           # macOS 번들 설치 경로
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}  # Linux용 라이브러리 경로
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}  # 실행 파일 설치 경로
)

# Qt6에서는 qt_finalize_executable()로 빌드 마무리 단계 수행
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(daily_project)
endif()
```

---

### 실습 프로젝트

#### 화면 구성

![](C:\Users\2-21\Desktop\1.png)

#### 구현 내용

- Label
  
  - 선택된 non exclusive 버튼(Programming, Qt, OS) 내용 출력

- Button
  
  - Label text 설정 및 초기화

- CheckBox

- ButtonGroup
  
  - exclusive 그룹
  
  - non exclusive 그룹

#### 주요 코드

- widget.h

```cpp
class Widget : public QWidget
// ...
private:
    Ui::Widget *ui;
    QButtonGroup *m_chk_group[2]; // 버튼 그룹 생성
    QCheckBox *m_btn_exclusive[3]; // 그룹 0 체크박스 생성
    QCheckBox *m_btn_non_exclusive[3]; // 그룹 1 체크박스 생성

private slots:
    void slot_clicked_1(); // 버튼 리스너 생성
    void slot_clicked_2();
    void slot_check_changed_1(); // 체크박스 리스너 생성
//...
```

- widget.cpp

```cpp
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
// ...
    QString str1[3] = {"Game", "Office", "Develop"}; // 버튼 그룹 0 목록
    QString str2[3] = {"P&rogramming", "Q&t", "O&S"}; // 버튼 그룹 1 목록
    int xpos = 30;
    int ypos = 30;
    m_chk_group[0] = new QButtonGroup(this);
    m_chk_group[1] = new QButtonGroup(this);
    for(int i = 0 ; i < 3 ; i++)
    {
        m_btn_exclusive[i] = new QCheckBox(str1[i], this);
        m_btn_exclusive[i]->setGeometry(xpos, ypos, 120, 30);
        m_chk_group[0]->addButton(m_btn_exclusive[i]); // 버튼 생성
        connect(m_btn_exclusive[i], SIGNAL(clicked()), this, SLOT(slot_check_changed_1())); // 리스너 등록

        m_btn_non_exclusive[i] = new QCheckBox(str2[i], this);
        m_btn_non_exclusive[i]->setGeometry(xpos + 120, ypos, 120, 30);
        m_chk_group[1]->addButton(m_btn_non_exclusive[i]); //버튼 생성

        ypos += 40;
    }
    m_chk_group[0]->setExclusive(true); // 단일 선택 설정 (radio button)
    m_chk_group[1]->setExclusive(false); // 다중 선택 설정

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(slot_clicked_1())); // pushButton이 clicked가 발생되면 slot_clicked를 실행
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(slot_clicked_2()));
// ...

void Widget::slot_check_changed_1()
{
    for(int i = 0 ; i < 3 ; i++) {
        if(m_btn_exclusive[i]->checkState())
        {
            qDebug("checkbox %d selected ", i+1); // 선택 버튼 출력
        }
    }
}

void Widget::slot_clicked_1()
{
    QString str = "";
    for (auto btn : m_chk_group[1]->buttons()) { // 체크 된 버튼 목록 확인
        if(btn->isChecked()) {
            str += btn->text() + ", ";
        }
    }
    str.replace("&&", "&");
    str.remove('&'); // 특수 기호 제거
    if(str != "") ui->label_1->setText(str);
}

void Widget::slot_clicked_2()
{
    m_chk_group[0]->setExclusive(false); // 선택 초기화를 하기 위해 단일 선택 옵션을 해제 해야한다
    for(auto group: m_chk_group){       // 선택 된 버튼 초기화
        for(auto btn: group->buttons())
            btn->setChecked(false);
    }
    m_chk_group[0]->setExclusive(true); // 

    ui->label_1->setText("SELECTED SKILLS"); // label 초기화
}
```

---

##### [전체 소스 코드]([qt_practice/TIL/day1/project at main · taewooyun/qt_practice · GitHub](https://github.com/taewooyun/qt_practice/tree/main/TIL/day1/project))

---
