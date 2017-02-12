#include <stdio.h>

int operatoronly(char *s){
	while(*s != '\0'){
		if(*s != '+' && *s != '*' ){
			printf("error : no operator --- %c", *s);
			*s++;
			return 0;
		}
	}
	return 1;
}
