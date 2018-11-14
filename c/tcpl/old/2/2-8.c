/*
	2-8
   	Write a function rightrot(x, n) that returns
	the value of the integer x rotated to the right by n bit positions.
   */

#include <stdio.h>
#include <math.h>

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned rightrot(unsigned x, int n){
	int i = 0;
	while((unsigned)pow((double)2, (double)i) < x){
		i++;
	}
	
	unsigned int tmp = getbits(x, n-1, n);
	return (x >> n) | (tmp << i-n);
		
}

int main(){
	
	unsigned int x = 2859;

	printf("%u\n", rightrot(x, 5));

	return 0;
}
