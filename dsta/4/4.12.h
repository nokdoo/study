//Implementing Level-Order Traversal
#include <stdio.h>
#include "tree4.12.h"

struct que{
	struct node *node;
	struct que *next;
};

struct que *que = NULL;

struct que *pop(){
	if(que == NULL) return NULL;
	struct que *tmp = que;
	que = que->next;
	return tmp;
}

void printque(){
	struct que *tmp = que;
	while(tmp != NULL){
		printf("%c ", tmp->node->data);
		tmp = tmp->next;
	}
	printf("\n");
}

void push(struct node *node){
	if(node == NULL) return ;

	struct que *tmp = que;

	if(tmp == NULL){
		tmp = (struct que *) malloc(sizeof(struct que));
		tmp->node = node;
		tmp->next = NULL;
		if(que == NULL) que = tmp;
	}else{

		while(tmp->next != NULL){
			tmp = tmp->next;
		}


		tmp->next = (struct que *) malloc(sizeof(struct que));
		tmp->next->node = node;
		tmp->next->next = NULL;
	}
}


void Traverse(){
	while(que != NULL){
		struct que *nodeOfQue = pop();
		printf("%c\n", nodeOfQue->node->data);
		push(nodeOfQue->node->left);
		push(nodeOfQue->node->right);
		free(nodeOfQue);
	}
}
