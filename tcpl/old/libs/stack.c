#define MAXVAL 100

int sp = 0;
double stack[MAXVAL];

void push(double f){
	if(sp < MAXVAL){
		stack[sp++] = f;
	}else{
		printf("error");
	}
}

double pop(void){
	if(sp>0){
		return stack[--sp];
	}else{
		printf("error");
		return 0.0;
	}
}

