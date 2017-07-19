#include <stdio.h>
#include "./linkedlist.h"

int main(){
	listNode *list;
	list = create(10);
	print(list);
	add(list, 20);
	add(list, 30);
	add(list, 40);
	add(list, 50);
	add(list, 60);
	print(list);
	removenode(list, getnode(list, 40));
	print(list);

}
