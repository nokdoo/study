#include <stdio.h>
#include <stdlib.h>

struct s_node{
	struct s_node *pre;
	int data;
	struct s_node *next;
};

struct s_node *getlastnode(struct s_node **node){
	struct s_node *tmp_node = *node;
	if(tmp_node == NULL){
		return NULL;
	}
	while(tmp_node->next != NULL)
		tmp_node = tmp_node->next;
	return tmp_node;
}

void addnode(struct s_node **node, int data){
	struct s_node *newNode = (struct s_node *) malloc(sizeof(struct s_node));
	newNode->data = data;
	struct s_node *lastnode = NULL;
	if(*node == NULL){
		*node = newNode;
	}else{
		newNode = (struct s_node *) malloc(sizeof(struct s_node));
		lastnode = getlastnode(node);
		newNode->pre = lastnode;
		newNode->data = data;
		lastnode->next = newNode;
	}
}

void delnode(struct s_node **list, struct s_node *node){
	struct s_node *tmp_node = *list;
	if(node == NULL){
		return;
	}
	while(tmp_node->next != node && tmp_node != NULL){
		tmp_node = tmp_node->next;
	}
	if(tmp_node == NULL){
		return;
	}
	tmp_node->next = node->next;
	free(node);
}

void printlist_(struct s_node **list){
	struct s_node *i_list = *list;
	while(i_list != NULL){
		printf("%d\n", i_list->data);
		i_list = i_list->next;
	}
}

struct s_node *searchnode(struct s_node *list, int data){
	while(list != NULL){
		if(list->data == data){
			return list;
		}
		list = list->next;
	}
	return NULL;
}

int main(){
	struct s_node *list;
	addnode(&list, 5);
	addnode(&list, 4);
	printlist_(&list);
	printf("\n\n\n");
	delnode(&list, getlastnode(&list));
	printlist_(&list);
	printf("\n\n\n");
	delnode(&list, searchnode(list, 6));
	printlist_(&list);

}
