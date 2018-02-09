# Practice Exercises
---

#### 6.1 CPU 스케줄링 알고리즘은 스케줄링 되는 프로세스의 실행 순서를 결정한다. 하나의 processor에 스케줄링 될 *n*개의 프로세스가 있다면 몇 가지의 스케줄링이 가능한가? *n*에 대한 공식으로 나타내라.
*n!*

#### 6.2 preemptive 스케줄링과 nonpreemptive 스케줄링의 차이점을 설명하라.
preemptive 스케줄링은 프로세스가 실행 도중에 인터럽트되는 것을 허용하고 CPU를 다른 프로세스에 할당한다. nonpreemptive 스케줄링은 프로세스가 CPU burst 내에 완료될 때만 CPU의 제어를 포기하는 것을 보장한다.

#### 6.3 다음의 프로세스가 실행을 위해서 각각 표시된 시간에 도착했다고 가정하자. 각 프로세스는 나열된 시간의 총 시간 동안 실행될 것이다. nonpreemptive 스케줄링을 사용하여 질문들에 답하라. 모든 결정은 그 결정이 이루어진 시간에 얻을 수 있는 정보에 기초해야 한다.

	Process			Arrival Time			Burst Time
	P1				0.0						8
	P2				0.4						4
	P3				1.0						1

a. FCFS 스케줄링 알고리즘을 사용하는 이 프로세스들의 평균 turnaround time은 무엇인가?<br/>
10.53

b. SJF 스케줄링 알고리즘을 사용하는 이 프로세스들의 평균 turnaround time은 무엇인가?<br/>
9.53

c. 성능 향상을 위해서 SJF 알고리즘을 사용한다고 해보자. 하지만 시간 0일 때 곧 도착할 다른 두 개의 프로세스를 알지 못하기 때문에 프로세스 P1을 실행시킨다. 처음 1 unit에 대해 CPU가 idle 상태라면 SJF 스케줄링이 사용된다. 평균 turnaround time을 계산하라. 프로세스 P1과 P2가 idle time을 기다리고 있기 때문에 대기 시간이 증가할 수 있음을 기억하라. 이 알고리즘은 future-knowledge scheduling으로 알려져있다.

turnaround time은 완료시간 - 도착 시간임을 기억하라. 따라서 turnaround time을 계산하기 위해서 도착 시간을 빼야한다. 도착 시간을 빼는 것을 잊어버리면 FCFS는 11이다.

#### 6.4 multilevel queueing system의 다른 레벨에서 다른 time-quantum을 갖는 것에는 어떤 이점이 있는가?
에디터와 같은 interactive 프로세스처럼 더 자주 서비스를 해야 하는 프로세스는 small time quantum과 함께 큐에 위치할 수 있다. 자주 서비스 되지 않아도 되는 프로세스는 large time quantum과 함께 큐에 위치할 수 있고, 프로세싱을 완료하기 위해서 더 적은 context switch를 요구할 것이며, 컴퓨터의 더 효율적인 사용을 이끌어 낸다.

#### 6.5 많은 CPU 스케줄링 알고리즘은 파라미터를 갖는다. 예를 들어 RR 알고리즘은 time slice를 나타내기 위한 파라미터가 필요하다. multilevel feedback queue는 큐의 수, 각 큐에 대한 스케줄링 알고리즘, 큐 간 프로세스를 움직이는 기준 등을 정의하기 위한 파라미터를 필요로 한다. <br/> 그러므로 이 알고리즘들은 실제 알고리즘의 집합이다(예를 들어, 모든 time slice에 대한 RR 알고리즘 집합 등). 알고리즘의 한 집합은 다른 알고리즘을 포함한다(예를 들어, FCFS 알고리즘은 무한의 time quantum을 가진 RR 알고리즘이다). 다음 알고리즘 집합 쌍 간에 어떤 관계가 존재하는가?
a. priority and SJF<br/>
가장 높은 우선순위를 가진 가장 짧은 작업

b. multilevel feedback queue and FCFS<br/>
MLFQ의 가장 낮은 레벨은 FCFS이다.

c. priority and FCFS<br/>
FCFS는 가장 오래 존재했던 작업에 가장 높은 우선순위를 부여한다.

d. RR and SJF<br/>
없음.

#### 6.6 (short-term CPU scheduling의 단계에 있는) 스케줄링 알고리즘이 최근에 가장 적은 processor time을 사용한 프로세스를 선호한다고 가정하자. 이 알고리즘은 왜 I/O-bound 프로그램을 선호하면서 영구적으로 CPU-bound 프로그램을 필요없다고 여기지 않는가?
이 알고리즘은 I/O-bound 프로그램에 의한 상대적으로 짧은 CPU burst 요청 때문에 I/O-bound 프로그램을 선호한다. 하지만 I/O-bound 프로그램이 I/O를 수행하기 위해 상대적으로 자주 CPU를 포기하기 때문에 CPU-bound 프로그램은 필요없지 않을 것이다.

#### 6.7 PCS 스케줄링과 SCS 스케줄링을 구분하라.
PCS 스케줄링은 로컬 프로세스에서 수행된다. 이것은 이용 가능한 LWP에서 스레드 라이브러리가 스레드를 스케줄링 하는 방법이다. SCS 스케줄링은 os가 커널 스레드를 스케줄링 하는 상황이다. many-to-one 또는 many-to-many를 사용하는 시스템에서 두 스케줄링 모델은 근본적으로 다르다. one-to-one을 사용하는 시스템에서 PCS와 SCS는 같다.

#### 6.8 os가 user-level thread를 many-to-many 모델을 사용하는 커널에 매핑하고, 이 매핑이 LWP의 사용을 통해서 이루어진다고 가정하자. 추가적으로 시스템이 프로그램 개발자가 real-time thread를 생성할 수 있게 한다. real-time 스레드를 LWP에 묶는게 필요한가?
그렇다. 그렇지 않으면 user thread는 실제 스케줄링 되기전에 이용 가능한 LWP을 위해 경쟁해야 할 것이다. user thread를 LWP에 묶음으로써, 이용 가능한 LWP를 기다리는 레이턴시가 사라진다. real-time user thread는 즉시 실행될 수 있다.

#### 6.9 전통적인 UNIX 스케줄러는 우선순위 숫자와 우선순위를 역수 관계로 놓는다. 숫자가 클수록 낮은 우선순위를 갖는다. 스케줄러는 다음의 함수를 이용해서 초당 하나씩 프로세스 우선순위를 다시 계산한다.<br/> priority = (recent CPU usage / 2) + base <br/> *base* = 60이고, *recent CPU usage*는 우선순위가 마지막으로 다시 계산된 후로 프로세스가 CPU를 얼마나 자주 사용하는지 나타내는 값을 나타낸다. <br/> P1에 대한 최근 CPU 사용을 40으로, P2에 대해 18, P3에 대해 10이라고 추정하자. 우선순위가 다시 계산될 때, 이 세 프로세스에 대한 새로운 우선순위는 무엇인가? 이 정보에 기초해서 전통적인 UNIX 스케줄러는 CPU-bound 프로세스의 상대적 우선순위를 증가시키는가? 감소시키는가?
우선순위는 각각 80, 69, 65으로 할당된다. 스케줄러는 CPU-bound 프로세스의 상대적인 우선순위를 감소시킨다.


