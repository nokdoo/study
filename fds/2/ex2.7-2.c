#include <stdio.h>

void convt(char *s, int start, int length){
	s += start+length;
	while(*s != '\0'){
		*(s-length) = *s;
		*s++;
	}
	*(s-length) = '\0';
}

int main(){
	char test[] = "abcdefg";
	convt(test, 2, 3);
	printf("%s\n", test);
}
