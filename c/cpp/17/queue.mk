queue : use_q.o queue.o
	cc -o queue use_q.o queue.o

use_q.o : use_q.c
	cc -c use_q.c

queue.o : queue.c
	cc -c queue.c
