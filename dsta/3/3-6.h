/*
	Contiguos-memory(stack) 
	+
	BinarySearch
*/


#include <stdio.h>
#include <stdlib.h>

typedef enum {false, true} boolean;

typedef struct stack{
	int length;
	int info[max_length];
}stack;

stack *MakeEmptyStack(){
	stack *L = (stack*)malloc(sizeof(stack));
	return L;
}

boolean IsEmptyStack(stack *L){
	return L->length == 0;
}

//info = int
int Top(stack *L){
	if(IsEmptyStack(L)){
		printf("Stack is Empty");
		exit(1);
	}
	return L->info[L->length-1];
}

//info = int
int Pop(stack *L){
	if(IsEmptyStack(L)){
		printf("Stack is Empty");
		exit(1);
	}
	int x = L->info[L->length-1];
	L->length--;
	return x;
}


//info = int
void Push(int x, stack *L){
	if(L->length == max_length){
		printf( "Stack is full");
		exit(2);
	}
	L->length++;
	L->info[L->length-1] = x;

}

void print36(stack *L){
	int i;
	for(i=0; i<L->length; i++){
		printf("%d", L->info[i]);
	}
	printf("\n");
}
