#include <stdio.h>

void print(int *c){
	int i;
	for(i=0; i<2; i++){
		printf("%d", c[i]);	
	}	
	printf("\n");
}

void setg(int *c, int i, int f){
	if(i == 2){
		print(c);
		return;
	}
	f ^= 0;
	c[i] = f;
	setg(c, i+1, f);
	f ^= 1;
	c[i] = f;
	setg(c, i+1, f);

}

int main(){
	int n;
	int c[20];
	scanf("%d", &n);
	
	setg(c, 0, 0);
	
}
