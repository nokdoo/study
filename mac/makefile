OBJECTS = main_fact.o fact.o

test : $(OBJECTS)
	gcc -o test $(OBJECTS)

main_fact.o : main_fact.c fact.h
	gcc -c main_fact.c

fact.o : fact.c fact.h
	gcc -c fact.c

clean :
	rm $(OBJECTS)
