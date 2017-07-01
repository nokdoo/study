#include <stdio.h>
#include <string.h>

#define MAX 100

char pat[MAX] = "abcabcacab";
int pat2[MAX];
char s[MAX] = "babcbabcabcaabcabcabcacabc";

void print(int pat2[]){
	int i = 0;
	while(i<10){
		printf("%d ", pat2[i++]);
	}
	printf("\n");
}

void setpat2(){
	int len = strlen(pat);
	pat2[0] = -1;
	int i;
	for(i=1; i<len; i++){
		if(pat[pat2[i-1]+1] == pat[i]){
			pat2[i] = pat2[i-1]+1;
		}else{
			pat2[i] = -1;
		}
	}
	print(pat2);
}

int getp(){
	int i, j;
	int len = strlen(pat);
	for(i=0, j=0; s[i]!='\0' && j<len; i++, j++){
		if(s[i] == pat[j]){
			continue;
		}else{
			j = pat2[j];
		}
	}
	return j;
}

int main(){
	int p;
	setpat2();
	p = getp();
	printf("%d\n", p);

}
