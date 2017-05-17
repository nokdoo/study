#include <stdio.h>

int main(){
	
	int a[2] = {5, 4};

	printf("%p, %d\n", a, a[0]);
	printf("%p, %d\n", a+1, *(a+1));


}
