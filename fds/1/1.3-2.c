#include <stdio.h>

int horner(int *arr, int len, int x){
	int i, j = 0, tmp, result = 0;
	while(--len >= 0){
		tmp = 1;
		for(i = 0; i<len; i++){
			tmp *= x;
		}
		result += (arr[j++]*tmp);
		printf("%d %d\n", j, arr[j-1]*tmp);
	}
	return result;
}

int main(){
	int arr[] = {-2, 1, 5, 3, 0, 4};
	int x = 3;
	int len = (sizeof(arr) / sizeof(int));
	printf("%d", horner(arr, len, x));

	return 0;
}
