#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 500

typedef struct{
	short int vert;
	short int horiz;
}location;

int top = -1;
int stacksize = 0;
location e[MAXSIZE];

void CreateS(int size);
int IsFull();
void Push(location item);
int IsEmpty();
location Pop();

void CreateS(int size){
	if(size > MAXSIZE){
		printf("size is too big\n");
		return;
	}
	stacksize = size;
}

int IsFull(){
	if(top == MAXSIZE-1)
		return 1;
	return 0;
}

void Push(location item){
	if(top<stacksize-1){
		e[++top] = item;
		printf("%d\n", top);
	}else{
		exit(0);
		printf("stack is full\n");
	}
}

int IsEmpty(){
	if(top == -1)
		return 1;
	return 0;
}

location Pop(){
	if(IsEmpty()){
		printf("stack is Empty\n");
		return e[0];
	}
	return e[top--];
}

