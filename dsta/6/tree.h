#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data){
	struct node *node = (struct node *) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

struct node *makeBinTree(){
	//test tree
	//						F
	//					D		U
	//						  P   V
	//                      N   S
	//                       O Q T
	struct node *root = newNode('F');
	root->left = newNode('D');
	root->right = newNode('U');
	root->right->left = newNode('P');
	root->right->right = newNode('V');
	root->right->left->left = newNode('N');
	root->right->left->right = newNode('S');
	root->right->left->left->right = newNode('O');
	root->right->left->right->left = newNode('Q');
	root->right->left->right->right = newNode('T');
	return root;
}
