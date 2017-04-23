#include <stdio.h>
#include <string.h>
#include "numcmp.c"
#include "../5/qsort_.c"
#include "../libs/swap.c"
#include "rwlines.c"
#include "strcmp_.c"

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_(void *lineptr[], int left, int right,
		int (*comp)(void *, void *), int reverse);

int numcmp(char const *, char const *);
int strcmp_(char const *s, char const *t);

int main(int argc, char *argv[]){
	int nlines;
	int numeric = 0;
	int reverse = 1;

	while(argc>1){
		if(strcmp_(argv[argc-1], "-n") == 0){
			numeric = 1;
		}else if(strcmp_(argv[argc-1], "-r") == 0){
			reverse = -1;
		}
		argc--;
	}

	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		qsort_((void **) lineptr, 0, nlines-1, 
			(int (*)(void *, void *))(numeric ? numcmp : strcmp_),
			reverse);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("input too big to sort\n");
		return 1;
	}
}	
