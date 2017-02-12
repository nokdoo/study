#include <stdio.h>
#include "../libs/stack.c"
#include "./atof.c"
#include "./check.c"

int main(int argc, char *argv[]){

	int i = 1;
	char type;
	if(argc == 1){
		printf("xxxx\n");
		return 0;
	}
	while(i<argc){
		printf("%s  \n", argv[i]);
		if(!check(argv[i])){
			return 0;
		}
		i++;
	}
printf("오냐\n");
	i = 1;
	while(i<argc){
		type = argv[i][0];
		printf("%c\n", argv[i][0]);
		switch(type){
			case '+':
				push(pop() - pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			default:
				push(atof(argv[i]));
		}
		i++;
	}
	printf("%lf\n", stack[0]);
	return 0;
}
