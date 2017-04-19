#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX_SIZE 101
#define SWAP(x,y,t) ((t) = (x), (x)=(y), (y)=(t))
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y)) ? 0: 1)
void sort(int [], int);
int binsearch(int list[], int searchnum, int left, int right){
	int middle;
	while(left <= right){
		middle = (left + right) /2;
		switch(COMPARE(list[middle], searchnum)){
			case -1:
				left = middle + 1;
				break;
			case 0:
				return middle;
			case 1:
				right = middle - 1;
		}
	}
	return -1;
}
void main(){
	int i, n, m;
	int list[MAX_SIZE];
	printf("insert data\n");
	scanf("%d", &n);
	if(n < 1 || n > MAX_SIZE){
		fprintf(stderr, "error\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i<n; i++){
		list[i] = rand() % 1000;
		printf("%d ", list[i]);
	}
	sort(list, n);
	printf("\n sorted \n");
	for(i = 0; i<n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
	
	scanf("%d", &m);
	printf("\n\n%d", binsearch(list, m, 0, n-1));
}
void sort(int list[], int n){
	int i, j, min, temp;
	for(i = 0; i<n-1; i++){
		min = i;
		for(j = i+1; j<n; j++)
			if(list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}
