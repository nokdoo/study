#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int getlength(char *s){
	int i=0;
	while(*s++!='\0')
		i++;
	return i;
}

void swap(char *s, int a, int b){
	char tmp = s[a];
	s[a] = s[b];
	s[b] = tmp;
}

void sort(char *s, int start){
	int last = getlength(s)-1;
	for(int i = 0; i<last-start; i++)
		for(int j = start; j<last; j++){
			if(s[j]>s[j+1]){
				swap(s, j, j+1);
			}
		}
}

int main() {
	int wordcnt;
	scanf("%d", &wordcnt);

	for(int i = 0; i<wordcnt; i++){
		char *word = (char *) malloc(sizeof(char)*1024);
		scanf("%s", word);
		int lastindex = getlength(word)-1;
		int j = lastindex;
		while(j > 0 && word[j-1] >= word[j]){
			j--;
		}
		if(j <= 0){
			printf("no answer\n");
			continue;
		}

		int k = lastindex;
		while(word[j-1] >= word[k]){
			k--;
		}
		//printf("%d, %d, %s   ==== ", k, j-1, word);
		if(k >= j){
			swap(word, k, j-1);
			//printf(" === %s   ", word);
			sort(word, j);
		}
		printf("%s\n", word);
	}

	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	return 0;

}
