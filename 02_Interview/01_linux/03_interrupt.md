### 인터럽트에서 지연작업을 처리하는 방법
“인터럽트 컨텍스트에서는 sleep이 불가능하기 때문에 ISR에서는 최소 처리만 수행하고, 실제 지연 작업은 workqueue나 threaded IRQ처럼 커널 스레드 기반의 Bottom Half로 위임하여 처리합니다.”

### kthread와 workqueue의 차이
“kthread는 개발자가 직접 관리하는 전용 커널 스레드이고, workqueue는 커널이 관리하는 스레드 풀에 작업을 위임하는 방식입니다. ISR에서 미룬 작업이나 이벤트 기반 처리에는 workqueue가 적합하고, 지속적으로 실행되어야 하는 작업에는 kthread가 적합합니다.”