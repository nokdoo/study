#include <stdio.h>
#include <string.h>
#include "../libs/getline_.c"
#define MAXLINE 1000

int getline_(char *line, int max);
char *fgets(char *s, int n, FILE *iop){
	register int c;
	register char *cs;
	cs = s;
	while(--n > 0 && (c = getc(iop)) != EOF){
		if((*cs++ = c) == '\n')
			break;
	}
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

int main(int argc, char *argv[]){
	char line[MAXLINE];
	int found = 0;
	char *prog;
	FILE *f1;

	if(argc > 2){
		prog = argv[2];
		f1 = fopen(argv[2], "r");
		while(fgets(line, MAXLINE, f1) != NULL){
			if(strstr(line, argv[1]) != NULL){
				printf("%s", line);
				found++;
			}
		}
	}else{
		while(getline_(line, MAXLINE) > 0){
			if(strstr(line, argv[1]) != NULL){
				printf("%s", line);
				found++;
			}
		}
	}
	return found;
}		
