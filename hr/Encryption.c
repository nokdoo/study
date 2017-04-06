#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	char *s = (char *)malloc(10240 * sizeof(char));
	char *t = (char *)malloc(10240 * sizeof(char));
	scanf("%s",s);
	int len = 0;
	char c;

	while((c=*s++) != '\0'){
		if(c == '-'){

		}else{
			*t++ = c;
			len++;
			printf("%c %c\n", c, *t);
		}
	}

	printf("%d\n", len);
	return 0;
}

