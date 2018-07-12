fact: main_fact.o fact.o
	gcc -o fact main_fact.o fact.o

main_fact.o: main_fact.c fact.h

fact.o: fact.c fact.h
