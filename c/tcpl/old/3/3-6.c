#include <stdio.h>
#include "reverse.h"

void itoa(int n, char s[], int w){
	int i, sign;

	if((sign = n) < 0 )
			n = -n;
	i = 0;
	do{
		s[i++] = n % 10 + '0';
	}while((n/=10) > 0);

	if(sign <0)
		s[i++] = '-';
	w -= i;
	while(w--){
		s[i++] = '@';
	}

	s[i] = '\0';
	reverse(s);
}

int main(){
	int a = 21324;
	char s[50];
	itoa(a, s, 20);
	printf("%s", s);
}
