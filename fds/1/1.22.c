#include <stdio.h>
#include <time.h>

#define MAX 100000

void selectsort(int a[], int max);

int main(){
	int i;
	int max = MAX;
	int a[MAX];
	clock_t start;
	clock_t stop;

	for(i = 0; i<max; i++){
		a[i] = max - i;
	}

	start = clock();
	selectsort(a, max);
	stop = clock();
	
	for(i = 0; i<max; i++){
		printf("%d ", a[i]);
	}
	printf("\n\n\n");
	printf("%lf", ((double)(stop-start)/CLOCKS_PER_SEC));
}

void selectsort(int a[], int max){
	int min = 0;
	int i, j;
	int tmp;
	for(i = 0; i<max-1; i++){
		for(j = i+1; j<max; j++){
			if(a[min] > a[j]){
				min = j;
			}
		}
		tmp = a[min];
		a[min] = a[i];
		a[i] = tmp;
	}
}
