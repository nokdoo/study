#include <stdio.h>
#include <string.h>
#include "../libs/getline_.c"
#define MAXLINE 1000

int getline_(char *line, int max);

int main(int argc, char *argv[]){
	char line[MAXLINE];
	int found = 0;

	if(argc != 2){
		printf("Usage: find pattern\n");
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
