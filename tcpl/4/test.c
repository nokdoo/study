#include <stdio.h>

void test(char s[]);

int main(){

	char s[] = "testhaha";
	printf("%s\n", s);
	test(s+3);

}

void test(char s[]){
	printf("%s\n", ++s);
	printf("%c", s[1]);
}
