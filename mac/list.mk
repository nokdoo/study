list: main_list.o list.o
	gcc -o list main_list.o list.o
	rm main_list.o list.o

list.o: list.c list.h
	cc -c list.c

main_list.o: main_list.c list.h
	cc -c main_list.c
