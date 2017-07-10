#include <stdio.h>
#include <math.h>

int main(){
	double x;

	x = -125125124;

	*(((int *)&x) + 1) &= 0x7fffffff;

	printf("%f", x);
}
