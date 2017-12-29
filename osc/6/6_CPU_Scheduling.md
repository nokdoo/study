# CPU Scheduling
---

CPU scheduling은 multiprogrammed operating system의 기초이다. 프로세스간 cpu 스위칭을 통해 os는 컴퓨터를 더 생산적으로 만들 수 있다. 이번 장에서 기본적인 CPU-scheduling의 개념을 소개하고 몇 가지 CPU-scheduling 알고리즘을 제시한다. 또한 특정 시스템에 대한 알고리즘을 선택하는 문제를 고려한다.

4장에서 프로세스 모델에 대한 스레드를 설명했다. 스레드를 지원하는 os에서 스레드는 프로세스가 아닌 kernel-level thread이다. 이것은 os에서 실제로 스케쥴되는 스레드이다. 하지만 프로세스 스케쥴링과 스레드 스케쥴링은 종종 같은 의미로 사용된다. 이번 장에서는 일반적인 스케쥴링 개념을 설명할 때 *process scheduling*을 사용하고, 특정 스레드의 발상을 참조할 때 *thread scheduling*을 사용한다.

	장 목표
	- multiprogrammed os의 기초인 CPU scheduling을 소개한다.
	- 다양한 CPU-scheduling 알고리즘을 설명한다.
	- 특정 시스템을 위한 CPU-scheduling 알고리즘을 선택하는 평가 기준을 논의한다.
	- 몇 가지 os의 스케쥴링 알고리즘을 확인한다.
