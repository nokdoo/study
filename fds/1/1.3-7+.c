#include <stdio.h>

int nfac(int n){
	int result = 1;
	while(n > 1){
		result *= n--;
	}
	return result;
}

int main(){
	int n;
	scanf("%d", &n);
	printf("%d\n", nfac(n));
}
