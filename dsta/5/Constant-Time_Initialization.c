/*	Constant-Time Initialization.c */
#include <stdio.h>
#include <stdlib.h>
#include "../std.h"

#define array_size 10

struct Array{
	int Default;
	int Count;
	int M[array_size];
	int When[array_size];
	int Which[array_size];
};

void Initialize(struct Array *A, int value){
	A->Count = 0;	
	A->Default = value;
}

boolean Valid(int i, struct Array *A){
	return ((0 <= A->When[i]) ? ((A->When[i] < A->Count) ? true : false) : false) && A->Which[A->When[i]] == i;
}

int Access(int i, struct Array *A){
	if(Valid(i, A)) return A->M[i];
	else return A->Default;
}

void Assign(struct Array *A, int i, int value){
	if(!Valid(i, A)){
		A->When[i] = A->Count;
		A->Which[A->Count] = i;
		A->Count++;
	}
	A->M[i] = value;
}

void printA(struct Array *A){
	int i = 0;
	while(i<array_size){
		printf("%d ", Access(i, A));
		i++;
	}
	printf("\n");
}

int main(){
	struct Array *A = (struct Array *) malloc(sizeof(struct Array));
	Initialize(A, 999);
	Assign(A, 6, 10);
	Assign(A, 1, 10);
	Assign(A, 3, 10);
	printA(A);
}
