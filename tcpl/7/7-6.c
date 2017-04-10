#include <stdio.h>

int main(int argc, char *argv[]){
	
	char *prog = argv[0];
	FILE *f1 = fopen(*++argv, "r");
	FILE *f2 = fopen(*++argv, "r");

	int linenum = 0;

	char c1;
	char c2;

	int rst = 1;

	while( (c1 = getc(f1)) != EOF && (c2 = getc(f2)) != EOF ){
		if(c1 != c2){
			printf("error");
			rst = 0;
			break;
		}
		if(c1 == '\n')
			linenum++;
	}

	printf("%d", rst);


	return 0;

}
