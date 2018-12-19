/*
	Encoding Tree
	
	p146
	Tree
*/

#include "5.2tree.h"

void TreeDecode(struct node *T, char *inputstream){
	struct node *P = T;
	
	while(*inputstream != '\0'){
		if(*inputstream == '0') P = P->left;
		else if(*inputstream == '1') P = P->right;
		*inputstream++;
		if(P->data != '\0'){
			printf("%c", P->data);
			P = T;
		}
	}

}

int main(){
	
	struct node *T = makeBinTree();

	char *inputstream = "10000001010110111100111";

	TreeDecode(T, inputstream);

	return 0;
}
