#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

struct key{
	char *word;
	int count;
}keytab[] = {
	"auto", 0,
	"break", 0,
	"char", 0,
	"void", 0,
	"int", 0,
	"while", 0

};

int main(){
	char workd[MAXWORD];
	struct key *p;

	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			if((p=binsearch(word, keytab, NKEYS)) != NULL)
				p->count++;
	for(p = keytab; p < keytab + NKEYS; p++)
		if(p->count > 0)
			printf("%4d %s\n", p->count, p->word);
	return 0;
}
