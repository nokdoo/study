#include <stdio.h>
#include "fgets.c"
#define PAGELINE 23

void printfile(char *prog);

int main(int argc, char *argv[]){
	FILE *fp;
	while(--argc>0){
		printfile(argv[argc]);
	}

	return 0;
}

void printfile(char *prog){
	FILE *fp;
	int pl = 0;
	char *flag;
	char line[1000];
	int pn = 0;
	fp = fopen(prog, "r");
	while(fgets(line, 1000, fp) != NULL){
		if(pl%PAGELINE == 0){
			printf("file : %s // pagenum : %d\n", prog, ++pn);
		}
		printf("%s", line);
		pl++;
	}

	while(pl++%PAGELINE != 0){
		printf("\n");
	}
}
