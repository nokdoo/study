#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define BASE 10 // 10,100,1000,10000

struct big {
	int num[1000];
	int len;
};

void setbig(struct big *rst, int n)
{
	int *num = rst->num;

	rst->len = 0;
	do {
		*num++ = n % BASE;
		rst->len++;
		n /= BASE;
	} while (n != 0);
}

void printbig(struct big *rst)
{
	int i = rst->len;
	int digs = log10(BASE);

	printf("%d", rst->num[--i]);
	while (0 <= --i) {
		printf("%0*d", digs, rst->num[i]);
	}
	printf("\n");
}

void facbig(struct big *rst, int n)
{
	int i;
	int tmp = 0;

	setbig(rst, n);
	while (--n > 1) {
		i = 0;
		printf("%d\n", rst->num[rst->len - 1]);
		while (i < rst->len) {
			rst->num[i] *= n;
			rst->num[i] += tmp;
			tmp = rst->num[i] / BASE;
			rst->num[i] %= BASE;
			i++;
			while (i == rst->len && tmp > 0) {
				rst->num[i] = tmp % BASE;
				tmp /= BASE;
				i++;
				rst->len++;
			}
		}
	}
}

int main()
{
	int n;
	struct big *rst = (struct big *) malloc(sizeof(struct big));
	scanf("%d", &n);
	//    setbig(rst, n);
	facbig(rst, n);
	printbig(rst);
	return 0;
}
