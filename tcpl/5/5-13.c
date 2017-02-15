#include <stdio.h>
#include "../libs/atoi.c"
#include "../libs/getline_.c"
#include <string.h>
#define MAXSIZE 1000

char line[MAXSIZE];
char linebuf[1000];
int main(int argc, char *argv[]){

	char *pline[1000];
	int n = 10;
	int nline = 0;
	int i;
	int len;
	char *p = linebuf;

	if((*(++argv))[0] == '-'){
		n = atoi(*argv+1);
	}

	while(len = getline_(line, 1000)){
		if(len != 0){
			strcpy(p, line);
			pline[i++] = p;
			p += len +1;
			nline++;
		}
	}
	printf("n : %d\n",  n);
	printf("nline : %d\n", nline);
	i = (nline > n) ? (nline - n) : 0;

	printf("i : %d\n", i);

	while(i<nline){
		printf("%s", pline[i++]);
	}

	return 0;
}
