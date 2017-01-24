/*
   	Write a function escape(s, t) that converts characters like newline and tab 
	into visible escape sequences like \n and \t as it copies the string t to s.
	Use a switch. Write a function for the other direction as well, 
	converting escape sequences into the real characters
	*/



#include <stdio.h>

char escape(unsigned char c){

	switch(c){
		case '\t':
			printf("\\");
			return 't';
			break;
		case '\n':
			printf("\\");
			return 'n';
			break;
		default :
			return c;
			break;
	}
}

int main(){
	char c;

	while((c = getchar()) != EOF){
			
		printf("%c", escape(c));
	}
}
