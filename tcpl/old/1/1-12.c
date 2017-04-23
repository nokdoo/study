#include <stdio.h>

#define IN 1
#define OUT 0

main(){
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while((c = getchar()) != EOF){
		++nc;
		if(c == '\n')
			++nl;
		if(c == ' '|| c == '\n' || c == '\t'){
			if(state == IN){
				state = OUT;
				putchar('\n');
			}
		}else if(state == OUT){
			state = IN;
			putchar(c);
			++nw;
		}else{
			putchar(c);
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

