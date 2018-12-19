#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int cmp(const char *g, const char *p, int c){
	int i;
	for(i=0; i<c; i++){
		//printf("%c === %c\n", g[i], p[i]);
		//if(*(g+i) != *(p+i))
		if(g[i] != p[i]){
			//printf("return 0\n");
			return 0;
		}
	}
	//printf("return 1\n");
	return 1;
}

int main(){
	int t; 
	scanf("%d",&t);
	for(int a0 = 0; a0 < t; a0++){
		int R; 
		int C; 
		scanf("%d %d",&R,&C);
		char* *G = malloc(sizeof(char*) * R);
		for(int G_i = 0; G_i < R; G_i++){
			G[G_i] = (char *)malloc(10240 * sizeof(char));
			scanf("%s",G[G_i]);
		}
		int r; 
		int c; 
		scanf("%d %d",&r,&c);
		char* *P = malloc(sizeof(char*) * r);
		for(int P_i = 0; P_i < r; P_i++){
			P[P_i] = (char *)malloc(10240 * sizeof(char));
			scanf("%s",P[P_i]);
		}
		int R_i;
		int r_i;
		for(R_i = 0, r_i = 0; R_i<R-r+1; R_i++){
			char *addr = NULL;
			int idx;
			int tmp_R_i = R_i;
			int j = 0;
			while(addr = strstr(G[R_i]+j++, P[r_i])){
				idx = addr - G[R_i];
				while(r_i<r-1){
					R_i++;
					r_i++;
					if(cmp(G[R_i]+idx, P[r_i], c)){
						if(r_i == r-1){
							printf("YES\n");
							break;
						}
					}else{
						r_i = 0;
						R_i = tmp_R_i;
						break;
					}
				}
			}
		}
		if(R_i == R-r+1 && r_i != r-1){
			printf("NO\n");
		}

	}
	return 0;
}

