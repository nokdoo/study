#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

int main(void)
{
	Queue q;
	Init(&q);

	char str1[NSIZE] = "hello1";
	char str2[NSIZE] = "hello2";
	char str3[NSIZE] = "hello3";

	Item *item;
	item = (Item*) malloc(sizeof(Item));
	strcpy(item->name, str1);
	Add(&q, item);

	item = (Item*) malloc(sizeof(Item));
	strcpy(item->name, str2);
	Add(&q, item);

	item = (Item*) malloc(sizeof(Item));
	strcpy(item->name, str3);
	Add(&q, item);

	Item *item2 = Shift(&q);
	printf("%s\n", item2->name);
	item2 = Shift(&q);
	printf("%s\n", item2->name);
	item2 = Shift(&q);
	printf("%s\n", item2->name);
}
