#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void printatob(int a, int b){
	for(;a<=b; a++){
		printf("%d ", a);
	}
}

int main(){
	int t; 
	scanf("%d",&t);
	for(int a0 = 0; a0 < t; a0++){
		int n; 
		int k; 
		scanf("%d %d",&n,&k);
		//printf("n:%d k:%d\n", n, k);
		if(k == 0){
			printatob(1, n);
			printf("\n");
			continue;
		}
		int mod = n%k;
		int div;
		if(mod == 0){
			div = n/k;
			if((div%2)){
				printf("-1\n");
				continue;
			}
			for(int i = 2; i<=div; i=i+2){
				if(i <= div){
					printatob(k*i-(k-1), k*i);
				}
				printatob(k*(i-1)-(k-1), k*(i-1));
			}
			printf("\n");
		}else{
			printf("-1\n");
		}
	}
	return 0;
}

