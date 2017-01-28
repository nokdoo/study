#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void swap(char s[], int a, int b);

int main(){
	char s[] = "0123456789";
	reverse(s);
	printf("%s\n", s);
}

void reverse(char s[]){

	static int left = 0;
	static int len = 0;


	if(left > len/2)
		return;

	if(left == 0){
		len = strlen(s) - 1;
	}

	swap(s, left++, len-left);
	reverse(s);
}

void swap(char s[], int a, int b){
	char tmp;
	tmp = s[a];
	s[a] = s[b];
	s[b] = tmp;
}
