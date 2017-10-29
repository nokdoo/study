#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() {
	int T = 0, N = 0;
	scanf("%d", &T);
	for(int t = 0; t<T; t++){
		scanf("%d", &N);
		int A[N];
		for(int i=0;i<N;i++){
			scanf("%d", &A[i]);
		}
		int count = 0;
		for(int i=0;i<N-1;i++){
			for(int j=i+1;j<N;j++){
				if(A[i]>A[j])
					count++;
			}
		}
		if(count&1)
			printf("NO\n");
		else
			printf("YES\n");
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	return 0;
}

