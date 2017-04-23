//4-6 문제의 의미를 모르겠다...
//4-9 이미 EOF를 막고 있는데...?

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100
#define ALPHA 'A'

int getop(char []);
void push(double);
double pop(void);

int sp = 0;
double val[MAXVAL];

char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);

void cclear();
void viewstack();
void cmd(char []);
void ungets(char s[]);

int main(){

	int type;
	double op1;
	double op2;
	char s[MAXOP];

	while((type = getop(s)) != EOF){
		switch(type){
			case NUMBER:
				push(atof(s));
				break;
			case ALPHA:
				cmd(s);
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				op1 = pop();
				push(op1 - op2);
				break;
			case '/':
				op2 = pop();
				if(op2 != 0.0)
					push(pop() / op2);
				else
					printf("error : zero divisor\n");
				break;
			case '%':
				op2 = pop();
				op1 = pop();
				if(op2 != 0.0)
					push(op1 - (int)(op1/op2)*op2);
				else
					printf("error: zero divisor\n");
				break;
			case 's':
				if(sp <= 1){
					printf("error : 's'\n");
				}else{
					viewstack();
					op2 = pop(); // for swap;
					op1 = pop();
					push(op2);
					push(op1);
					viewstack();
				}
				break;
			case 'c':
				if(sp>0){
					cclear();
				}else
					printf("error : 'c'\n");
				break;
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error : unknown command %s\n", s);
				break;
		}
	}

	return 0;

}

void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void){
	if(sp>0)
		return val[--sp];
	else{
		printf("error: stack empty\n");
		return 0.0;
	}
}

int getop(char s[]){
	int i,c;

	while((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if(!isdigit(c) && c != '.' && c != '-' && !isalpha(c))
		return c;
	i = 0;
	if(c == '-'){
		while(isdigit(s[++i] = c = getch()))
			;
		if(i == 1){
			s[1] = '\0';
			ungetch(c);
			return '-';
		}
	}
	if(isalpha(c)){
		while(isalpha(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if(c != EOF)
			ungetch(c);
		return ALPHA;
	}
	if(isdigit(c))
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

int getch(void){
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
	if(bufp >= BUFSIZE){
		printf("ungetch: too many characters\n");
	}else
		buf[bufp++] = c;
}

void cclear(){
	while(sp>0){
		val[sp--] = 0;
	}
}

void viewstack(){
	int i = sp;
	while(i > 0){
		printf("%f ", val[--i]);
	}
	printf("\n");
}

void cmd(char s[]){
	double op2;
	int size;
	if(strcmp(s, "sin") == 0 ){
		push(sin(pop()));
	}else if(strcmp(s, "cos") == 0){
		push(cos(pop()));
	}else if(strcmp(s, "exp") == 0){
		push(exp(pop()));
	}else if(strcmp(s, "pow") == 0){
		op2 = pop();
		push(pow(pop(), op2));
	}else if(strcmp(s, "ungets") == 0){
		size = strlen(s);
		printf("%s\n", s);
		ungets(s);
		while(size>0){
			printf("%c", getch());
			size--;
		}
		printf("\n");
	}else{
		printf("error : cmd");
	}
}	

void ungets(char s[]){
	int i = strlen(s);
	while(i>0){
		ungetch(s[i-1]);
		i--;
	}
}
