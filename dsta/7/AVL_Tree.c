#include <stdio.h>
#include <stdlib.h>

struct node{
	char key;
	int balance;
	struct node* left;
	struct node* right;
};

struct node* NewNode(char newkey){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->key = newkey;
	new_node->balance = 0;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void dCKA(char K, struct node* P, struct node** Q, int* d){
	if(P == NULL) return;
	if(K == P->key){
		*d = 0;
		*Q = P;
	}else if(K < P->key){
		*d = -1;
		*Q = (P->left);
	}else{
		*d = 1;
		*Q = (P->right);
	}
}

void Rotate(struct node* P, int d){
	struct node* tmp = P;
	struct node* PR = P->right;
	struct node* PL = P->left;
	if(d == -1){
		P = tmp->right;
		tmp->right = PR->left;
		PR->left = tmp;
	}else{
		P = tmp->left;
		tmp->left = PL->right;
		PL->right = tmp;
	}
}

void AVLTreeInsert(char K, struct node** T){
	struct node* P = *T;
	struct node* A = NULL;
	struct node* B = NULL;
	struct node* R = NULL;
	struct node* C = NULL;
	struct node* tmp = NULL;
	int CritNodeFound = 0;
	int flag = 0;
	int d1 = 0;
	int d2 = 0;
	int d3 = 0;

	if(*T == NULL){
		*T = NewNode(K);
		return;
	}

	while(P != NULL && P->key != K){
		if(P->balance != 0){
			A = P;
			CritNodeFound = 1;
		}
		if(K < P->key){
			if(P->left == NULL){
				P->left = NewNode(K);
				flag = 1;
			}	
			P = P->left;
		}else{
			if(P->right == NULL){
				P->right = NewNode(K);
				flag = 1;
			}
			P = P->right;
		}
		if(flag == 1) break;
	}

	//if(P != NULL && K == P->key){
	if(K == P->key){
		return;
	}

	if(!CritNodeFound){
		R = *T;
	}else{
		dCKA(K, A, &C, &d1);
		if(A->balance != d1){
			A->balance = 0;
			R = P;
		}else{
			dCKA(K, C, &B, &d2);
			if(d2 == d1){
				A->balance = 0;
				R = B;
				Rotate(A, -d1);
			}else{
				dCKA(K, B, &R, &d3);
				if(d3 == d2){
					A->balance = 0;
					C->balance = d1;
				}else if(d3 == -d2){
					A->balance = d2;
				}else{
					A->balance = 0;
				}
				Rotate(C, -d2);
				Rotate(A, -d1);
			}
		}
	}
	while(R != NULL && R->key != K){
		dCKA(K, R, &R, &(R->balance));
	}
}

void InorderPrint(struct node *root){
    struct node *stack[10];
    int i = -1;
    struct node* P = root;
    int flag = 0;
    while(flag == 0){
        if(P != NULL){
            stack[++i] = P;
            P = P->left;
        }else{
            if(i>-1){
                P = stack[i--];
                printf("%c ", P->key);
                P = P->right;
            }else 
				flag = 1;
        }
    }
    printf("\n");
}

int main(){
	struct node *tree = 0;
	AVLTreeInsert('M', &tree);
	AVLTreeInsert('N', &tree);
	AVLTreeInsert('O', &tree);
	AVLTreeInsert('L', &tree);
	AVLTreeInsert('K', &tree);
	AVLTreeInsert('Q', &tree);
	AVLTreeInsert('P', &tree);
	AVLTreeInsert('H', &tree);
	AVLTreeInsert('I', &tree);
	AVLTreeInsert('A', &tree);
	InorderPrint(tree);
}
