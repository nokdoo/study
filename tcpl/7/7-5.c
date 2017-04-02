// 3 5 + 9 7 + 2 / * 10 -   :     54.00000

#include <stdio.h>
#include <stdarg.h>
#include "../libs/stack.c"

double pfcal(char *fmt, ...){
	va_list ap;
	char *p;
	int *ival;
	int result = 0;
	int flag = 0;
	double pre = 0;

	va_start(ap, fmt);
	for(p=fmt; *p; p++){
		if(*p == '('){
			flag++;
		}else if(*p == ')'){
			if(--flag<0){
				printf("error : --flag");
				break;
			}
		}else if(*p == '%'){
			switch(*++p){
				case 'd':
					ival = va_arg(ap, int *);
					if(scanf("%d", ival) != 1){
						break;
					}
					push(*ival);
				default:
					break;
			}
		}else if(*p == '+'){
			push(pop()+pop());
		}else if(*p == '-'){
			pre = pop();
			push(pop()-pre);
		}else if(*p == '*'){
			push(pop()*pop());
		}else if(*p == '/'){
			pre = pop();
			push(pop()/pre);
		}
	}

	va_end(ap);
	return pop();
}

int main(){
	int a;
	printf("%f", pfcal("%d%d+%d%d+%d/*%d-", &a, &a, &a, &a, &a, &a));

	return 0;
}
