dlist: dlist.o main_dlist.o
	gcc -o dlist main_dlist.o dlist.o
	rm dlist.o main_dlist.o

dlist.o: dlist.c dlist.h
	gcc -c dlist.c

main_dlist.o: main_dlist.c dlist.h
	gcc -c main_dlist.c
