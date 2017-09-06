//ring buffer(queue)

#include <stdio.h>
#include <stdlib.h>
#include "../std.h"

#define max_length 20

typedef struct queue{
	int length;
	int info[max_length];
	int front;
}queue;

queue *MakeEmptyQueue(){
	queue *L = (queue*)malloc(sizeof(queue));
	L->length = 0;
	L->front = 0;
	return L;
}

boolean IsEmptyQueue(queue *L){
	return L->length == 0;
}

int Dequeue(queue *L){
	if(IsEmptyQueue(L)){
		printf("Queue is empty\n");
		exit(1);
	}
	int x = L->info[L->front];
	L->front = (L->front + 1) % max_length;
	L->length--;
	return x;
}

void Enqueue(int x, queue *L){
	if(L->length == max_length){
		printf("Queue is full\n");
		exit(2);
	}
	L->length++;
	L->info[(L->front + L->length - 1) % max_length] = x;
}

int Front(queue *L){
	if(IsEmptyQueue(L)){
		printf("Queue is empty\n");
		exit(3);
	}
	return L->info[L->front];
}
