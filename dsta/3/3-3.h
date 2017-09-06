//linked list(stack)
#include <stdio.h>
#include <stdlib.h>
#include "../std.h"

typedef int info;

typedef struct node{
	info info;
	struct node *next;
}node;

typedef struct list{
	struct node *next;
}list;

list *MakeEmptyStack(){
	list *L = (list*)malloc(sizeof(list));
	L->next = NULL;
	return L;
}

boolean IsEmptyStack(list *L){
	return L->next == NULL;
}

info Top(list *L){
	if(IsEmptyStack(L)){
		printf("Stack is empty\n");
	}
	return L->next->info;
}

info Pop(list *L){
	if(IsEmptyStack(L)){
		printf("Stack is empty\n");
	}
	int x = L->next->info;
	L->next = L->next->next;
	return x;
}

void Push(int x, list *L){
	node *P = (node*)malloc(sizeof(node));
	P->info = x;
	P->next = L->next;
	L->next = P;
}

void print33(list *L){
	node *tmp = L->next;
	while(tmp != NULL){
		printf("%d", tmp->info);
		tmp = tmp->next;
	}
	printf("\n");
}
