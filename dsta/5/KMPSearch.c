#include <stdio.h>
#include <string.h>

void setPSub(char *p, int *p_sub, int p_len){
	p_sub[0] = 0;
	int i = 1;
	while(i<p_len){
		if(p[i] == p[p_sub[i-1]]){
			p_sub[i] = p_sub[i-1]+1;
		}else{
			p_sub[i] = 0;
		}
		i++;
	}
	i = 0;
	for(i = 0; i<p_len; i++){
		printf("%d ", p_sub[i]);
	}
	printf("\n");
}

int KMPSearch(char *s, char *p){
	int i = 0;
	int j = 0;
	int p_len = strlen(p);
	int s_len = strlen(s);
	int p_sub[p_len];
	setPSub(p, p_sub, p_len);
	
	while(i<s_len){
		if(s[i] == p[j]){
			i++;
			j++;
		}else{
			i++;
			j = p[j];
		}
		if(j == p_len){
			return i-j;
		}
	}
	return -1;
}

int main(){
	char *s = "ababdabacdababcabab";
	char *p = "ababcabab";
	//char *p = "aabaabac";
	printf("%d\n", KMPSearch(s, p));
}
