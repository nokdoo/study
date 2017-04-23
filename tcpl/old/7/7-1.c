#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(int argc, char **argv){
	int (*convert[2])(int) = {tolower, toupper};
	char cas;
	char c;
	if(argc>0){
		if(strcmp(argv[0], "upper") == 0){
			cas = 1;
		}else if(strcmp(argv[0], "lower") == 0){
			cas = 0;
		}
		while((c = getchar()) != EOF){
			putchar((*convert[cas])((char)c));
		}
	}
	return 0;
}
