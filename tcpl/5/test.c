#include <stdio.h>
#include "alloc.c"
#include <string.h>

int main(){
	char *test[10];
	char *test0 = "test0";
	char *test1 = "test1";

	test[0] = test0;
	test[1] = test1;

	printf("%s", test[0]);

}
