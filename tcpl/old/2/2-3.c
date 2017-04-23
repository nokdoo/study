#include <stdio.h>
#include <math.h>
  
int main(){
	char hex[] = "0xADFFD";

	printf("%d", htoi(hex));

}

int htoi(char hex[]){
	int i = 2;
	int e = 0;
	int ret = 0;
	char c;

	while((c = hex[i]) != '\0'){
		if('0' <= c && c <= '9'){
			hex[i] = c - '0' + 0;
		}else if('a' <= c && c <= 'f'){
			hex[i] = c - 'a' + 10;
		}else if('A' <= c && c <= 'F'){
			hex[i] = c - 'A' + 10;
		}else{
			printf("16진수에 해당되지 않는 숫자가 포함되어 있습니다.\n");
			return;
		}
		i++;
	}

	i--;

	while(i > 1){
		ret += pow((double)16, e) * hex[i];
		printf("%d\n", hex[i]);
		e++;
		i--;
	}

	return ret;

}	
