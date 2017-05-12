#include <stdio.h>
#include <string.h>
int count = 0;
void perm(char *list, int i, int len);
void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

int main(){
	char list[6] = "abcde";
	int len = strlen(list);

	perm(list, 0, len);
	printf("%d\n", count);
}

void perm(char *list, int i, int len){
	int j;
	if(i == len){
		count++;
		printf("%s ", list);
	}else{
		for(j = i; j<len; j++){
			swap(&list[i], &list[j]);
			perm(list, i+1, len);
			swap(&list[i], &list[j]);
		}
	}
}
