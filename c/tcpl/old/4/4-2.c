#include <stdio.h>
double xt_atof(char s[]);
int main(){

	char line[1000];
	int found = 0;

	while(getline2(line, 1000)>0){
		printf("%f\n", xt_atof(line));
	}	

	return 0;
}
