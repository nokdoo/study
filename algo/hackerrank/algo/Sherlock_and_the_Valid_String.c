#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void sort(int *al){
	int i, j, max = 0;
	int tmp;
	for(i = 0; i<25; i++){
		max = i;
		for(j = i; j<26; j++){
			if(al[j] > max){
				max = j;                
			}
		}
		tmp = al[i];
		al[i] = al[max];
		al[max] = tmp;
	}
	for(i =0; i<26; i++){
		//printf("%d ", al[i]);
	}
	//printf("\n");
}

int findlast(int *al){
	int i=0;
	while(*al++ != 0){
		i++;
	}
	return i-1;
}

void isValid(char *s){
	long long i;
	int al[26] = {0};
	int lastidx;
	i = 0;
	while(s[i] != '\0'){
		al[s[i]-'a']++;
		i++;
	}

	sort(al);
	lastidx = findlast(al);

	if(lastidx >= 2){
		if(al[lastidx] == al[0]){
			printf("YES\n");
		}else if(al[lastidx] == 1){
			if(al[0] == al[lastidx-1]){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else if(al[0]-1 == al[lastidx] && al[1] == al[lastidx]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}else{
		if(abs(al[0] - al[1]) == 1){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}

int main() {
	char* s = (char *)malloc(512000 * sizeof(char));
	scanf("%s", s);
	int result_size;
	isValid(s);
	return 0;
}

