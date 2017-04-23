/*
   	In a two's complement number representation, our version of itoa deos not handle 
	the largest negative number, that is, the value of n equal to -2^(wordsize-1).
	Explain why not.
	Modify it to print that value correctly, regardless of the machine on which it runs.
	
 	현재 OS에서 INT_MIN의 값은 -2147483648이며, 이것이 largest negative number이다.
	따라서 int값의 범위는 -2147483648 ~ 2147483647임을 알 수 있다.
	
	3비트의 값을 예로 들면, int값의 범위는 -4 ~ 3이다.
	largest negative number를 양수로 바꿔주게 되면 
		-4 -> 4 
	이 되어야 하는데, 4는 현재 OS에서 표현할 수 없는 범위에 속한다. 
	이를 비트연산으로 확인하면,
		100 ===(부호 변경 : 1의 보수 + 1)===> 100
	임을 알 수 있고 largest negative number의 부호를 바꾸게 되면 
	다시 largest negarive number임을 알 수 있다.
	따라서 itoa함수 내의 n = -n 은 largest negative number가 된다.

	이에, 따라오는 n%10+'0'을 연산하면 -(LNN의 1의 자릿수)이 되고 (현재 OS에서는 -8)
		-8 + '0' = '('
	이므로 -(을 출력한다.

	while문의 expression, n /= 10은 음수의 결과가 나오기 때문에 더 이상 실행되지 않는다.
 */

#include <stdio.h>
#include <limits.h>
#include "reverse.h"
#include <math.h>

int main(){
	
	int n = -2147483648;
	char s[20];

	int i, sign;
	
	if((sign = n) < 0)
		n = -n;
	i = 0;
	do{
		s[i++] = abs(n % 10) + '0';
	}while((n /= 10));
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);

	printf("%s", s);	
	return 0;
}
