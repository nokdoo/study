/*
   	Write the function itob(n, s, b) that converts the integer n 
	into a base b character representation in the string s.
	In particular, itob(n ,s, 16) formats n as a hexadecimal integer in s.

	*/

#include <stdio.h>
#include "reverse.h"

void itob(int n, char s[], int b){
	int i = 0;
	char num[16] = {
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
		'A', 'B', 'C', 'D', 'E', 'F'
	};

	do{
		s[i++] = num[n%b];
	}while(n /= b);
	s[i] = '\0';
	reverse(s);



}

int main(){

	int a = 23123;	
	char s[50];

	itob(a, s, 8);

	printf("%s\n", s);

	return 0;
}
