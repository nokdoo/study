# 4 Threads
---
3장에서 소개된 프로세스 모델은 프로세스는 single thread of control을 가진 실행 프로그램이라 가정했다. 그러나 사실상 모든 현대 os는 프로세스가 multiple threads of controll을 가지는 기능을 제공한다. Pthreads. Windows. JAva thread libraries에 대한 API의 논의를 포함하여, 이번 장에서는 멀티스레드 컴퓨터 시스템과 관련한 개념을 소개한다. 멀티스레드 프로그래밍과 os 설계에서의 그 효과에 관련된 이슈를 살펴볼 것이다. 마지막으로 윈도우즈와 리눅스 os가 kernel level에서 스레드를 어떻게 지원하는지 알아볼 것이다.

---
이번 장 목표
- 스레드의 개념 소개 - 멀티스레드 컴퓨터 시스템의 기반을 형성하는 cpu 사용의 기본 단위
- Pthreads, Windows, Java thread libraries의 API 논의
- 암시적인 스레딩을 제공하는 전략 탐구
- 멀티스레딩 프로그래밍과 관련된 이슈 확인
- 윈도우즈와 리눅스의 스레드를 위한 지원 탐구
