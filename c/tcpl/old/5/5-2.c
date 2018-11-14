#include <stdio.h>
#include <ctype.h>
#include "../libs/getch_ungetch.c"

void getfloat(float *);

int main(){

	float pf = 0.0;

	getfloat(&pf);

	printf("%f\n", pf);
	
	return 0;
}

void getfloat(float *pf){
	char c;
	int sign;
	float f = 1.0;
	while(isspace(c = getch()))
		;

	if(!isdigit(c) && c != EOF && c != '-' && c != '+'){
		ungetch(c);
		return ;
	}

	sign = (c == '-') ? -1 : 1;

	if(c == '+' || c == '-'){
		c = getch();
	}

	while(isdigit(c)){
		*pf = 10 * *pf + (c-'0');
		c = getch();
	}

	printf("%f\n\n\n", *pf);


	if(c == '.'){
		c = getch();
		while(isdigit(c)){
			printf("%csdasdasd\n", c);
			printf("%f\n", *pf);
			*pf += (f=f/10) * (c-'0');
			c = getch();
		}
	}

	*pf *= sign;

	if(c!=EOF){
		ungetch(c);
	}
}
