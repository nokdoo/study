#include "4.9.h"

int main(){
	struct node *root = makeBinTree();
	InorderTraversal(root, NULL);
	printf("%c - inorder - %c\n", root->right->left->data, InorderSuccessor(root->right->left)->data);
}
