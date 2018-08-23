#include <stdio.h>

#include "dlist.h"

static void print(DList *list)
{
	DListElmt *element;
	int *data;

	if(dlist_size(list)==0)
		return;
	
	element = dlist_head(list);

	while(element != NULL)
	{
		data = dlist_data(element);
		fprintf(stdout, "%d ", *data); 
		element = dlist_next(element);
	}
}

int main()
{
	DList list;
	int *data;
	int i;

	dlist_init(&list, free);

	for(i=7; i>=0; i--)
	{
		data = (int*)malloc(sizeof(int));
		*data = i;
		dlist_ins_next(&list, dlist_tail(&list), data);
	}

	print(&list);

	return 0;
}
