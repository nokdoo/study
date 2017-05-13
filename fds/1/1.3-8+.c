#include <stdio.h>

int fb(int *f1, int *f2, int n){
	int result = *f1  + *f2;

	if(n-- <= 0){
		return result;
	}else{
		*f1 = *f2;
		*f2 = result;
		return fb(f1, f2, n);
	}
	return -1;
}

int main(){
	int f1 = 0, f2 = 1, n;
	scanf("%d", &n);
	printf("%d", fb(&f1, &f2, n-2));
}
