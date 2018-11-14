#include <stdio.h>

#define ARRAY_MAX 50

main(){
	char c;
	char state = '0';
	int stack_idx = 0;
	char stack[50] = {'\0'};

	while((c = getchar()) != EOF){

		if(c == '(' || c == '{'){
			if(state == '\'' || state == '\"' ){
				
			}else{
				stack[stack_idx] = c;
				stack_idx++;
				state = c;
			}
		}else if(c == '\''){
			if(state == '\''){
				stack[stack_idx] = '\0';
				stack_idx--;
			}else if(state == '\"'){
				
			}else{
				stack[stack_idx] = '\'';
				stack_idx++;
				state = c;
			}
		}else if(c == '\"'){
			if(state == '\''){
				
			}else if(c == '\"'){
				stack[stack_idx] == '\0';
				stack_idx--;
			}else{
				stack[stack_idx] == c;
				stack_idx++;
				state = c;
			}
		}else if(c == ')'){
			if(state == '('){
				stack[stack_idx] = '\0';
				stack_idx--;
			}
		}else if(c == '}'){
			if(state == '{'){
				stack[stack_idx] = '\0';
				stack_idx--;
			}
		}
		printf("%c", c);
	}
	if(state == 0){
		printf("\n\n\nno error!\n\n\n");
	}
}
