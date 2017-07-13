#include <stdio.h>

#define M 5
#define N 5

int map[M][N] = {
	1,2,2,2,5,
	1,4,4,3,1,
	2,1,1,1,2,
	1,3,5,1,1,
	1,5,1,2,2
};

int max(int a, int b){
	return a>b ? a : b;
}

int max_joy(int m, int n){
	if(m == 0 && n == 0){
		return map[0][0];
	}
	if(m == 0){
		return max_joy(m, n-1) + map[m][n];
	}
	if(n == 0){
		return max_joy(m-1, n) + map[m][n];
	}
	return max(max_joy(m-1, n), max_joy(m, n-1)) + map[m][n];
}

int main(){
	printf("%d\n", max_joy(4, 4));	
}
