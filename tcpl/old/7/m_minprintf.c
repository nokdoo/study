#include <stdio.h>
#include "minprintf.c"

int main(){
	int d = 10;
	double e = 29.9;
	minprintf("%d, %f", d, e);
	return 0;
}
