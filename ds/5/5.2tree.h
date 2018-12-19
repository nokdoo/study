#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node *left;
	struct node *right;
};

struct node *newNode(char data){
	struct node *node = (struct node *) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

struct node *makeBinTree(){
	struct node *root = newNode('\0');
	
	root->left = newNode('\0');
	root->right = newNode('\0');
	
	root->left->left = newNode('\0');
	root->left->right = newNode('\0');

	root->right->left = newNode('A');
	root->right->right = newNode('\0');

	root->left->left->left = newNode('\0');
	root->left->left->right = newNode('\0');

	root->left->right->left = newNode('D');
	root->left->right->right = newNode('\0');

	root->right->right->left = newNode(' ');
	root->right->right->right = newNode('F');

	root->left->left->left->left = newNode('I');
	root->left->left->left->right = newNode('V');

	root->left->left->right->left = newNode('M');
	root->left->left->right->right = newNode('U');

	root->left->right->right->left = newNode('H');
	root->left->right->right->right = newNode('N');
	return root;
}
