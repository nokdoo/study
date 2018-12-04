#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>

#define NSIZE 45
#define QSIZE 14

struct item
{
	char name[NSIZE];
};

typedef struct item Item;

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

void Init(Queue *pq);
bool IsEmpty(Queue *pq);
bool IsFull(Queue *pq);
int NumofQ(Queue *pq);
void Add(Queue *pq, Item *item);
Item *Shift(Queue *pq);
#endif
