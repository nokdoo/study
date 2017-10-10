#include "tree.h"
#define max(x,y) ((x) > (y))? (x) : (y)

int OrdHt(struct node *node){
	if(node == NULL){
		return 0;
	}else if(node->left == NULL){
		OrdHt(node->right);
	}else{
		return max(1+OrdHt(node->left), OrdHt(node->right));
		
	}



}

int main(){
	struct node *root = makeBinTree();
	int hight = OrdHt(root);
	printf("%d\n", hight);
}
