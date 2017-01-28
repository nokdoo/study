#include <stdio.h>
#include "getint.c"
#include "../libs/getch_ungetch.c"


int main(){
	int pn;
	while(getint(&pn) != EOF)
		printf("%d ", pn);
		;
	return 0;
}
