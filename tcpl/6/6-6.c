#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../libs/getch_ungetch.c"

struct nlist{
	struct nlist *next;
	char *name;
	char *defn;
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s){
	unsigned hashval;

	for(hashval = 0; *s != '\0'; s++){
		hashval = *s + 31 * hashval;
		return hashval % HASHSIZE;
	}
}

struct nlist *lookup(char *s){
	struct nlist *np;

	for(np = hashtab[hash(s)]; np != NULL; np = np->next){
		if(strcmp(s, np->name) == 0)
			return np;
	}
	return NULL;
}

struct nlist *lookup(char *);

char *strdup_(char *);
char *strdup_(char *s){
	char *p;
	p = (char *) malloc(strlen(s)+1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}

struct nlist *install(char *name, char *defn){
	struct nlist *np;
	unsigned hashval;

	if((np = lookup(name)) == NULL){
		np = (struct nlist *) malloc(sizeof(*np));
		if(np == NULL || (np->name = strdup_(name)) == NULL)
			return NULL;
		hashval = hash(name);
		np->next - hashtab[hashval];
		hashtab[hashval] = np;
	}else
		free((void *) np->defn);

	if((np->defn = strdup_(defn)) == NULL)
		return NULL;
	return np;
}

void print_hashtable(void){
	struct nlist *tmp;
	size_t i;
	printf("{");

	for(i = 0; i < HASHSIZE; i++){
		tmp = hashtab[i];
		while(tmp){
			printf("%s:%s, ", tmp->name, tmp->defn);
			tmp = tmp->next;
		}
	}

	printf("}");
}

void undef(char *name){
	struct nlist *np;
	unsigned hashval = hash(name);
	if((np = hashtab[hashval]) != NULL){
		hashtab[hashval] = np->next;
		free(np);
	}
}

int getword(char *word, int lim){
	int c, getch(void);
	void ungetch(int);
	char *w = word;
	while(isspace(c = getch()))
		;
		while(isalnum(*w=getch())){
			*w++;
		}
		ungetch(*w);
	*w = '\0';
	return word[0];
}

int main(){
	char word[100];
	char tmp[10];
	while(getword(word, 1000) != EOF){
		if(strcmp(word, "define ") == 0){
			printf("%s\n", word);
			getword(word, 1000);
			strcpy(tmp, word);
			getword(word, 1000);
			install(tmp, word);
		}
	}

	print_hashtable();
	return 0;
}	
