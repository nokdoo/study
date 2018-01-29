#include "tree.h"

void InorderPrint(struct node *root){
	struct node *stack[10];
	int i = -1;
	struct node *P = root;
	int flag = 0;
	while(flag == 0){
		if(P != NULL){
			stack[++i] = P;
			P = P->left;
		}else{
			if(i>-1){
				P = stack[i--];
				printf("%c ", P->data);

				P = P->right;
			}else flag = 1;
		}	
	}
	printf("\n");
}

void BinaryTreeInsert(struct node *root, char key){
	struct node *P = root;
	if(P == NULL){
		//트리가 만들어져 있으니 패스
	}
	while(1){
		if(P->data > key){
			if(P->left == NULL){
				P->left = newNode(key);
				return;
			}
			P = P->left;
		}else if(P->data < key){
			if(P->right == NULL){
				P->right = newNode(key);
				return;
			}
			P = P->right;
		}
	}
}

void CopyNode(struct node *from, struct node *to){
	to->data = from->data;
	to->right = from->right;
	to->left = from->left;
}

void BinaryTreeDelete(struct node *root, char key){
	struct node *P = root;
	struct node *Q = NULL;
	struct node *tmp = NULL;
	while(1){
		if(key < P->data){
			tmp = P;
			P = P->left;
		}else if(P-> data < key){
			tmp = P;
			P = P->right;
		}else if(P->data == key){
			if(P->right != NULL){
				tmp = NULL;
				Q = P->right;
				while(Q->left != NULL){
					Q = Q->left;
				}
				P->data = Q->data;
				if(Q->right != NULL){
					tmp = Q->right;
					Q->data = Q->right->data;
					Q->left = Q->right->left;
					Q->right = Q->right->right;
					free(tmp);
				}else{
					P->right = NULL;
					free(Q);
				}
			}else{
				if(P->left != NULL){
					tmp = NULL;
					Q = P->left;
					while(Q->right != NULL){
						tmp = Q;
						Q = Q->right;
					}
					P->data = Q->data;
					if(tmp != NULL){
						if(Q->left != NULL){
							tmp->right = Q->left;
							free(Q);
						}else tmp->right = NULL;
					}
				}else{
					if(tmp != NULL) 
					tmp->right = P->left;
					free(P);
				}
			}
			return;
		}
	}
}

int main(){
	struct node *root = makeBinTree();
	InorderPrint(root);
	BinaryTreeInsert(root, 'E');
	BinaryTreeInsert(root, 'R');
	InorderPrint(root);
	BinaryTreeDelete(root, 'E');
	BinaryTreeDelete(root, 'R');
	BinaryTreeDelete(root, 'F');
	BinaryTreeDelete(root, 'U');
	InorderPrint(root);
}
