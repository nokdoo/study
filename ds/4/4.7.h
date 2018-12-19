//Link-Inversion traversal of binary tree
#include <stdio.h>
#include "tagtree.h"


void Traverse(struct node *root){

	struct node *P = NULL; // parent of Q
	struct node *Q = root;
	struct node *tmp = NULL;

	while(1){
		//왼쪽 최하단으로 내려감
		while(Q != NULL && Q->tag == 0){
			printf("%d\n", Q->data);
			Q->tag = 0;
			tmp = Q->left;
			Q->left = P;
			P = Q;
			Q = tmp;
		}

		//아래의  descend4를 수행하고 왼쪽으로 내려가지 못하면 이제 올라가야 할 차례
		while(P != NULL && P->tag == 1){
			tmp = P->right;
			P->right = Q;
			Q = P;
			P = tmp;
		}

		if(P == NULL) return;
		else{
			//왼쪽에서 올라감
			tmp = P->left;
			P->left = Q;
			Q = P;
			P = tmp;
			Q->tag = 1;
			//왼쪽에서(탐색된 곳에서) 올라오면 탐색했다는 의미로 tag = 1

			//오른쪽으로 내려감 : descend4
			tmp = Q->right;
			Q->right = P;
			P = Q;
			Q = tmp;
		}
	}
}
