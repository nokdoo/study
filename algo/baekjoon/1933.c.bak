#include <stdio.h>
#include <stdlib.h>

struct node{
	int x;
	int y;
	struct node *next;
};

struct node *mkNode(int x, int y){
	struct node *tmp = (struct node*) malloc(sizeof(struct node));
	tmp->x = x;
	tmp->y = y;
	tmp->next = NULL;
	return tmp;
}

void printNode(struct node *node){
	while(node != NULL){
		printf("%d %d ", node->x, node->y);
		node = node->next;
	}
}

void insertNode(struct node *A, struct node *new){
	new->next = A->next;
	A->next = new;
}

void cutNode(struct node *A){
	struct node *tmp = A;
	A = A->next;
	tmp->next = NULL;
	while(A!=NULL){
		tmp = A->next;
		free(A);
		A = tmp;
	}
}

struct node *getLastNode(struct node *A){
	while(A->y != 0){
		A = A->next;
	}
	return A;
}

int main(){
	int n; 
	scanf("%d", &n);
	struct node *A = NULL;
	struct node *lastofA = NULL;
	struct node *tmpA = NULL;
	int x0, y0, x1, y1;
	for(int i = 0; i<n; i++){
		scanf("%d", &x0);
		scanf("%d", &y0);
		scanf("%d", &x1);
		y1=0;
		if(A == NULL){
			A = mkNode(x0, y0);
			A->next = mkNode(x1, y1);
			continue;
		}
		tmpA = A;
		
		while(!(tmpA->x <= x0 && x0 <= tmpA->next->x))
			tmpA = tmpA->next;
			
		lastofA = getLastNode(tmpA);
		if(tmpA->y < y0){
			insertNode(tmpA, mkNode(x0, y0));
			tmpA = tmpA->next;
			while(tmpA != NULL && tmpA->y < y0){
				
			}

			if(lastofA->x > x1){
				while(!(tmpA->x <= x1 && x1 <= tmpA->next->x))
					tmpA = tmpA->next;
				

			}else{
				cutNode(tmpA);
				lastofA = mkNode(x1, y0);
				insertNode(tmpA, lastofA);
			}
		}else{
			if(x1 <= lastofA->x){
				continue;
			}else{
				int tmpx = lastofA->x;
				cutNode(tmpA);
				insertNode(tmpA, mkNode(tmpx, y0));
				tmpA = tmpA->next;
				insertNode(tmpA, mkNode(x1, y1));
			}
		}

	}
	printNode(A);
	return 0;
}
