#include <stdio.h>
#include "../libs/getch_ungetch.c"

#define LINEWIDTH 15

int isprintable(char c){
	char *printable = "abcdefghijklmnopqrstuvwxyz0123456789";
	char *s;

	for(s = printable; *s != 0; s++){
		if(c == *s){
			return 1;
		}
	}

	return 0;
}

int main(){
	char out[LINEWIDTH+1];
	char c;
	int i = 0;

	while((c=getch()) != EOF){
		if(isprintable(c)){
			out[i++] = c;
		}else{
			if(i+4 > LINEWIDTH){
				out[i] = '\0';
				printf("%s\n", out);
				i = 4;
				printf("[%2x]", c);
			}else{
				printf("[%2x]", c);
				i += 4;
			}
		}
			if(i == LINEWIDTH){
				out[i] = '\0';
				printf("%s\n", out);
				i = 0;
			}else if(c == '\n'){
				out[i] = '\0';
				printf("%s", out);
				i = 0;
			}
	}
	
}
