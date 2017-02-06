#include <stdio.h>

void strcat_(char *s, char *t){
	while(*s++ != '\0')
		;
	*--s;
	while((*s++ = *t++) != '\0');
}

int main(){
	char s[100] = "first";
	char *t = "second";

	strcat_(s, t);

	printf("%s\n", s);
}
