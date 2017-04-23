#include "../libs/getch_ungetch.c"

int gettoken(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while(isspace(c = getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c) && !isdigit(c)){
		*w = '\0';
		return c;
	}
	for(; --lim >0; w++)
		if(!isalnum(*w = getch()) && !isdigit(*w)){
			ungetch(*w);
			break;
		}
	*w = '\0';
	return word[0];
}
