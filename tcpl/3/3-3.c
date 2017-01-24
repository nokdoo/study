/*
   	Write a function expand(s1, s2)
	that expands shorthand notations like a-z in the string s1
	into the equivalent complete list abc...xyz in s2.
	Allow for letters of either case and digits, and be prepared to handle cases
	like a-b-c and a-z0-9 and -a-z.
	Arrange that a leading or trailing - is taken literally.
	*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char compare_type(char a, char b){
	if(isalpha(a) && isalpha(b)){
		if(('a' <= a && a <= 'z') && ('a' <= b && b <= 'z')){
			return 1;
		}
		if(('A' <= a && a <= 'Z') && ('A' <= b && b <= 'Z')){
			return 1;
		}
	}
	else if(isdigit(a) && isdigit(b))
		return 1;
	else return 0;
}

void expand(char s1[], char s2[]){
	int i, j = 0;
	int gap, sign;
	
	for(i = 0; s1[i] != '\0'; i++, j++){
		s2[j] = s1[i];
		if(j>1){
			if(s2[j-1] == '-' && compare_type(s2[j-2], s2[j])){
				gap = s2[j] - s2[j-2];
				sign = (gap>=0) ? 1 : -1;
				printf("%c, %c, %d, %d\n", s2[j], s2[j-2], i, j);
				gap *= sign;
				j--;
				for(; gap>0; gap--, j++){
					s2[j] = s2[j-1] + 1*sign;
				}
				j--;
			}
		}
	}
	s2[j] = '\0';
}

int main(){
	char s1[100] = "hello ha ha -a-g-a9-5-";
	char s2[200];
	int i;
	expand(s1, s2);
	
	printf("%s", s2);
	
}
