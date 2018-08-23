fact : main_fact.o fact.o
	gcc -o fact main_fact.o fact.o
	rm main_fact.o fact.o

main_fact.o: main_fact.c fact.h
	gcc -c main_fact.c

fact.o: fact.c fact.h
	gcc -c fact.c

