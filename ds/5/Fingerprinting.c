#include <stdio.h>
#include <string.h>

int X(char *txt, int start, int len){
	int sum = 0;
	int i=0;
	while(i<len){
		sum += (int) txt[start++];
		i++;
	}
	return sum;
}

int fi(char *target, int i, int target_sum, int p_len){
	if(i == 0){
	}else{
		target_sum = target_sum + (int)target[i+p_len-1] - (int)target[i-1];
	}
	return target_sum;
}

int Fingerprinting(char *target, char *pattern){
	int p_len = strlen(pattern);
	int t_len = strlen(target);
	int pattern_sum = X(pattern, 0, p_len);
	int target_sum = X(target, 0, p_len);

	int i=0;
	int cnt = t_len-p_len;
	while(i <= cnt){
		target_sum = fi(target, i, target_sum, p_len);
		if(pattern_sum == target_sum){
			if(strncmp(target+i, pattern, p_len) == 0){
				return i;
			}
		}
		i++;
	}
	return -1;
}

int main(){
	char *target = "ababdabacdababcabab";
	char *pattern = "ababcabab";
	printf("%d\n", Fingerprinting(target, pattern));
}
