/*
   	Write the function strrindex(s, t),
	which returns the position of the rightmost occurrence of t in ,
	or -1 if there is none
	*/

#include <stdio.h>

int main(){
	char t[] = "ould";
	char s[1000];

	while(getline2(s, 1000) > 0){
			printf("%d\n", strrindex(s, t));
	}

	return 0;
}
