# DAY3

---

## 1. Layout

- 위젯을 담는 그릇, 레이아웃의 구성에 따라 동적으로 위젯들의 크기가 조정된다

| 종류          | 예시                                                                                              | 요약                      |
| ----------- |:-----------------------------------------------------------------------------------------------:| ----------------------- |
| QHBoxLayout | ![](https://velog.velcdn.com/images/ottleh/post/3eb135f5-b7ab-4eaa-8904-c7a3bd7d92d8/image.png) | 가로로 균등하게 배치             |
| QVBoxLayout | ![](https://velog.velcdn.com/images/ottleh/post/2006b52e-fb8a-4741-85a6-662a6c154eea/image.png) | 세로로 균등하게 배치             |
| QGridLayout | ![](https://velog.velcdn.com/images/ottleh/post/c2cc0dd5-60ee-47d6-b671-2adc6e37b4ff/image.png) | 격자 배치 및 병합 가능           |
| QFormLayout | ![](https://velog.velcdn.com/images/ottleh/post/a122a8d4-00a0-4eca-8df4-6d775c61d652/image.png) | 라벨-필드 쌍으로 구성된 폼 전용 레이아웃 |

#### QLayout::setSizeConstraint(QLayout::SizeConstraint constraint)

- Layout의 주요 메서드로, 위젯 계층 사이의 크기에 대한 제약을 설정할 수 있으며 열거형을 매개변수로 받는다

| 열거형                    | 설명                                     |
| ---------------------- | -------------------------------------- |
| `SetDefaultConstraint` | 제약 없음 (기본값). 자유롭게 리사이즈 가능              |
| `SetNoConstraint`      | 제약 완전히 해제. 레이아웃은 위젯 크기에 영향 주지 않음       |
| `SetMinimumSize`       | 부모 위젯의 **최소 크기를** 레이아웃의 최소 크기와 동일하게 설정 |
| `SetFixedSize`         | 부모 위젯의 크기를 **레이아웃의 크기로 고정** (리사이즈 불가)  |
| `SetMaximumSize`       | 부모 위젯의 **최대 크기**를 레이아웃의 최대 크기와 동일하게 제한 |
| `SetMinAndMaxSize`     | 부모의 **최소/최대 크기 모두** 레이아웃 기준으로 제한       |

## 2. DataType & Class in Qt

#### 데이터 타입

| 타입          | 크기     | 설명                                      |
| ----------- | ------ | --------------------------------------- |
| bool        | 8 bit  | true / false                            |
| qint8       | 8 bit  | signed char                             |
| qint16      | 16 bit | signed short                            |
| qint32      | 32 bit | signed int                              |
| qint64      | 64 bit | long long int                           |
| quint8      | 8 bit  | unsigned char                           |
| quint16     | 16 bit | unsigned short                          |
| quint32     | 32 bit | unsigned int                            |
| quint64     | 64 bit | unsigned long long int                  |
| float       | 32 bit | IEEE 754 포맷을 사용하는 floating point number |
| double      | 64 bit | IEEE 754 포맷을 사용하는 floating point number |
| const char* | 32 bit | 문자열 상수를 가리키는 포인터, 마지막에 0 제외             |

- 절대값

- 최소최대

- 소수점

- 최대값

- 반올림

- 64 반올림

| 클래스                | 타입                                                                   |
| ------------------ | -------------------------------------------------------------------- |
| QByteArray         | 바이트 단위의 배열을 지원하기 위한 클래스                                              |
| QByteArrayMatcher  | QByteArray로 구현된 바이트 단위의 배열의 index를 이용해 매칭되는 문자열 이 있는지 찾기 위해 사용되는 클래스 |
| QChar              | 16bit 유니코드 Character를 지원하기 위한 클래스                                    |
| QLatin1Char        |                                                                      |
| <br/>QLatin1String | US-ASCII/Latin-1 인코딩 문자열을 지원하기 위해 제공되는 클래스                           |
| QLocale            | 숫자 표시 방식 혹은 문자 표시 방식을 다양한 언어의 표현 방식에 맞도록 변환하는 클래스입니다.                |
| QString            | 유니코드 문자열 캐릭터를 지원 하는 클래스                                              |
| QStringList        | 문자열 리스트의 집합 클래스                                                      |
| QStringMatcher     | 문자열 상에 매칭되는 문자열을 찾기 위해 제공되는 클래스                                      |
| QStringRef         | size( ), position( ), toString( )과 같은 서브 스트링 래핑 클래스                  |
| QTextStream        | Text기반 WRITE/READ 를 위한 STREAM 기능 제공                                  |
| QDataStream        | Binary 기반 WRITE/READ 를 위한 STREAM 기능 제공                               |

- 문자열 데이터타입
  
  - QByteArray
  - QString
    - == 연산자 비교 가능
  - QStringList
    - Linked List
      - << 연산자 제공
      - .join("구분자")
  - QTextStream
    - 대량의 텍스트 데이터(파일)
    - 버퍼 보유

#### 데이터 클래스

| 클래스         | 설명                                                                |
| ----------- | ----------------------------------------------------------------- |
| QBitArray   | 비트 연산(AND, OR, XOR, NOT)을 제공하기 위한 bit Array                       |
| QMargins    | left, top, right, bottom 사각형의 각 Marin을 처리하기 위한 클래스                |
| QPoint      | X, Y, Z 값을 처리하기 위해 제공하는 클래스                                       |
| QQuaternion | 벡터 및 스칼라로 구성된 Quaternion을 처리하기 위한 클래스                             |
| QRect       | 사각형의 left (qint32), top (qint32), right (qint32), bottom (qint32) |
| QRegExp     | 정규화 표현식을 처리하기 위한 클래스                                              |
| QRegion     | Painter 상에서 클립보드 영역을 정의하기 위해 사용                                   |
| QSize       | 넓이와 높이를 저장 할 수 있는 클래스                                             |
| QVariant    | void 타입으로 저장 할 수 있는 union 형태의 클래스                                 |
| QVector2D   | 2차원 공간에서 Vector 또는 vertex를 나타내기 위한 클래스                            |
| QVector3D   | x, y, z 3개의 좌표를 사용할 수 있는 클래스                                      |
| QVector4D   | 4차원 공간에서 Vector 또는 vertex를 나타내기 위해 사용.                            |

### 컨테이너 클래스

| 클래스                | 설명                                                       |
| ------------------ | -------------------------------------------------------- |
| QHash<Key, T>      | Hash 테이블 기반의 Dictionary를 제공하는 템플릿 클래스                    |
| QMap<Key, T>       | Binary Search Tree기반 템플릿 클래스                             |
| QPair<T1, T2>      | Pair(쌍)로 존재하는 아이템 데이터를 처리 클래스.                           |
| QList<T>           | List 형태의 값을 다루기 위해 제공하는 템플릿 클래스                          |
| QLinkedList<T>     | 링크드리스트를 제공하기 위한 템플릿 클래스                                  |
| QVector<T>         | 동적인 QVector 배열을 다루기 위해 제공되는 클래스                          |
| QStack<T>          | Stack 기반의 push( ), pop( ) 등을 사용하기 위해 제공                  |
| QQueue<T>          | FIFO 구조의 데이터 조작을 위해 제공                                   |
| QSet<T>            | 해시 기반의 빠른 검색을 위해 제공되는 클래스                                |
| QMap<Key, T>       | Key값에 의해 Mapping 되는 데이터를 하나의 조합으로 연결되어 Dictionary를 제공한다. |
| QMultiMap<Key, T>  | QMap으로부터 상속받은 클래스이며 다중 Mapping 값을 사용할 수 있다.              |
| QMultiHash<Key, T> | QHash 로부터 상속받은 클래스이며 다중 Mapping 값을 이용해 헤쉬를 사용할 수 있다.     |

## 3. Signal & Slot

- Qt에서 이벤트를 처리하기기 위한 메커니즘

- 추가 설명

## 4. Qt Designer를 이용한 GUI 설계

- ui->setupUi(QWidget); 로 MainWidget과 연결

- .ui 에서 GUI로 생성된 컴포넌트의 Object Name으로 코드상에서 접근

- ui파일 변경하거나 추가하려면?

## 5. Dialog

- 종류

| 종류              | 설명                              |
| --------------- | ------------------------------- |
| QInputDialog    | 사용자로부터 값을 입력 받을 수 있는 다이얼로그      |
| QColorDialog    | 특정 컬러를 선택할 수 있는 다이얼로그           |
| QFileDialog     | 파일 또는 디렉토리를 선택하는 GUI 인터페이스를 제공. |
| QFontDialog     | 폰트를 선택하기 위한 다이얼로그               |
| QProgressDialog | 퍼센트와 같은 진행사항을 보여주기 위한 다이얼로그     |
| QMessageBox     | 모달 방식의 다이얼로그                    |

#### QFileDialog::Options

| 상수                                 | 설명                             |
| ---------------------------------- | ------------------------------ |
| QFileDialog::ShowDirsOnly          | 디렉토리만 표시                       |
| QFileDialog::DontResolveSymlinks   | 심볼릭 링크를 표시하지 않기 위해 사용          |
| QFileDialog::DontConfirmOverwrite  | 덮어쓰기 할 때 경고 메시지를 표시하지 않기       |
| QFileDialog::DontUseNativeDialog   | 시스템 기본 파일 다이얼로그를 사용하지 않기 위해 사용 |
| QFileDialog::ReadOnly              | 읽기 모드로 파일 다이얼로그를 사용            |
| QFileDialog::HideNameFilterDetails | 필터를 이용해 파일을 감추기 위해 사용          |

#### QMessageBox

- 모달 방식의 다이얼로그

| 상수                           | 값          | 설명                |
| ---------------------------- | ---------- | ----------------- |
| QMessageBox::Ok              | 0x00000400 | OK 버튼             |
| QMessageBox::Open            | 0x00002000 | 파일 열기 버튼          |
| QMessageBox::Save            | 0x00000800 | 저장 버튼             |
| QMessageBox::Cancel          | 0x00400000 | 취소 버튼             |
| QMessageBox::Close           | 0x00200000 | 닫기 버튼             |
| QMessageBox::Discard         | 0x00800000 | 저장하지 않고 버리기 버튼    |
| QMessageBox::Apply           | 0x02000000 | APPLY 버튼          |
| QMessageBox::Reset           | 0x04000000 | RESET 버튼          |
| QMessageBox::RestoreDefaults | 0x08000000 | 다시 저장하기 버튼        |
| QMessageBox::Help            | 0x01000000 | 도움말 버튼            |
| QMessageBox::SaveAll         | 0x00001000 | 모두 저장하기 버튼        |
| QMessageBox::Yes             | 0x00004000 | YES 버튼            |
| QMessageBox::YesToAll        | 0x00008000 | 모두 YES 적용하기 버튼    |
| QMessageBox::No              | 0x00010000 | NO 버튼             |
| QMessageBox::NoToAll         | 0x00020000 | 모두 NO 적용하기 버튼     |
| QMessageBox::Abort           | 0x00040000 | 중지 버튼             |
| QMessageBox::Retry           | 0x00080000 | 재시도 버튼            |
| QMessageBox::Ignore          | 0x00100000 | Ignore(무시) 버튼     |
| QMessageBox::NoButton        | 0x00000000 | An invalid button |

#### Custom Dialog

- emit, signal, slot 관계에 대한 개념

- 멤버 직접 호출로 슬롯 호출 시 파라미터 어떻게 사용하는지

- 

## 6. File I/O

#### QFile 클래스

- QFile.open(QIODevice::OpenMode)

- OpenMode 종류

| Constant              | 값             | 설명                                                     |
| --------------------- | ------------- | ------------------------------------------------------ |
| QIODevice::NotOpen    | 0x0000        | 파일을 열지 않을 때 사용                                         |
| QIODevice::ReadOnly   | 0x0001        | 읽기 전용 모드로 사용                                           |
| QIODevice::WriteOnly  | 0x0002        | 쓰기 전용 모드로 사용                                           |
| QIODevice::ReadWrite  | Read \| Write | 읽기 / 쓰기 모드를 함께 사용                                      |
| QIODevice::Append     | 0x0004        | 파일 끝에 추가하기 위해 사용                                       |
| QIODevice::Truncate   | 0x0008        | 만약 이전에 Open된 파일이 있다면 새로운 연결을 위해 이전에 사용된 파일을 삭제.        |
| QIODevice::Text       | 0x0010        | TEXT모드로 읽을 때 마지막에 ‘\n’을 사용. MS윈도우인에서는 ‘\r\n’을 마지막에 사용. |
| QIODevice::Unbuffered | 0x0020        | 버퍼를 사용하지 않고 디바이스를 바로 사용                                |

파일 입출력 실습

## 7. 프로퍼티

개념 의미 예제

## 8. Model and View

- View 클래스와 매핑 되어 있는 Model 클래스를 사용하여 해당 Model이 지원하는 데이터 타입을 넣기만 하면 View에서 GUI를 구현해줌

### Model

#### QAbstractItemModel

- QAbstractListModel
  
  - QStringListModel
    
    - QString 타입의 단순 데이터 리스트를 다룸
    
    - setStringList

- QStandardItemModel
  
  - 테이블 또는 트리형태와 같은 데이터를 다룸
  
  - QStandardItemModel(4, 4)
  
  - setItem

- QFileSystemModel
  
  - 파일 시스템으로 부터 읽어온 파일과 디렉토리를 다룸
  
  - setRootPath(QDir::currentPath())

- QAbstractTableModel
  
  - 데이터베이스 쿼리로 부터 가져온 데이터를 다룸
  
  - QSqlQueryModel
    
    - SQL 데이터를 다룸
    
    - setQuery("")
    
    - setHeaderData(int, Qt::, tr)
    
    - with QTableView
  
  - QSqlTableModel
    
    - SQL 테이블을 다룸
  
  - QSqlRelationalTableModel
    
    - 

### View

- QTreeView
  
  - QFileSystemModel
  
  - 

- QListView
  
  - QFileSystemModel
  
  - QStringListModel
  
  - 

- QTableView
  
  - QStandardItemModel
  
  - 

---

### memo

- ascii / unicode / utf-8
- 시그널을 직접 구현해서 호출 할 함수를 넘겨주는것과 함수에서 호출하는것과 차이
  - 호출할 함수를 인자로 넘겨주기 위해 사용하는건가
- 위젯 실습 전체코드 집어넣기
- TIL 태그 달기
- View에는 모든 Model을 적용시킬 수 있는가 -> 테스트 해보기
- 메모리 스토리지 구성(stack/heap/.data/.bss/.text)
- 스마트포인터가 어디에서 구현되는가
- 
