#include <stdio.h>
#include <stdlib.h>

struct node{
	int x1, x2, y1, y2;
};

int cmpa(const void *a, const void *b){
	return ((struct node *)a)->x1 - ((struct node *)b)->x1; 
}

int main(){
	int n;
	scanf("%d", &n);
	struct node arr[n]; 
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i].x1);
		scanf("%d", &arr[i].y1);
		scanf("%d", &arr[i].x2);
		arr[i].y2 = 0;
	}
	qsort(arr, n, sizeof(struct node), cmpa);	

//내 방식대로 풀어보자.

	return 0;
}
