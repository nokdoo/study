#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n;

void swap(int *a, int *b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void printarr(int *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}


void qsort_(int *arr, int left, int right){
	if(left >= right)
		return;
	int p = left;
	int i = left;
	int j = left+1;
	for(; j<=right; j++){
		if(arr[p] > arr[j]){
			swap(&arr[++i], &arr[j]);
		}
	}
	printarr(arr, n);
	swap(&arr[i], &arr[p]);
	qsort_(arr, left, i);
	qsort_(arr, i+1, right);
}


int main() {
	scanf("%d", &n);
	int *arr = (int *) malloc(sizeof(int)*n);
	int i;
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	qsort_(arr, 0, n-1);
	printarr(arr, n);
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	return 0;
}

