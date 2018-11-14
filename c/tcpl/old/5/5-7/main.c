#include <stdio.h>
#include <string.h>


#define ALLOCSIZE_ 10000

#include "rwlines.c"
#include "../../libs/getline_.c"
#include "../../libs/qsort.c"


#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *, char *, char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

main(){
	int nlines;
	
	char allocbuf_[ALLOCSIZE_];
	char *allocp_ = allocbuf_;
	
	
	if((nlines = readlines(allocbuf_, allocp_, lineptr, MAXLINES)) >= 0){
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	}else{
		printf("error : input too big to sort\n");
		return 1;
	}
}
