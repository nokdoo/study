#include "4.12.h"

int main(){
	struct node *root = makeBinTree();
	que = (struct que *) malloc(sizeof(struct que));
	que->node = root;
	que->next = NULL;
	printf("test\n");
	Traverse();
}
