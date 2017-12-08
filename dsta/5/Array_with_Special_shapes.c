/*
	A  B  C  D
  A 0  2  7  5
  B 2  0  13 3
  C 7  13 0  25
  D 5  3  25 0
*/

#include <stdio.h>
#include <stdlib.h>

#define N 4
#define CNT  N*(N+1)/2

int Array[N][N] = {
	0, 2, 7, 5,
	2, 0, 13, 3,
	7, 13, 0, 25,
	5, 3, 25, 0
};

void printM(int *M){
	for(int i=0; i<CNT; i++){
		printf("%d ", M[i]);
	}
	printf("\n");
}

void AccessM(int *M, int i, int j){
	if(i > j){
		int tmp = i;
		i = j;
		j = tmp;
	}
	int inc = (N*i + (i - i*i) / 2 + j);
	printf("%d\n", inc);	
	printf("%d\n", *(M+inc));
}

int main(){
	int *M = (int *) malloc(sizeof(int)*CNT);
	for(int i=0, k=0; i<N; i++){
		for(int j=i; j<N; j++, k++){
			M[k] = Array[i][j];
		}
	}
	
	printM(M);
	
	AccessM(M, 2, 0);
}
