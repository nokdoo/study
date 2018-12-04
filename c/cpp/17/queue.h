#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>

#define NSIZE 45

struct item
{
	char name[NSIZE];
};

typedef item Item;

typedef struct node
{
	Item item;
	struct node * next;
} Node;

typedef struct queue
{
	Node * head;
	Node * tail;
	int count;
} Queue;

void InitQueue(Queue *pq);
