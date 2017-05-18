#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, int *argv[]){
	FILE *fp;
	char filename[30];
	int i;
	if(argc>2){
		fprintf(stderr, "1개만입력\n");
		exit(1);
	}
	*++argv;
	for(i = 0; i<3; i++){
		printf("%c", *(*argv)++);
	}
}
