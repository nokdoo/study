/*
	Write a function setbits(x, p, n, y) that returns x with the n bits
	that begin at position p set to the rightmost n bits of y,
	leaving the other bits unchanged.
   */
#include <stdio.h>
unsigned getbits(unsigned, int, int);

unsigned setbits(unsigned x, int p, int n, unsigned y){
	return x ^ (getbits(x, p, n) << p+1-n) | (getbits(y, n-1, n) << p+1-n);
}

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}

int main(){
	int x  = 2859;

	printf("%u\n", setbits(x, 7, 5, 2511));

	return 0;
}


