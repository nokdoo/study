#include <stdio.h>
#include <string.h>
#define max_string_size 100
#define max_pattern_size 100

int pmatch();
void fail(char *pat, int n);
int failure[max_pattern_size];
char string[max_string_size] = "babcbabcabcaabcabcabcacabc";
char pat[max_pattern_size] = "abcabcacab";

void fail(char *pat, int n){
	int i;
	int j;
	failure[0] = -1;
	for(j = 1; j < n; j++){
		i = failure[j-1];
		while((pat[j] != pat[i+1]) && (i >= 0))
			i = failure[i];
		if(pat[j] == pat[i+1])
			failure[j] = i+1;
		else 
			failure[j] = -1;
	}
	failure[j+1] = '\0';
}

int pmatch(char *string, char *pat){
	int i = 0, j = 0;
	int lens = strlen(string);
	int lenp = strlen(pat);
	while(i < lens && j < lenp){
		if(string[i] == pat[j]){
			i++;
			j++;
		}else if(j == 0)
			i++;
		else
			j = failure[j-1] + 1;
	}
	return (( j == lenp)?(i-lenp) : -1 );
}

int main(){
	
	int i = 0;
	int n = strlen(pat);
	int m = strlen(string);
	fail(pat, n);
	int mn = pmatch(string, pat);
	while(i<n)
		printf("%d", failure[i++]);
	printf("\n");
	i = 0;
	while(i<m)
		printf("%c", string[i++]);
	printf("\n");

	i=0;
	while(i++<mn)
		printf(" ");

	i=0;
	while(i<n)
		printf("%c", pat[i++]);
	printf("\n");

	return 0;
}

