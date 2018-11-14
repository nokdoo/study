#include <stdio.h>
#include "minscanf.c"

int main(){
	int a;
	minscanf("%d", &a);
	printf("%d", a);
}
