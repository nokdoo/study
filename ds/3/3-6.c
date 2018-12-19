/*
	Contiguous-Memory (stack)
	+
	MergeSort
	+
	BinarySearch
*/

#include "3-5.h"


int T[8] = {6, 5, 3, 1, 8, 7, 2, 4};

stack *S;

void printT(int start, int end){
	for(; start<=end; start++){
		printf("%d", T[start]);
	
	}
	printf("\n");
}

void Merge(int a, int middle, int b){
	int tmp[b+1];
	int i;
	for(i =0; i<=b; i++){
		tmp[i] = T[i];
	}	
	int j;
	i = a;
	j = middle+1;
	int ti=a;

	while(i<=middle && j<=b){
		if(tmp[i] < tmp[j]){
			T[ti] = tmp[i];
			i++;
		}else{
			T[ti] = tmp[j];
			j++;
		}
		ti++;
	}
	
	for(; i<=middle; i++, ti++){
		T[ti] = tmp[i];
	}

	for(; j<=b; j++, ti++){
		T[ti] = tmp[j];
	}
}

void MergeSort(){
	int a, b, middle;
	b = Pop(S);
	middle = Pop(S);
	a = Pop(S);
	if(a>=b){
		return;
	}
	
	Push(a, S);
	Push((a+middle)/2, S);
	Push(middle, S);
	MergeSort();

	Push(middle+1, S);
	Push(((middle+1)+b)/2, S);
	Push(b, S);
	MergeSort();

	Merge(a, middle, b);
}

int BinarySearch(int start, int end, int key){
	if(start > end) return -1;

	int middle = (start + end) / 2;

	if(T[middle] == key) {printf("%d\n", key); printT(0, 7); return middle;}

	if(T[middle] < key) BinarySearch(middle+1, end, key);

	if(T[middle] > key) BinarySearch(start, middle-1, key);
}

int main(){
	S = MakeEmptyStack();
	int a = 0;
	int b = 7;
	Push(a, S);
	Push((a+b)/2, S);
	Push(b, S);
	MergeSort();
	printT(a, b);
	printf("%d", BinarySearch(a, b, 3));
}
