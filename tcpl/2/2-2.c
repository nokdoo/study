#include <stdio.h>
  
int main(){
	char c;
	int lim = 10;
	char s[10];
	int i;

	for(i=0; i<lim-1;){
		if((c = getchar()) != '\n'){
			if(c != EOF){
				s[i] = c;
			printf("%c", c);
				i++;
			}else{
				break;
			}
				}else{
					break;}
	}

	i = 0;
	while(s[i] != '\0'){
		printf("%d\n", s[i]);
			i++;
	}

	return 0;
}
