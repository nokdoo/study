#include <stdio.h>
#define MAXLEN 100
#define MAXWID 10
#define NEWLINE \n
#define BLANK ' '
#define TAB '\t'

main (){
	int i = 0;
	char c;
	int newline_flag = 0;
	
	while((c = getchar()) != EOF){
		if(i >= MAXWID){
			if((c == BLANK || c == TAB)){
				printf("\n");
				while(1){
					c = getchar();
					if(c == TAB || c == BLANK){
						
					}else{
						putchar(c);
						break;
					}
				}
				i = 0;
			}else{
				putchar(c);
			}
		}else{
			putchar(c);
		}
		if(c == '\n'){
			i = 0;
		}
		i++;
	}

	return 0;

}
