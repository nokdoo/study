#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAXLEN 10000
#define LESS -1
#define EQUAL 0
#define GREATER 1

int getlen(char *s){
	int i=0;
	while(*s++){
		i++;
	}
	return i;
}

void strcpy_(char *a, char *b){
	while(*b){
		*a++ = *b++;
	}
	*a='\0';
}

void swap(char **a, char **b){
	//char *tmp = (char *) malloc(sizeof(char)*MAXLEN);
	//strcpy_(tmp, b);
	//strcpy_(b, a);
	//strcpy_(a, tmp);
	char *tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

int cmp(char *a, char *b){
	int len_a = getlen(a);
	int len_b = getlen(b);
	int i, ret;
	if(len_a > len_b){
		return GREATER;
	}else if(len_a < len_b){
		return LESS;
	}else{
		ret = strcmp(a, b);
		if(ret > 0){
			return GREATER;
		}else if(ret < 0){
			return LESS;
		}else if(ret == 0){
			return EQUAL;
		}else{
			printf("error\n");
			exit(1);
		}
	}
	return 0;
}

void sort(char **arr, long long n){

	//퀵소트 때리자...
	int i, j, min = 0;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(cmp(arr[min], arr[j]) == GREATER){
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
		;
	}

}

void quickSort(char **arr, int left, int right) {
	if(left < right){
		int p = left, i = left, j = left+1;
		while(j <= right){
			if(cmp(arr[p], arr[j]) == GREATER){
				swap(&arr[++i], &arr[j]);
			}
			j++;
		}
		swap(&arr[p], &arr[i]);
		quickSort(arr, left, i-1);
		quickSort(arr, i+1, right);
	}
}

int main(){
	long long n;
	scanf("%lld", &n);
	char **arr = (char **) malloc(sizeof(char *)*n);
	long long i;
	for(i = 0; i < n; i++){
		arr[i] = (char *) malloc(sizeof(char)*MAXLEN);
		scanf("%s", arr[i]);
	}

	quickSort(arr, 0, n-1);
	//sort(arr, n);

	for(i = 0; i < n; i ++){
		printf("%s\n", arr[i]);
	}

	// Enter your code here. Read input from STDIN. Print output to STDOUT
	return 0;
}

