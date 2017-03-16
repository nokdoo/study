#include "../libs/getch_ungetch.c"
extern int linenum;
int getword(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	
	while(isspace(c = getch()))
		;
	if(c == '.'){
		linenum++;
		printf("linenum : %d\n", linenum); 
	}
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)){
		if(c == '.'){
			linenum++;
			printf("\nlinenum : %d\n", linenum); 
		}
		*w = '\0';
		return c;
	}
	for(; --lim >0; w++)
		if(!isalnum(*w = getch())){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
