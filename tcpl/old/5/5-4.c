#include <stdio.h>

int strend(char *s, char *t){
	
	int sn = 0;;
	int tn = 0;
	char c;
	
	while(*s != '\0'){
		*s++;
		sn++;		
	}

	while(*t != '\0'){
		*t++;
		tn++;
	}

	if(tn > sn){
		return 0;
	}

	while(tn-- > 0){
		if(*s-- != *t--){
			return 0;
		}
	}

	return 1;
}

int main(){
	char *s = "firstsecond";

	printf("%d\n%d\n%d\n", strend(s, "second"), strend(s, "seccond"), strend("first", "st"));
}
