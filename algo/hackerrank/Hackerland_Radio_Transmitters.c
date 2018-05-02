#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define FRONT 0
#define REAR 1
#define NOTHING -1

void intquick(int *x, int left, int right){
    int tmp;
    if(left < right){
		int p = left, i = left, j = left+1;
		while(j <= right){
			if(x[p] > x[j]){
                tmp = x[++i];
                x[i] = x[j];
                x[j] = tmp;
			}
			j++;
		}
		tmp = x[p];
        x[p] = x[i];
        x[i] = tmp;
		intquick(x, left, i-1);
		intquick(x, i+1, right);
	}
}

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *x = malloc(sizeof(int) * n);
    for(int x_i = 0; x_i < n; x_i++){
       scanf("%d",&x[x_i]);
    }
    int cnt = 0;
    int status = NOTHING;
    int i;
    intquick(x, 0, n-1);
    
    //for(i =0; i<n; i++){
    //    printf("%d ", x[i]);
    //}
    int start = 0;
    int point = 0;
    for(i = 0; i<n;){
        start = x[i];
        point = x[i];
        cnt++;
        if(i==n-1)
            break;
        else{
            i++;
        }
        while(i<n && x[i]-start <= k)
            point = x[i++];
        if(point == start)
            continue;
        start = point;
        while(i<n && x[i]-start <= k)
            point = x[i++];
        start = point;
        
    }
    
    printf("%d", cnt);
    
    
    return 0;
}
