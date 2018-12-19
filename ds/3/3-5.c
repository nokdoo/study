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
	for(i=0; i<=b; i++){
		tmp[i] = T[i];
		printf("%d", T[i]);

	}
	printf("\n");
	int j;
	i = a;
	j = middle+1;
	int ti=a;

	printf("a: %d b: %d tmp[a]: %d tmp[b]: %d     ", a, b, tmp[a], tmp[b]);
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
	printT(a, middle);
	MergeSort();

	Push(middle+1, S);
	Push(((middle+1)+b)/2, S);
	Push(b, S);
	printT(middle+1, b);
	MergeSort();



	printf("merged : ");
	Merge(a, middle, b);
	printT(a, b);
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
}
