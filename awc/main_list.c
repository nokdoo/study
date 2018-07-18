#include <stdio.h>

#include "list.h"

static void print(const List *list){
	ListElmt *element;
	int *data;

	fprintf(stdout, "size = %d\n", list_size(list));

	element = list_head(list);

	while(1){
		data = element_data(element);
		fprintf(stdout, "%03d ", *data); 

		if(element_is_tail(element))
			break;
		else
			element = element_next(element);
	}

	return;
}

int main(){
	List list;

	int *data;
	int i;

	list_init(&list, free);

	for(i = 7; i>=0; i--){
		data = (int *)malloc(sizeof(int));
		*data = i;
		list_ins_next(&list, NULL, data);
	}

	print(&list);
	
	return 0;
}
