# Practice Exercises
---

#### 3.1 [Figure 3.30, p149]의 프로그램을 이용하여 출력이 Line A에서 무엇이 되는지 설명하라.
제어권이 부모에게 돌아오면, 자식 프로세스는 value의 값을 복제하여 사용하기 때문에 value의 값은 여전히 5이다.

#### 3.2 초기 부모 프로세스를 포함하여 [Figure 3.31, p150]의 프로그램에 의해 생성된 프로세스의 수는 얼마나 되는가?
8개

#### 3.3 애플의 iOS os의 오리지날 버전은 동시처리를 제공하지 않았다. 동시처리가 os에 추가하는 세 가지 주요 복잡도를 논의하라.

#### 3.4 Sun UltraSPARC 프로세서는 multiple register set을 가지고 있다. 새로운 context가 이미 register set 중 하나에 로드되었다면 context swith가 발생할 때 무슨 일이 일어나는지 설명하라. 새로운 context가 register set이 아닌 메모리에 위치하고 모든 register set이 사용 중이라면 어떤 일이 일어나는가?
cpu current-register-set 포인터가 새로운 context를 포함하는 set을 가리킬 것이고, 이것은 매우 짧은 시간은 소모한다. context가 메모리에 있다면 register set에 있는 context 중 하나는선택되고 메모리로 이동해야 한다. 그리고 새로운 context는 메모리로부터 해당 set에 로드되어야 한다. 이 과정은 대체되는 context를 선택하는 방법을 사용하기 때문에, 한 register set을 이용하는 system보다 조금 더 시간을 많이 소모한다.

#### 3.5 프로세스가 fork() operation을 사용해서 새로운 프로세스를 생성할 때 다음의 상태들은 부모 프로세스와 자식 프로세스 간에 공유되는가?
Stack, Heap, Shared memory segments

shared memory semgents만 새롭게 fork된 자식 프로세스와 부모 프로세스 사이에 공유된다. stack과 heap은 새롭게 생성되는 프로세스에 대한 복제본이 만들어진다.

#### 3.6 RPC 메커니즘과 관련해서 "exactly once" semantic을 생각하라. 클라이언트로 돌아온 ACK 메세지가 네트워크 때문에 사라지더라도 이 semantic을 구현하기 위한 알고리즘은 올바르게 실행되는가? 메세지의 sequence를 설명하고 "exactly once"가 여전히 보존되는지 논의하라.

"exactly once"는 원격 프로시저가 오직 한 번만 실행되도록 보장한다. 이것을 보장하는 일반적인 알고리즘은 timestamp와 (또는 서버에게 중복 메세지를 구별하기위한 incremental counter와) 결합된 acknowledgement (ACK) 스키마와 결합한다.

일반적인 전략은 클라이언트가 timestamp와 함께 RPC를 서버에 보내는 것이다. 클라이언트는 timeout clock을 시작한다. 그러면 클라이언트는 다음 둘 중 하나를 기다릴 것이다. (1) - 이것은 원격 프로시저가 동작하였음을 알려주는 서버로부터 ACK를 받을 것이다. (2) - 시간을 초과할 것이다. 클라이언트가 시간을 초과하면 클라이언트는 서버가 원격 프로시저를 동작할 수 없는 것이라고 추정한다. 그래서 클라이언트는 새로운 timestamp를 보내면서 RPC를 두 번째로 호출한다. 클라이언트는 다음 두 가지 이유로 ACK를 받지 않을 수 있다. (1) - original RPC가 서버에 전달되지 않았거나 (2) - RPC가 올바르게 전달되고 동작하였지만 ACK가 길을 잃어버린 경우다. (1)의 상황에서 ACK의 사용은 서버가 궁극적으로 RPC를 받고 동작하도록 한다. (2)의 상황은 서버는 중복된 RPC를 받을 것이고 timestamp를 사용하여 중복을 식별할 것이다. 그래서 RPC를 두 번 동작하지 않도록 한다. 서버는 클라이언트가 RPC이 동작 했음을 알 수 있게 ACK를 두 번 보내는 것이 중요하다.

#### 3.7 분산 시스템이 서버의 실패를 알기 쉽다고 가정하자. RPC 실행의 "exactly once" semantic를 보장하는데 어떤 메커니즘이 필요한가?
서버는 RPC operation이 성공적으로 동작하였고 그 결과가 operation과 관련이 있던지 간에, 어떤 RPC operation을 수신하였는제 대한 정보를 disk log와 같은 안전한 저장소에 보관해야 한다. 서버 충돌이 일어나고 RPC 메세지를 수신하였을 때, 서버는 RPC가 이전에 동작했었는지를 확인할 수 있고 RPC의 실행에 대한 "exactly once" semantic을 보장한다.
