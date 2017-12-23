# Practice Exercises
---

#### 1.1 OS의 주요 목적 3가지는 무엇인가?
* 컴퓨터 하드웨어에서 편리하고 효율적인 방법으로 프로그램을 실행시킬 수 있는 환경을 사용자에게 제공하는 것.
* 주어진 문제를 해결하기 위해서 독립된 자원을 할당하는 것. 할당은 가능한 공정하고 효율적으로 이루어져야 한다.
* 사용자 프로그램이 실행되는 동안 제어 프로그램이 에러 발생, 부적절한 접근을 감시하고 I/O 장치의 제어와 operation을 관리하는 것.

#### 1.2 OS를 위한 컴퓨터 하드웨어와 효율적 사용이 강조되지만 이 원칙을 저버리고 자원의 낭비를 일으키는 경우는 언제인가? 그리고 이 낭비는 항상 낭비로서 불필요한 것인가?
시스템은 사용자의 요구에 자원을 최대로 활용해야 하지만, 시각화의 이유로 GUI에 자원을 낭비하기도 한다. 하지만 이 GUI는 사용자와 시스템 간 인터페이스로서 역할을 하기 때문에 불필요하지 않다. GUI도 사용자의 필요에 의한 프로그램이다.

#### 1.3 실시간 환경을 위해서 OS 작성하는 프로그래머가 극복해야 하는 주된 어려움은 무엇인가?
정해진 시간 내에 task를 처리하지 못하면 breakdown을 일으키는 scheduling scheme를 정의하는 것.

#### 1.4 OS의 다양한 정의를 고려했을 때, web, mail과 같은 프로그램을 os에 포함시키는 것에 대해 어떻게 생각하는가?
[반대] windows에서 IE외에 다른 프로그램을 사용하듯 프로그램에도 경쟁성이 있어야 발전을 거듭할 수 있다.

#### 1.5 시스템을 보호하는 기본적인 형태로써, kernel mode와 user mode는 어떻게 구별하는가?
instruction은 cpu가 kernel mode에 있을 때만 실행 가능하고, 유사하게 하드웨어 장치 또한 프로그램이 kernel mode에서 실행될 때만 접근할 수 있다. 인터럽트를 발생 시킬지에 대한 동작 제어도 cpu가 kernel mode에 있을 때 가능하다. user mode에서 실행되는 cpu는 매우 제한적인 능력만 가지고 있다.

#### 1.6 다음 중 특권이 필요한 것은 무엇인가?
a. set value of timer
b. read the clock
c. clear memory
d. issue a trap instruction
e. turn off interrupts
f. modify entries in device-status table
g. switch from user to kernel mode
h. access i/o device

a, c, e, f, h

#### 1.7 os는 메모리의 일부에 os자체를 저장하고 내부, 외부에서 변경이 불가능하게 만들어진 과거가 있다. 이러한 문제점은 무엇인가?
os는 자체적으로 사용자의 정보를 관리하고 있다. 변경이 불가능하다는 것은 이를 관리할 수 없음을 의미한다.

#### 1.8 어떤 cpu는 kernel mode, user mode 외의 추가적인 mode를 지원한다. 이 추가적인 mode를 사용해서 얻는 것은 무엇인가?
* user mode의 type을 다양하게 구별할 수 있고 시스템은 코드가 사용될 수 있는 mode를 지정할 수 있게 된다. 해당 mode에 소속된 사용자들은 서로 다른 사용자의 코드를 사용할 수 있다.
* kernel mode 내에서 구별되는 kernel mode를 만들어 별 다른 switch 없이 kernel mode에서 서비스될 수 있다.

#### 1.9 timer가 현재 시간을 구하는 과정을 간략히 설명하라. 
* 프로그램은 앞으로 얼마 간의 시간 동안 sleep할 것인지 timer를 지정할 수 있다.
* timer의 시간이 지나고 인터럽트가 발생하면 지금까지 발생한 인터럽트의 횟수를 사용하여 현재 시간에 업데이트 시킨다.

#### 1.10 캐시가 유용한 이유는 무엇인가? 캐시가 어떤 문제를 해결하는가? 캐시가 일으키는 문제는 무엇인가? 캐시를 디스크만큼 크게 만들 수 있다면 디스크를 제거하고 캐시를 크게 만드는 것이 어떤가?
* 캐시는 속도가 다른 component에 data를 전송하는데 유용하다. 캐시는 component사이에서 중간 속도를 제공하여 전송 문제를 해결한다.
 -> 빠른 장치가 느린 장치를 기다릴 필요가 없다.
component의 데이터가 변경되면(multiprocessor system에서 일어날 수 있는 일) 캐시의 데이터도 없데이트 되어야 한다.

#### 1.11 분산 시스템의 client-server model과 peer-to-peer model을 구분하라
* client, server로 역할이 구분되어 있는 것과는 달리 peer-to-peer 모델에서는 역할의 제한이 없다.
