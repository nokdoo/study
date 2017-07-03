#include <stdio.h>

int c[26];

int count(char *s){
	
	int cnt = 0;

	while(*s != '\0'){
		if(c[*s++-'a']++ == 0){

			cnt++;
		}
	}

	return cnt;

}	

int main(){
	char s[100];
	scanf("%s", s);
	int a = count(s);
	printf("%d\n", a);
	printf("%s\n", s);
}
