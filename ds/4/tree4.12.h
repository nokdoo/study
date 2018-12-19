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
	//트리 모양
	//p117 참고

	//depth 0
	struct node *root = newNode('D');

	//depth 1
	root->left = newNode('B');
	root->right = newNode('K');

	//depth 2
	root->left->left = newNode('A');
	root->left->right = newNode('C');
	root->right->left = newNode('I');
	root->right->right = newNode('L');

	//depth 4
	root->right->left->left = newNode('F');
	root->right->left->right = newNode('J');

	//depth 5
	root->right->left->left->left = newNode('E');
	root->right->left->left->right = newNode('G');
	
	//depth 6
	root->right->left->left->right->right = newNode('H');
	return root;
}
