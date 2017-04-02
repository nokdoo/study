#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int k;
	int a;
	scanf("%d", &n);
	scanf("%d", &k);
	int *cnt = (int *) malloc(sizeof(int)*k);
	for(int i = 0; i<n; i++){
		scanf("%d", &a);
		cnt[a%k]++;
	}

	printf("%d", cnt[0]);
	return 0;
}
