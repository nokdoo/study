//53페이지 함수...

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


int max(int a, int b);
int *cto_arr_i(char *c, int len);
int *GradeSchoolMult(int *x, int *y, int n);
int *CleverMulti(int *x, int *y, int n);
void SetA(int *x, int *X, int from, int to);
int *Add(int *l, int *r, int lm, int rm);
int GetInt(int *a, int len);
int *itoa(int n, int len);
void printa(int *a, int len);

void printa(int *a, int len){
	int i;
	for(i=0; i<len; i++){
		printf("%d", a[i]);
	}
	printf("\n");
}

int *itoa(int n, int len){
	int *a = (int*)malloc(sizeof(int)*len);
	int i;
	for(i=0; i<len; i++){
		a[len-1-i] = n%2;
		if(a[len-1-i] != 0 && a[len-1-i] != 1){
			printf("here");
		}
		n /= 2;
	}
	return a;
}

int GetInt(int *a, int len){
	int sum = 0;
	int i, j;
	for(i=len-1, j=1; i>=0; i--, j*=2){
		sum += a[i]*j;
	}
	return sum;
}


int *Add(int *l, int *r, int lm, int rm){
	int a = GetInt(l, lm);
	int b = GetInt(r, rm);
	int c = a+b;
	int len = max(lm, rm);
	int *result = NULL;
	result = itoa(c, len);
	return result;

}

void SetA(int *x, int *X, int from, int to){
	int i, j;
	for(i=from, j=0; i<=to; i++,j++){
		x[j] = X[i];
	}
}

int *CleverMulti(int *X, int *Y, int n){
	if(n <= 3){
		return GradeSchoolMult(X, Y, n);
	}
	int m = (int)ceil((double)n/2);

	int Xl[m];
	SetA(Xl, X, 0, m-1);

	int Xr[n-m];
	SetA(Xr, X, m, n-1);

	int Yl[m];
	SetA(Yl, Y, 0, m-1);

	int Yr[n-m];
	SetA(Yr, Y, m, n-1);

	int *AddX;
	AddX = Add(Xl, Xr, m, n-m);

	int *AddY;
	AddY = Add(Yl, Yr, m, n-m);


	int *P1 = NULL;
	int *P2 = NULL;
	int *P3 = NULL;
	
	P1 = CleverMulti(Xl, Yl, 2*m);
	P2 = CleverMulti(Xr, Yr, 2*(n-m));
	P3 = CleverMulti(AddX, AddY, 2*m+2);



	int i1 = GetInt(P1, 2*m);
	int i2 = GetInt(P2, 2*(n-m));
	int i3 = GetInt(P3, 2*m+2);
	int d = i3-i1-i2;

	int *D = NULL;
	D = itoa(d, 2*m+2);

	int *Z = (int*)malloc(sizeof(int)*2*n);
	SetA(Z, P1, 0, 2*m-1);
	SetA(Z, P2, 2*m, 2*n-1);
	return Z;
}
int *GradeSchoolMult(int *X, int *Y, int n){
	int a = GetInt(X, n);
	int b = GetInt(Y, n);
	printf("%d %d\n", a, b);
	
	
	return itoa(a*b, 2*n);
}


int *cto_arr_i(char *c, int len){
	int *X = (int*)malloc(sizeof(int)*len);
	int i;
	for(i=0; i<len; i++){
		if(c[i] == '0'){
			X[i] = 0;
		}else if(c[i] == '1'){
			X[i] = 1;
		}
	}
	return X;
}

int max(int a, int b){
	return (a>b) ? a : b;
}

int main(){

	//char *x = "1101101";
	char *x = "1111";
	//char *x = "101";
	int xlen = strlen(x);
	int *X = NULL;
	X = cto_arr_i(x, xlen);


	//char *y = "1100101";
	char *y = "1111";
	//char *y = "100";
	int ylen = strlen(y);
	int *Y = NULL;
	Y = cto_arr_i(y, ylen);
	
	int n = (xlen > ylen) ? xlen : ylen;
	printf("test\n");
	int *result = CleverMulti(X, Y, n);

	printa(result, 6);



}
