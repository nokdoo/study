#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "queue.h"

static void CopyToNode(Item *item, Node *node);
static void CopyToItem(Node *node, Item *item);

void Init(Queue *pq)
{
	pq->head = NULL;
	pq->tail = NULL;
	pq->count = 0;
}

bool IsEmpty(Queue *pq)
{
	return pq->count == 0;
}

bool IsFull(Queue *pq)
{
	return pq->count == QSIZE;
}

int NumofQ(Queue *pq)
{
	return pq->count;
}

void Add(Queue *pq, Item *item)
{
	Node *pnew;

	if(IsFull(pq))
	{
		printf("Can't add new item because Queue is full\n");
		return;
	}

	pnew = (Node *) malloc(sizeof(Node));

	if(pnew == NULL)
	{
		fprintf(stderr, "Allocation Error\n");
		exit(1);
	}

	CopyToNode(item, pnew);

	if(IsEmpty(pq))
	{
		pq->head = pnew;
	}
	else
	{
		pq->tail->next = pnew;
	}
	pq->tail = pnew;
	pq->count++;
}

Item *Shift(Queue *pq)
{
	if(IsEmpty(pq)) NULL;

	Node *head = pq->head;
	Item *item = (Item*) malloc(sizeof(Item));
	CopyToItem(head, item);
	
	pq->head = head->next;
	free(head);
	pq->count--;
	if(IsEmpty(pq))
		pq->tail = NULL;

	return item;
}

void CopyToNode(Item *item, Node *node)
{
	node->item = *item;
}

void CopyToItem(Node *node, Item *item)
{
	//*item = node->item;
	strcpy(item->name, (node->item).name);
}
