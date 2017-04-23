#include <stdio.h>
 
void squeeze(char s1[], char s2[]);

int main(){

	char s1[] = "ABCDEFG";
	char s2[] = "BEG";

	squeeze(s1, s2);



	return 0;
}

void squeeze(char s1[], char s2[]){
	int i, j = 0;
	int b = 0;

	while(s1[i] != '\0'){
		b = 0;
		while(s1[i] != s2[b++]){
			if(s2[b] == '\0'){
				s1[j++] = s1[i];
				break;
			}
		}
		i++;
	}
	s1[j] = '\0';
	printf("%s", s1);
}
