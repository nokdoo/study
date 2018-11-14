#include <stdio.h>

main(){
	int c, i, nwhite, nother;
	int ndigit[10] = {0};

	int i2;
	int max;
	nwhite = nother = 0;
	for(i = 0; i< 10; ++i){
		ndigit[i] = 0;
	}

	while ((c = getchar()) != EOF)
		if(c>='0' && c <= '9'){
			++ndigit[c-'0'];
		}else if(c == ' '|| c == '\n' || c == '\t'){
			++nwhite;
		}else
			++nother;

	printf("digits =");
	for(i = 0; i<10; ++i){
		printf(" %d", ndigit[i]);
	}
	printf(", white space = %d, other = %d\n", nwhite, nother);

	for(i = 0; i<10; i++){
		for(i2=0; i2<=ndigit[i]; i2++){
			printf("%d", i2);
		}printf("\n");
	}
			
}
