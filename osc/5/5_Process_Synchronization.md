# Process Synchronization
---

*Cooperating process*는 시스템에서 실행되는 다른 프로세스에 영향을 주거나 받을 수 있다. cooperating process는 logical address space를 공유하거나, 파일 또는 메세지를 통해서만 데이터를 공유할 수 있다. 전자의 경우, 4장에서 논의한 것처럼 스레드를 통해서 형성된다. 하지만 데이터를 공유하기 위한 동시 접근은 데이터를 일관성 없게 만든다. 이번 장에서는, logical address space를 공유하는 cooperating process의 순차적 실행을 보장하기 위한 다양한 메커니즘을 논의함으로써 데이터의 일관성을 관리한다.

---
이번 장 목표
 - critical-section problem 소개 - 공유된 데이터의 일관성을 보장하기 위해 솔루션이 사용됨.
 - critical-section problem의 소프트웨어, 하드웨어 솔루션을 제시.
 - 몇 가지 고전적인 process-synchronization problem 확인.
 - process-synchronization problem을 해결하기 위해 사용되는 몇 가지 툴을 탐구.

