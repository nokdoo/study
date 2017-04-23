#include <stdio.h>

void strncpy_(char *s, char *t, int n){
	while(n-- > 0 && (*s++ = *t++) != '\0') // n-- > 0  이 앞에 있어야 n개를 체크
		;
}

void strncat_(char *s, char *t, int n){
	while(*s != '\0'){
		*s++;
	}

	while(n-- > 0 && (*s++ = *t++) != '\0')
		;
}

int strncmp_(char *s, char *t, int n){
	while(n-- > 0 && *s==*t){
		if(*t == '\0'){
			return 0;
		}
		*s++;
		*t++;
	}

	return *s - *t;

}


int main(){
	char s[20] = "SeoYounTaek";
	char *t = "nokdoo";
	char a[10] = {0};

	strncpy_(a, t, 4);
	printf("strncpy : %s\n", a);
	strncat_(s, t, 4);
	printf("strncat : %s\n", s);
	printf("strncmp : %d, %d\n\n", strncmp_(a, "nokdoo", 4), strncmp_(a, "Nokdoo", 4));

	printf("%d, %d\n", 'n', 'N');
}
