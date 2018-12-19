//Three-in-one traversal of binary tree
#include <stdio.h>
#include "tree.h"


void Traverse(struct node *root){
	while(root != NULL){
		printf("%d ", root->data);
		Traverse(root->left);
		root = root->right;
	}
}
