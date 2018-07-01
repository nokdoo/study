#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct node{
	char key;
	int balance;
	struct node* left;
	struct node* right;
};

struct trace{
	int direct;
	struct node *node;
};

struct node *test = NULL;

struct node* NewNode(char newkey){
	struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->key = newkey;
	new_node->balance = 0;
	new_node->left = NULL;
	new_node->right = NULL;
	if(newkey == 'R')
		test = new_node;
	return new_node;
}

void proc(int *d, struct node **Q, char *K, struct node **P){
	if(*K == (*P)->key){
		*d = 0;
		*Q = *P;
	}else if(*K < (*P)->key){
		*d = -1;
		*Q = (*P)->left;
	}else{
		*d = 1;
		*Q = (*P)->right;
	}
}

void swap(struct node *A, struct node *B){
	struct node *tmp = NewNode('A');
	*tmp = *A;
	*A = *B;
	*B = *tmp;
	free(tmp);
}

void Rotate(struct node **P, int d){
	struct node *R = (*P)->right, *L = (*P)->left;
	if(d == -1){//left rot
		swap((*P), (*P)->right);
		R->right = (*P)->left;
		(*P)->left = R;
	}else if(d == 1){//right rot
		swap((*P), (*P)->left);
		L->left = (*P)->right;
		(*P)->right = L;
	}
}

void AVLTreeInsert(char K, struct node** T){
	struct node *P = *T;
	struct node *A = NULL; // critical node
	int CritNodeFound = FALSE;
	int direct = 0; // left: -1, right: 1;
	
	if( *T == NULL ){
		*T = NewNode(K);
		return;
	}

	while(P != NULL && P->key != K){
		if(P->balance != 0){
			A = P;
			CritNodeFound = TRUE;
		}
		if(K < P->key){
			if(P->left == NULL){
				direct = -1;
				break;
			}
			P = P->left;
		}else{
			if(P->right == NULL){
				direct = 1;
				break;
			}
			P = P->right;
		}
	}

	if(P != NULL && K == P->key){
		return;
	}

	if(direct == -1){
		P->left = NewNode(K);
		P = P->left;
	}else if(direct == 1){
		P->right = NewNode(K);
		P = P->right;
	}

	struct node *C = NULL; // child of ciritical node
	struct node *R = NULL; // root
	if(!CritNodeFound){
		R = *T;
	}else{
		int d1;
		proc(&d1, &C, &K, &A);
		
		if(A->balance != d1){
			A->balance = 0;
			R = P;
		}else{
			int d2;
			struct node *B = NULL;
			proc(&d2, &B, &K, &C);
			if(d2 == d2){
				A->balance = 0;
				R = B;
				Rotate(&A, -d1);
			}else{
				int d3;
				proc(&d3, &R, &K, &B);
				if(d3 == d2){
					A->balance = 0;
					C->balance = d1;
				}else if(d3 == -d2){
					A->balance = d2;	
				}else{
					A->balance = 0;
				}
				Rotate(&C, -d2);
				Rotate(&A, -d1);
			}
		}
	}

	while(R != NULL && R->key != K){
		proc(&(R->balance), &R, &K, &R);
	}
}

int isLeaf(struct node *P){
	if(P->right == NULL && P->left == NULL)
		return TRUE;
	return FALSE;
}

int hasTwoChild(struct node *P){
	if(P->right != NULL && P->left != NULL)
		return TRUE;
	return FALSE;
}

struct node* InorderSuccessor(struct node **T, struct node *P){
	struct node *tmp = *T;
	int FindFlag = FALSE;
	int LeftBreak = FALSE;
	struct node *stack[10];
	int idx = -1;

	while(tmp != NULL){
		printf("%c  ", tmp->key);
		if(FindFlag == TRUE){
			return tmp;
		}

		if(LeftBreak == FALSE){
			if(tmp->left == NULL){
				LeftBreak = TRUE;
				tmp = stack[idx--];
			}else{
				stack[++idx] = tmp;
				tmp = tmp->left;
			}
			continue;
		}

		if(tmp->key == P->key){
			FindFlag = TRUE;
		}

		if(tmp->right != NULL){
			tmp = tmp->right;
			LeftBreak = FALSE;
		}else{
			if(idx == -1) return NULL;
			tmp = stack[idx--];
		}
		
	}
}

void AVLTreeDelete(char K, struct node **T){
	struct trace stack[10];
	int idx = -1;
	struct node *P = *T;

	while(P != NULL && P->key != K){
		if(K < P->key){
			stack[++idx].node = P;
			stack[idx].direct = 1;
			P = P->right;
		}else{
			stack[++idx].node = P;
			stack[idx].direct = -1;
			P = P->left;
		}
	}

	if(P == NULL){
		return;
	}

	struct node *Parent = stack[idx--].node;
	int direct = stack[idx--].direct;

	if(isLeaf(P)){
		Parent->balance -= direct;
		if(direct == 1){
			Parent->right = NULL;
		}else{
			Parent->left = NULL;
		}
		free(P);
		return;
	}else{
		if(hasTwoChild(P)){
			struct node *is = InorderSuccessor(T, P);
			//여기
		}else{ // hasOneChild
			if(direct == 1){
				Parent->right = (P->right == NULL) ? P->left : P->right;
			}else{
				Parent->left = (P->right == NULL) ? P->left : P->right;
			}
			free(P);
		}
	}
}

void InorderPrint(struct node *root){
    struct node *stack[10];
    int i = -1;
    struct node* P = root;
    int flag = 0;
	printf("Inorder Traversal : ");
    while(flag == 0){
        if(P != NULL){
            stack[++i] = P;
            P = P->left;
        }else{
            if(i>-1){
                P = stack[i--];
                printf("%c(%d) ", P->key, P->balance);
                P = P->right;
            }else 
				flag = 1;
        }
    }
    printf("\n");
}


int main(){
	struct node *tree = 0;
	AVLTreeInsert('F', &tree);
	AVLTreeInsert('D', &tree);
	AVLTreeInsert('B', &tree);
	AVLTreeInsert('E', &tree);
	AVLTreeInsert('R', &tree);
	AVLTreeInsert('P', &tree);
	AVLTreeInsert('V', &tree);
	AVLTreeInsert('M', &tree);
	struct node *tmp = InorderSuccessor(&tree, test);
	if(tmp == NULL){
		printf("NULL\n");
	}else{
		//printf("%c  ", tmp->key);
	}
//	AVLTreeDelete('B', &tree);
//	AVLTreeInsert('B', &tree);
//	AVLTreeDelete('F', &tree);
//	AVLTreeInsert('F', &tree);
//	AVLTreeDelete('M', &tree);
//	AVLTreeInsert('M', &tree);
//	AVLTreeDelete('R', &tree);
//	AVLTreeInsert('R', &tree);

	InorderPrint(tree);
}
