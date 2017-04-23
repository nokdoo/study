#include <stdio.h>

main(){
	int comment_flag = 0;
	char stack = 0;
	char c;
	char pre = 0;
	

	while((c = getchar()) != EOF){
		if(pre == '/' && c == '*' && comment_flag != -1){
			comment_flag = 2;
		}else if(pre == '/' && c == '/' && comment_flag != -1){
			comment_flag = 1;
		}


		if(comment_flag == 0){
			if(c == '/'){
				
				
			}else{
				if(pre == '/' && c == '*'){
				}else if(pre == '/' && c != '*'){
					putchar(pre);
					putchar(c);
				}else{
					putchar(c);
				}
			}
		}

		if(pre == '*' && c == '/' && comment_flag == 2){
			comment_flag = 0;
			c = 0;
		}else if(comment_flag == 1 && c == '\n'){
			comment_flag = 0;
			putchar(c);
		}       
		
		pre = c;
	}

}
