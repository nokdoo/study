#include <stdio.h>

#define MAXLINE 100

int main(){
	double sum, atof(char []);
	char line[MAXLINE];
	int getline2(char line[], int max);

	sum = 0;
	while(getline2(line, MAXLINE) > 0)
		printf("\t%g\n", sum+= atof(line));
	return 0;
}
