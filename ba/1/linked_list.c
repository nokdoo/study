#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
	char data[10];
	struct node *next;
};

struct node *addnode(struct node *end, char s[]){
	strcpy(end->data, s);
	end->next = (struct node *) malloc(sizeof(struct node));
	return end = end->next;
}

void printlist(struct node *);
struct node *searchnode(struct node *, char *);
void delnode(struct node *, struct node *);

int main(int argc, char *argv[]){
	
	struct node *list = NULL;
	struct node *end = NULL;
	char *del = "del";
	int i=1;
	if(argc > 1){
		list = (struct node *) malloc(sizeof(struct node));
		end = list;
		do{
			end = addnode(end, argv[i++]);
		}while(i<argc);

	}else{
		printf("argv 필요...\n");
	}
	end = addnode(end, del);
	end = addnode(end, "haha");
	printlist(list);

	printf("\n\n------------------\n\n");

	delnode(list, searchnode(list, del));
	printlist(list);
	return 0;

}

void printlist(struct node *list){
	while(list->next != NULL){
		printf("%s\n", list->data);
		list = list->next;
	}
}

struct node *searchnode(struct node *list, char *s){
	int i = 1;
	while(list->next != NULL){
		if(strcmp(list->data, s) == 0){
			return list;
		}
		list = list->next;
		i++;
	}

	return 0;
}

void delnode(struct node *list, struct node *node){
	struct node *tmp;
	while(1){
		if(list->next == NULL){
			if(list == node){
				tmp->next = list;
				free(list);
			}
			break;
		}
		if((list = (tmp = list)->next) == node){
			tmp->next = node->next;
			free(list);
			break;
		}
	}
}
