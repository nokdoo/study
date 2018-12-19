//linked list(queue)
#include <stdio.h>
#include <stdlib.h>
#include "../std.h"

typedef int info;

typedef struct node{
	info info;
	struct node *next;
}node;

typedef struct list{
	node *front;
	node *back;
}list;

list *MakeEmptyQueue(){
	list *L = (list*)malloc(sizeof(list));
	L->front = L->back = NULL;
	return L;
}

boolean IsEmptyQueue(list *L){
	return L->front == NULL;
}

void Enqueue(info x, list *L){
	node *P = (node*)malloc(sizeof(node));
	P->info = x;
	P->next = NULL;
	if(IsEmptyQueue(L)){
		L->front = P;
	}else{
		L->back->next = P;
	}
	L->back = P;
}

info Dequeue(list *L){
	if(IsEmptyQueue(L)){
		printf("Queue is empty\n");
		exit(1);
	}
	int x = L->front->info;
	node *tmp = L->front;
	L->front = L->front->next;
	if(IsEmptyQueue(L)){
		L->back = NULL;
	}
	free(tmp);
	return x;
}

info Front(list *L){
	if(IsEmptyQueue(L)){
		printf("Queue is empty\n");
		exit(2);
	}
	return L->front->info;
}

void print34(list *L){
	node *tmp = L->front;
	while(tmp != NULL){
		printf("%d", tmp->info);
		tmp = tmp->next;
	}
	printf("\n");
}
