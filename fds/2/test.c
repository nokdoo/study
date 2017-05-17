#include <stdio.h>

union a{
	int a;
	char b;
};

int main(){
	int aa = 1;
	char bb = 'b';

	union a cc;
	cc.a = aa;

	printf("%d\n", cc.a);
}
