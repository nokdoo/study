#include <stdio.h>

void convt(char *s, char c){
	while(*s != c){
		if(*s++ == '\0'){
			return;
		}
	}
	while(*s != '\0'){
		*s = *(s+1);
		*s++;
	}
}

int main(){
	char s[] = "abccdefgh";
	char c = 'b';
	convt(s, c);
	printf("%s\n", s);
}
