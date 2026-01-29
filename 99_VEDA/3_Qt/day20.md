# DAY 5

---

## Qt Graphics View Framework

- 어플리케이션에서 제공되는 컨텐츠가 모니터보다 큰 영역(지도, 건축 도면, 설계도 등)일 때 쉽게 구현할 수 있도록 제공
- 내부 구현 알고리즘으로 BSP Tree를 사용하기 때문에 수 많은 오브젝트를 빠르게 표시할 수 있다

| 요소                          | 설명                                                               |
| --------------------------- | ---------------------------------------------------------------- |
| QGrphicsView                | 시각적으로 표시가 가능한 영역. 예를 들어 GUI에서 특정 영역. 이 클래스는 GUI 상에서 실제 크기의 영역이다. |
| QGraphcisScene              | QGraphcisScene 클래스는 논리 적인 영역 이다. QGrphicsView                    |
| 영역 안에 표시된다.                 |                                                                  |
| QGraphicsItem               | QGraphcisScene 클래스 오브젝트 상에 표시된다. 맵                               |
| 상에 표시되는 오브젝트와 같은 개념으로 사용된다. |                                                                  |

![](C:\Users\2-21\AppData\Roaming\marktext\images\2025-11-14-09-14-18-image.png)

### QGraphcisScene

- setScene

- setRenderHint

- setCacheMode

- setViewportUpdateMode

- setDragMode

- resize

- show

- scene
  
  - scene()->collidingItems(this) : 겹치는지 확인 

### QGraphicsItem

- signal
  
  - Advance : QGraphicsScene이 업데이트되면 호출
  
  - mouseModeEvent : QGraphicsScene 내의 특정 GraphicsItem을 마우스로 드래그 하기
    
    - setFlag로 설정되어 있는 아이템이 드래그 될 때 호출

- setFlags

- 

## Animation Framework and State Machine

- GUI상에서 화면 전환 시 부드러운 화면 전환과 같은 애니메이션 요소를 사용하기 위해 제공되는 Framework

- 투명, 이동, 확대/축소 등과 같은 애니메이션 요소를 사용

#### Easing Curves

- 시간에 따른 좌표 값을 타입에 따라 조정할 수 있다

- Linear, InQuad, OutQuad, InOutQuad 등

#### State Machine

- 애니메이션을 위해 계산 된 위젯의 상태(위치, 투명도 등)를 한번에 변경할 때 사용

- animation에서 병렬 실행하는 기능을 제공하지만 수십 개의 상태를 변경해야할 때 더 효과적일 수 있다

- 

#### Animation Group

- 그룹화를 통해 애니메이션 요소를 동시 또는 순차적으로 실행할 수 있다

- QSequentialAnimationGroup

- QParallelAnimationGroup

- 

#### Transition

- 대상의 상태(실행전/실행후)가 변경되는 애니메이션의 단위
  
  ![](C:\Users\2-21\AppData\Roaming\marktext\images\2025-11-14-10-41-38-image.png)

#### Qt Chart (6.10 deprecated)

- QLineSeries

- QAreaSeries

- QBarSeries

- QPieSeries

#### Qt Data Visualization (6.10 deprecated)

- QBar3DSeries
  
  - 막대 표시

- Q3DScatter
  
  - 지점 표시

- Q3DSurface
  
  - 단면도 표시

## Multimedia

Qt는 멀티미디어를 지원한다. 

마이크로 입력된 음원을
100 Millisecond Seconds 단위로 컴퓨터 네트워크 망을 경유해 송신하고, 수신 받은 컴
퓨터에서 이 음원을 재생하는 응용 어플리케이션을 구현해야 한다고 한다면
단순히 음악 파일을 재생하는 API로는 구현하기 어렵다. 따라서 Qt 에서 제공하는
Multimedia 모듈은 단순한 기능부터 좀더 복잡한 멀티미디어 응용 어플리케이션을 보
다 쉽게 구현할 수 있는 장점이 있다.

- Audio

- Video

- Camera

### Audio

- Sample rate
  
  - 파형을 2진수 디지털로 변환한 특정 값
  
  - 52.3KHz or 22.4KHz
  
  - ?? 2배는 해야한다

- Bit rate
  
  - 1초동안 사용한 Bit수, bps 단위를 사용한다
  
  - 96Kbps, 128Kbps, 192Kbps
  
  - ?? quantization

- PCM sampling
  
  - 원본 소스
  
  - pcm audio file은 header가 없이 raw data만 저장한 파일이다.**  
    **따라서 pcm 포맷으로 저장된 오디오는 별도로 오디오에 대한 정보를 가지고 있지 않으면 제대로 play할 수 없다.**
  
  - 오디오 드라이버에서 오디오 데이터를 캡쳐했다면, 당연히 header가 없는 pcm 포맷이며 이때 오디오 드라이버가 어떤 상태(sampling rate, bit size, endian, channels)로 동작 중이 였는지에 따라 pcm 포맷을 해석해야 한다. 만일 데이터가 RIFF 포맷이라면 Little endian 형식이므로, wav header만 붙여주면 wav 오디오의 play가 가능해진다.**
  
  - 따라서 big endian 이라면 header 추가 뿐만 아니라 오디오 데이터에 대한 endian 변환까지 해야 한다.**
  
  - PCM 파일 크기는 “PCM 초당 데이터 처리
    량 * 재생 시간 / 8” 을 하면 PCM 파일 크기를 계산할 수 있다

### Video

- QVideoWidget

- 

---

### memo

- 3d로 구현된 화면을 평면으로 만들고 카메라 시야에 들어오는 이미지를 전체적으로 보여줌

- 교육 내용을 습득한 결과물이기 때문에 최대한 다 써보기

- 컴포넌트마다 커스텀이 되는지

- QAbstractSeries - chart

- Qt 도큐먼트 출처 포함

- 
