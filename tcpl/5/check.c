#include <stdio.h>
#include <ctype.h>
// 0 - digit, 1 - operator, 2 - error
int check(char *s){
	char c = s[0];
	if(isdigit(c)){
		return 0;
	}else if(c == '+' || c == '*'){
		return c;
	}

	return 2;
}

