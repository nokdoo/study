#include <stdio.h>
#include <string.h>

#define char_len 256
#define max(a,b) ((a>=b)?(a):(b))

void SetBMArray(char *pattern, int p_len, int *sub_array){
	int i;
	for(i = 0; i<char_len; i++){
		sub_array[i] = -1;
	}

	for(i = 0; i<p_len; i++){
		sub_array[(int)pattern[i]] = i;
	}
}

int BMSearch(char *target, char *pattern){
	int t_len = strlen(target);
	int p_len = strlen(pattern);

	int sub_array[char_len];
	SetBMArray(pattern, p_len, sub_array);

	int k=0;

	while(k <= (t_len-p_len)){
		int i = p_len - 1;
	
		while(i>= 0 && target[k+i] == pattern[i]) i--;

		if(i<0){
			return k;
		}else{
			k += max(1, i - sub_array[target[k+i]]);
		}
	}
	return -1;
}

int main(){
	char *target = "ABAAABCD";
	char *pattern = "ABC";
	printf("%d\n", BMSearch(target, pattern));
}
