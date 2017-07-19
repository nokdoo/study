#include <stdio.h>
#include <stdlib.h>

#define MALLOC(p,s) \
	if(!((p)=malloc(s))){\
		fprintf(stderr, "Insufficient memmory");\
		exit(EXIT_FAILURE);\
	}

typedef struct node{
	int data;
	struct node *link;
}listNode;

listNode *create(int val){
	listNode *tmp;
	MALLOC(tmp, sizeof(*tmp));
	tmp->data = val;
	tmp->link = NULL;
	return tmp;
}

void destroy(listNode *list){
	listNode *tmp;
	while(list != NULL){
		tmp = list->link;
		free(list);
		list = tmp;
	}
}

void print(listNode *list){
	while(list != NULL){
		printf("%d ", list->data);
		list = list->link;
	}
	printf("\n");
}

void insertto(listNode *list, int val){
	listNode *added;
	MALLOC(added, sizeof(*added));
	added->link = list->link;
	added->data = val;
	list->link = added;
}

void add(listNode *list, int val){
	while(list->link != NULL){
		list = list->link;
	}
	listNode *tmp;
	MALLOC(tmp, sizeof(*tmp));
	tmp->data = val;
	tmp->link = NULL;
	list->link = tmp;
}

listNode *getnode(listNode *list, int val){
	while(list->data != val){
		list = list->link;
		if(list == NULL){
			printf("val is not present\n");
			return NULL;
		}
	}
	return list;
}

int removenode(listNode *list, listNode *delnode){
	if(list == delnode){
		free(list);
		return 1;
	}
	while(list->link != delnode){
		list = list->link;
	}
	listNode *tmp = list->link;
	list->link = list->link->link;
	free(tmp);
}
