#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

struct node{
	int x1, y1, x2;
};

struct answerNode{
	int x, y;
};

int cmpx1(const void *a, const void *b){
	return ((struct node *)a)->x1 - ((struct node *)b)->x1; 
}
int cmpx2(const void *a, const void *b){
	return ((struct node *)a)->x2 - ((struct node *)b)->x2; 
}

int main(){
	int n;
	scanf("%d", &n);
	struct node arr1[n];
	for(int i=0; i<n; i++){
		scanf("%d", &arr1[i].x1);
		scanf("%d", &arr1[i].y1);
		scanf("%d", &arr1[i].x2);
	}
	qsort(arr1, n, sizeof(struct node), cmpx1);
	struct node arr2[n];
	memcpy(arr2, arr1, sizeof(arr1));
	qsort(arr2, n, sizeof(struct node), cmpx2);

	return 0;
}
