//Scanning a Tree in Constant Space
#include <stdio.h>
#include "tree4.8.h"


void Traverse(struct node *root){

	struct node *L = (struct node*) malloc(sizeof(struct node));
	struct node *P = L;
	struct node *Q = root;
	struct node *tmp = NULL;
	struct node *tmp2 = NULL;

	while(Q != L){
		if(Q != NULL){
			printf("%c\n", Q->data);
			tmp = P;
			tmp2 = Q;
			P = Q;
			Q = tmp2->left;
			tmp2->left = tmp2->right;
			tmp2->right = tmp;
		}else{
			tmp = Q;
			Q = P;
			P = tmp;
		}
	}

}
