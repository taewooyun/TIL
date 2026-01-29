# DAY 4

---

## 1. QPainter::

- Qt에서 Text, 선, 도형을 표시할 수 있게 해주는 클래스

- Gradents, Transformation, Composition등과 같은 효과를 적용시킬 수 있다

- **QWidget::paintEvent(QPaintEvent)**
  
  - 위젯을 그릴 때 자동으로 호출되는 함수
  
  - 오버라이딩으로 재정의하여 QPainter와 함께 임의로 그림을 그릴 수 있다
  
  - 호출은 임의로 하지 않고 update() 함수로 콜백의 형태로 호출된다

- 주요 메서드
  
  - .begin(QWidget) : 
  
  - .setPen(Qt::blue) <- enum? : 
  
  - .drawLine : 선 그리기
  
  - .drawRect : 사각형 그리기
  
  - .drawRoundedRect(QRect, int, int) : 모서리가 둥근 사각형 그리기
  
  - .drawPolyline(QPoint[], count) : 포인트 지점을 선으로 그리기
  
  - .drawPolygon(QPoint[], count) : 포인트 지점으로 도형 그리기
  
  - .drawText()
  
  - .drawEllipse
  
  - .end() :

- 각 메서드의 주요 옵션들 정리

- 

#### QPen::

- .setPen

- .setStyle

- .joinStyle

- 

#### QBrush::

- 생성자
  
  - QPixmap
  
  - QGradient

- color

- pattern

- 

#### QGradient::

- QLinearGradient::
  
  - setSpread
    
    - PadSpread
    
    - RepeatSpread
    
    - ReflectSpread

- QRadialGradient::
  
  - setSpread
    
    - PadSpread
    
    - RepeatSpread
    
    - ReflectSpread

- QConicalGradient::
  
  - 

#### QTransform::

- 기하학적 변형

- 

#### QImage::

- setCompositionMode와의 관계

#### Custom Button

- #### Non Client Area

- OS에서 제공되는 기본 창에 대한 GUI
  
  - 윈도우 바
  
  - FramelessWindowHint?

#### QPainter를 이용한 Chromakey 구현

- ## 2. Timer

- SIGNAL
  
  - timeout
  
  - 

- SingleShot

- 예제에서 스타트하고 좀 오래걸림

- QDateTime 사용법

- 

---

### memo

- 전처리 지시자 활용법 확인
  
  - #if 0
  - #endif

- 중간중간 궁금했던걸 회고에 채워넣기

- 시그널 슬롯 델리게이트

- 커스텀 버튼에서 시그널 슬롯 매개변수 받기

- 
