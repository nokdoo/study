#include <stdio.h>
#include <string.h>
int strrindex(char s[], char t[]){

	
	int i, j;
	for(i = strlen(s)-1; i >= 0; i--){
	
		for(j = strlen(t)-1; s[i] == t[j]; i--, j--){
			if(j==0){

				return i;
			}
		}
	
	}
	return -1;//-1
}
