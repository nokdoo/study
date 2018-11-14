#include <stdio.h>
#include <string.h>
#include "rwlines.c"
#include "../libs/getline_.c"
#include "alloc.c"
#include "../libs/qsort.c"


#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

//void qsort(char *lineptr[], int left, int right);

main(){
	int nlines;
	
	if((nlines = readlines(lineptr, MAXLINES)) >= 0){
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("error : input too big to sort\n");
		return 1;
	}
}
