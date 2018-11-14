#include <stdio.h>
#include "../libs/stack.c"
#include "check.c"
#include "atof.c"

int main(int agrc, char *agrv[]){
	
	int type;
	int i = 1;
	int i2 = 0;

	while(i<agrc){
		printf("%s - test\n", agrv[i]);
		for(i2 = 0; i2 < sp; i2++){
			printf("%lf, ", stack[i2]);
		}
		printf("\n");
		switch(type = check(agrv[i])){
			case 0:
				push(atof(agrv[i]));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
		}
		i++;
	}

	printf("%lf\n", stack[0]);
	return 0;
}	
