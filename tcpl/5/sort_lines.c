#include <stdio.h>
#include <string.h>
#include "numcmp.c"
#include "../libs/qsort_.c"
#include "../libs/swap.c"
#include "rwlines.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
		int (*comp)(void *, void *));
int numcmp(char const*, char const*);

int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0;

	while

	//if(argc > 1 && strcmp(argv[1], "-n") == 0)
	//	numeric = 1;
	
	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		qsort_((void **) lineptr, 0, nlines-1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("input too big to sort\n");
		return 1;
	}
}	
