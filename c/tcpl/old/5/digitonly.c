#include <stdio.h>
#include <ctype.h>

int digitonly(char *s){
	
	printf("%s\n", s);
	while(*s != '\0'){
		if(!isdigit(*s++)){
			printf("error : no number");
			return 0;
		}
	}
	return 1;
}

