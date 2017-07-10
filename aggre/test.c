#include <stdio.h>

int main(){
	double a = 8;
	printf("%d\n", *(((int *)&a)+1));
	printf("%d\n", *((int *)&a));
	printf("%p\n", &a);
}
