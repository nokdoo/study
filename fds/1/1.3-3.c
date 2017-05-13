#include <stdio.h>

void cases(int n, int boolean);
void cases2(int n, int boo);

int main(){
	int n;
	scanf("%d", &n);
	cases(n, 0);
	return 0;
}

void cases(int n, int boolean){
	if(n == 0){
		if(boolean == 1){
			printf("\n");
		}else{
			printf("\v\b\b");
		}
		return;
	}else{
		n--;
		printf("0 ");
		cases(n, 0);
		printf("1 ");
		cases(n, 1);
	}
}

