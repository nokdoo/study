#include <stdio.h>
void printd(int n, char s[]);
int main(){
	int a = -1234567890;
	char s[100];
	printd(a, s);
	printf("%s\n", s);
	return 0;
}

void printd(int n, char s[]){
	static int i = 0;
	if(n<0){
		putchar('-');
		n = -n;
	}
	if(n/10)
		printd(n/10, s);
	s[i++] = (n % 10 + '0');
	s[i] = '\0';
}
