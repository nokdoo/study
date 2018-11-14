/*
   	Our binary search makes two tests inside the loop,
	when one would suffice (at the price of more tests outside).
	Write a version with only one test inside the loop and measure the difference in run-time
	*/

#include <stdio.h>

int binsearch(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n-1;
	while(low < high){
		mid = (low+high) / 2;
		if(x <= v[mid]){
			high = mid;
		}else{
			low = mid+1;
		}
	}

	if(low == high){
		return low;
	}

	return -1;
}

int main(){
	int v[10] = {1,2,3,4,5,6,7,8,9,10};
	printf("%d\n", binsearch(7, v, 10));
}	
