#include <stdio.h>
#include <ctype.h>

double atof(char *s){
	double val = 0;
	while(isdigit(*s)){
		val = val*10 + (*s++ - '0');
	}
	return val;
}
