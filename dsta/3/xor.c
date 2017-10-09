#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* XORaddr;
};

struct Node *XOR(struct Node *a, struct Node *b){
	return (struct Node *) ((unsigned int) (a) ^ (unsigned int) (b));
}

struct Node *insertNode(struct Node **head, int data){
	struct Node *tmp_node = (struct Node *) malloc(sizeof(struct Node));
	tmp_node->data = data;

	tmp_node->XORaddr = XOR((*head)->XORaddr, NULL);

	if(*head != NULL){
		struct Node *next = XOR((*head)->XORaddr, NULL);
		(*head)->XORaddr = XOR(tmp_node, next);
	}

	*head = tmp;
}

int main(){
	struct Node *head = NULL;
	insertNode(&head, 1);
	insertNode(&head, 2);
	insertNode(&head, 3);
	insertNode(&head, 4);
}
