# Practice Exercises
---

#### 5.1 5.4절에서 disabling interrupt는 빈번하게 systems의 clock에 영향을 미칠 수 있다고 했다. 왜 이것이 발생할 수 있고 그러한 영향을 어떻게 최소화 할 수 있는지 설명하라.
system clock은 모든 clock interrupt에서 업데이트 된다. 인터럽트가 차단된다면 (특히 긴 시간 동안), system clock이 현재 시간을 쉽게 잃어버리는 것이 가능하다. system clock은 scheduling purpose에도 사용된다. 예를 들어 프로세스를 위한 time quantum은 다수의 clock tick을 표현된다. 모든 clock interrupt에서 스케쥴러는, 현재 실행 중인 프로세스에 대한 time quantum이 만료되었는지를 결정한다. clock interrupt가 차단된다면 스케쥴러는 time quantum을 정확하게 할당할 수 없다. 이 영향은 매우 짧은 시간동안만 clock interrupt를 차단함으로써 최소화될 수 있다.

#### 5.2 Windwos, Linux, Solaris는 왜 multiple locking mechanism을 구현하는지 설명하라. 이들이 spinlock, mutex lock, semaphore, adaptive mutex lock, condition variable을 사용하는 상황을 설명하라. 각각의 경우에서 왜 메커니즘이 필요한지 설명하라.
이 os들은 어플리케이션 개발자의 요구에 의존하는 다른 locking mechanism을 제공한다. spinlock은 스레드가 sleep queue에 넣어져 오버헤드를 발생시키기 보다는 (짧은 시간 동안) 바쁘게 실행될 수 있는 multiprocessor system에 유용하다. mutex는 자원을 locking하는 것에 유용하다. Solaris2는 adaptive mutex를 사용한다. 이것은 mutex가 multiprocessor machine에서 spinlock으로 구현되는 것을 의미한다. semaphore와 condition variable은 회전이 긴 시간동안 지속되는 것은 비효율적이기 때문에, 자원이 긴 시간 동안 유지되어야 할 때 synchronization을 위한 더 적절한 툴이다. 

#### 5.3 *busy waiting*의 의미는 무엇인가? os에 있는 waiting의 종류는 무엇인가? busy waiting은 전부 회피할 수 있는가?
*busy waiting*은 프로세스가 processor를 포기하는 것 없이 tight loop에서 만족되는 condition을 기다리고 있는 것을 말한다. 다르게는, 프로세스가 processor를 포기함으로써 기다릴 수 있으며, condition을 차단하고 미래에 적절한 때에 깨어나기를 기다릴 수 있다. busy waiting은 피할 수 있지만 프로세스를 sleep 상태로 놓는 것과, 적절한 프로그램 상태에 도달했을 때 다시 wake 상태로 돌아오는 것과 관련된 오버헤드를 일으킨다.

#### 5.4 spinlock이 single-processor system에 적절하지 않고 아직 multiprocessor system에서 사용되는 이유를 설멍하라.
spinlock은 spinlock의 밖에서 프로세스를 중단하는 condition이 오직 다른 프로세스의 실행으로부터 얻어질 수 있기 때문에 single-processor system에는 적합하지 않다. 프로세스가 processor를 포기하지 않는다면, 다른 프로세스는, 첫 번째 프로세스가 진행하기 위해 요구되는 프로그램 condition을 설정할 수 있는 기회를 얻지 못한다. multiprocessor system에서는 다른 프로세스가 다른 processor에서 실행되고, 이것에 의해 다른 프로세스가 첫 번째 프로세스를 spinlock으로부터 해제하기 위한 프로그램 state를 수정할 수 있다.

#### 5.5 *wait()*, *signal()* semaphore operation이 atomically하게 실행되지 않는다면 mutual exclusion이 파괴될 수 있음을 보여라.
wait operation은 semaphore와 연관된 값을 atomically하게 감소시킨다. semaphore의 값이 1일 때 두 개의 wait operation이 하나의 semaphore에서 실행된다면, 두 개의 operation이 atomically하게 수행되지 않는 다면, 두 operation 모두 semaphore의 값을 감소시키는 것을 수행할 것이고 이것에 의해 mutual exclusion을 파괴한다.

#### 5.6 binary semaphore가 n개의 프로세스 사이에서 mutual exclusion을 구현하기 위해 사용될 수 있는지 설명하라.
n개의 프로세스는 1로 초기화 된 하나의 semaphore, mutex를 공유한다. 각 프로세스 Pi는 다음처럼 구성된다.

	do{
		wait(mutex);

			/* critical section */

		signal(mutex);
			
			/* remainder section */
	} while (true);
