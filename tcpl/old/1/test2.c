#include <stdio.h>

main(){
	unsigned char c;
	while((c = getchar()) != EOF){
		putchar(c);
	}
	printf("\nended");
}
