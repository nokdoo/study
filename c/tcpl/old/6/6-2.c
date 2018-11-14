#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "gettoken.c"

#define MAXWORD 100
struct tnode{
	char *word;
	int count;
	struct tnode *left;
	struct tnode *right;
};

char *type[] = {
	"int",
	"char"
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int gettoken(char *, int);

int main(){
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;
	int typesize = (sizeof(type) / sizeof(char*));
	int i;

	while(gettoken(word, MAXWORD) != EOF){
		for(i = 0; i < typesize; i++){
			if(strcmp(type[i], word) == 0){	
				if(gettoken(word, MAXWORD)==EOF)
					break;
				printf("%s\n", word);
				root = addtree(root, word);
			}
		}
	}
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
char *strdup_(char *s){
	char *p;
	p = (char *) malloc(strlen(s)+1);
	if(p != NULL)
		strcpy(p, s);
	return p;
}

struct tnode *addtree(struct tnode *p, char *w){
	int cond;

	if(p == NULL){
		p = talloc();
		p->word = strdup_(w);
		p->count = 1;
		p->left = p->right = NULL;

	}else if((cond = strcmp(w, p->word)) == 0)
		p-> count++;
	else if(cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

void treeprint(struct tnode *p){
	if(p != NULL){
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

