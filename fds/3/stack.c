#include <stdio.h>

#define MAXSIZE 5

typedef struct{
	int key;
}element;

int top = -1;
int stacksize = 0;
element e[MAXSIZE];

void CreateS(int size);
int IsFull();
void Push(element item);
int IsEmpty();
element Pop();

void CreateS(int size){
	if(size > 5){
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

void Push(element item){
	if(top<stacksize-1){
		e[++top] = item;
	}else{
		printf("stack is full\n");
	}
}

int IsEmpty(){
	if(top == -1)
		return 1;
	return 0;
}

element Pop(){
	if(IsEmpty()){
		printf("stack is Empty\n");
		return e[0];
	}
	return e[top--];
}

int main(){
	element el;
	el.key = 1;
	Pop();
	CreateS(5);
	Push(el);
	el.key = 2;
	Push(el);
	el.key = 3;
	Push(el);
	el.key = 4;
	Push(el);
	el.key = 5;
	Push(el);
	Push(el);
	Push(el);
	el = Pop();
	printf("%d\n",el.key);
	el = Pop();
	printf("%d\n",el.key);
	el = Pop();
	printf("%d\n",el.key);
	el = Pop();
	printf("%d\n",el.key);

}
