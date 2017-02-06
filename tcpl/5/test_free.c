#include <stdio.h>
#include <string.h>
#include "alloc.c"
int main(){
	printf("%d\n", *allocp);
	char *b = alloc(10);
	strcpy(b, "0123456789");
	printf("%s\n", b);
	afree(b);
	printf("%d\n", *allocp);
	printf("%s\n", b);
	//char a[] = "0123456789";
	//char *b[10];
}
