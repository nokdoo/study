//Three-in-one traversal of binary tree
#include <stdio.h>
#include "tree.h"


void Traverse(struct node *root){
	if(root!=NULL){
		printf("%d ", root->data);
		Traverse(root->left);
		Traverse(root->right);
	}
}
