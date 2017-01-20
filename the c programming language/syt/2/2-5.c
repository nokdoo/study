#include <stdio.h>
 
int main(){

	char s1[] = "concatenate";
	char s2[] = "fiend";

	printf("%d\n", any(s1, s2));

	return 0;
}

int any(char s1[], char s2[]){
	int i = 0;
	int j = 0;

	while(s1[i] != '\0'){
		j = 0;
		while(s2[j] != '\0'){
			if(s2[j++] == s1[i]){
				return i;
			}
		}
		i++;
	}

	return -1;
}

