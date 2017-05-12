// 1 2 3 4 5 6 6 6 6 7 7 7
// 처럼 찾으려는 숫자가 연속적일 경우
// 인덱스의 범위를 출력하자.

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAXSIZE 101
#define COMPARE(a, b) ( ((a) > (b)) ? 1 : ( ((a) == (b)) ? 0 : -1 ))

void sort(int list[], int n);
void swap(int *a, int *b);
void print(int list[], int n);
void binsearch(int list[], int find, int left, int right);
void startAt(int list[], int find, int left, int right);
void endAt(int list[], int find, int left, int right);

int main(){
	int i, n;
	int list[MAXSIZE];
	int find;
	printf("배열의 최대 크기 : %d\n배열의 크기 입력...\n", MAXSIZE);
	scanf("%d", &n);
	if(n > MAXSIZE || n < 1){
		fprintf(stderr, "error\n");
		exit(1);
	}
	printf("생성된 배열\n");
	for(i = 0; i < n; i++){
		list[i] = rand() % n;
		printf("%d ", list[i]);
		if(i % 100 == 0 && i != 0){
			printf("\n");
		}
	}
	printf("\n\n");
	sort(list, n);
	printf("정렬된 배열\n");
	print(list, n);
	printf("\n\n");
	printf("찾고자 하는 숫자...\n");
	scanf("%d", &find);
	binsearch(list, find, 0, n);
}

void sort(int list[], int n){
	int i, j, min;
	for(i = 0; i<n-1; i++){
		min = i;
		for(j = i+1; j < n; j++){
			if(list[j] < list[min]){
				min = j;
			}
		}
		swap(&list[min], &list[i]);
	}
}

void swap(int *a, int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void print(int list[], int n){
	int i;
	for(i = 0; i<n; i++){
		printf("%d ", list[i]);
		if(i % 100 == 0 && i != 0){
			printf("\n");
		}
	}
}

void binsearch(int list[], int find, int left, int right){
	int mid = (left+right)/2;
	int cmp = COMPARE(list[mid], find);
	if(cmp == 1){
		binsearch(list, find, left, mid);
	}else if(cmp == -1){
		binsearch(list, find, mid+1, right);
	}else{
		startAt(list, find, left, mid);
		endAt(list, find, mid, right);
	}
}

void startAt(int list[], int find, int left, int right){
	int mid = (left + right) / 2;
	int cmp = COMPARE(list[mid], find);
	if(cmp == 0){
		if(left == mid){
			printf("%d - ", left);
			return;
		}
		startAt(list, find, left, mid);
	}else{
		startAt(list, find, mid+1, right);
	}
}

void endAt(int list[], int find, int left, int right){
	int mid = (left + right) / 2;
	int cmp = COMPARE(list[mid], find);
	if(cmp == 0){
		if(left == mid){
			printf("%d\n", left);
			return;
		}
		endAt(list, find, mid, right);
	}else{
		endAt(list, find, left, mid);
	}
}
