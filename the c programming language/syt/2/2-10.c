/*
	2-10
   	Rewrite the function lower, which converts upper case letters
	to lower case with a conditional expression instead of if-else.
	
   */

#include <stdio.h>

int main(){
	
	char c;
	while((c = getchar())!= EOF){
		printf("%c", ('A' <= c && c <= 'Z') ? c - 'A' + 'a' : c);

	}

	return 0;
}
