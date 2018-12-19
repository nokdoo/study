//Threaded Trees
#include <stdio.h>
#include "tree4.9.h"

int isThread(struct node *N);

struct node *inorderNode = NULL;
struct node *preorderNode = NULL;

void InorderTraversal(struct node *Q, struct node *P){
	if(Q == NULL) return;
	
	
	InorderTraversal(Q->left, Q);
	
	if(Q->left == NULL || Q->right == NULL){
		Q->thread = 1;
		
		if(Q->left == NULL && preorderNode != NULL){
			Q->left = preorderNode;
			printf("%c -> %c\n", Q->data, preorderNode->data);
		}

		if(Q->right == NULL && inorderNode == NULL){
			inorderNode = Q;
		}

	}

	printf("%c : %d\n", Q->data, Q->thread);
	preorderNode = Q;	

	if(inorderNode != NULL && inorderNode != Q){

		inorderNode->right = Q;
		printf("%c -> %c\n", inorderNode->data, Q->data);
		inorderNode = NULL;
	}


	

	InorderTraversal(Q->right, Q);
}

struct node *InorderSuccessor(struct node *N){
	struct node *P = N->right;
	if(P == NULL) return NULL;
	else if(!isThread(P))
		while(!isThread(P->left) || P->left != NULL){
			P = P->left;
		}
	return P;
}

struct node *PreorderSuccessor(struct node *N){
	struct node *P = NULL;
	if(!isThread(N->left) && N->left != NULL) return N->left;
	else{
		P = N;
		while(isThread(P->right)){
			P = P->right;
		}
		if(P->right == NULL) return NULL;
		else return P->right;
	}
}

int isThread(struct node *N){
	if(N->thread == 1) return 1;
	else return 0;
}
