#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int n; 
	int k; 
	scanf("%d", &n);
	scanf("%d", &k);
	int count[k];
	for (int i = 0; i < k; i++) {
		count[i] = 0;
	}
	int a;
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		count[a%k]++;
	}

	int cnt = 0;
	for (int i = 0; i <= k/2; i++) {
		if (i == 0 || i == k - i) {
			if (count[i] > 0) {
				cnt++;
			}
		} else {
			cnt += count[i] > count[k-i] ? count[i] : count[k-i];
		}
	}
	printf("%d\n", cnt);

	return 0;
}
