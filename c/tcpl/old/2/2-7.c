/*
    2-7
	Write a function invert(x, p, n) that returns x with the n bits
	that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
	leaving the others unchanged.
   */
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n){
	return (x >> (p+1-n)) & ~(~0 << n);
}

unsigned invert(unsigned x, int p, int n){
	unsigned int tmp;
	tmp = getbits(x, p, n);
	x = x ^ (tmp << p+1-n);
	tmp = getbits(~tmp, n-1, n);
	x = x | (tmp << p+1-n);
	return x;
}

int main(){
	unsigned int a = 2859;
	printf("%u\n", invert(a, 7, 5));
	return 0;
}
