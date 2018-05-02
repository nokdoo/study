#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void shellsort(char v[], int n){
	int gap, i, j;
	char tmp;
	for(gap = n/2; gap>0; gap/=2)
		for(i = gap; i<n; i++)
			for(j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap){
				tmp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = tmp;
			}

}

int checking(char *a, char *b, int range){
	char c[range+1];
	char d[range+1];
	strncpy(c, a, range);
	c[range] = '\0';
	strncpy(d, b, range);
	d[range] = '\0';
	shellsort(c, range);
	shellsort(d, range);
	//    printf("%s %s %d\n", c, d, strcmp(c, d));

	//    for(int i=0; i<range; i++){
	//        printf("%c", c[i]);
	//    }
	//    printf("\n");
	return (strcmp(c,d)==0) ? 1 : 0;

}

int main() {

	int row;
	scanf("%d", &row);
	int i, j, len;
	int range, k;
	int cnt;

	for(i=0; i<row; i++){
		char s[100];
		scanf("%s", s);
		len = 0;
		while(s[len] != '\0')
			len++;
		cnt = 0;
		for(range = 1; range < len; range++){
			for(j=0; j<len-range; j++){
				for(k=j+1; k<len-range+1; k++){
					cnt += checking(&s[j], &s[k], range);
				}
			}
		}
		printf("%d\n", cnt);

	}
	return 0;
}

