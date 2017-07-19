#include <stdio.h>
#include "./linkedstack.h"

int main(){
	listNode *list;
	list = create(10);
	print(list);
	printf("%p ", list);
	list = add(list, 20);
	printf("%p\n", list);
	list = add(list, 30);
	list = add(list, 40);
	list = add(list, 50);
	list = add(list, 60);
	print(list);
	removenode(list, getnode(list, 40));
	
	print(list);

}
