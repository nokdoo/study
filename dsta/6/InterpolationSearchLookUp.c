#include <stdio.h>

#define N 26

char table[N] = {
	'a', 'b', 'c', 'd', 'e', 'f', 'g',
	'h', 'i', 'j', 'k', 'l', 'm', 'n',
	'o', 'p', 'q', 'r', 's', 't', 'u',
	'v', 'w', 'x', 'y', 'z'
};

int toInt(char a){
	return (int) a;
}

int InterpolationSearchLookUp(char K, char T[]){
	int n = N;
	int key0 = -1;
	int keyn = 'z'+1;
	int left = 0;
	int right = n-1;

	while(right > left){
		int p = (toInt(K) - ((left == 0) ? key0 : toInt(T[left-1]))) / (((right == n-1) ? keyn : toInt(T[right+1]))  - ((left == 0) ? key0 : toInt(T[left-1])));
		int middle = p * (right-left+1) + left;
		if(toInt(K) == toInt(T[middle])) return middle;
		else if(toInt(K) < toInt(T[middle])) right = middle-1;
		else left = middle+1;
	}
	return -1;
}

int main(){
	printf("%d\n", InterpolationSearchLookUp('r', table));
	printf("%c\n", table[17]);
}
