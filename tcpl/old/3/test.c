#include <stdio.h>
#include "itoa.h"

int main(){

	int a = -2147483648;
	char b[64];

	itoa(a, b);

	printf("%s", b);


	
}
