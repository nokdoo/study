#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "getword.c"

#define MAXWORD 100

struct wnode{
	int linenum;
	struct wnode *next;
};

struct tnode{
	char *word;
	struct wnode *line;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
struct wnode *addnode(struct wnode *);
void treeprint(struct tnode *);
int getword(char *, int);
int linenum = 1;

int main(){
	struct tnode *root;
	char word[MAXWORD];
	root = NULL;

	while(getword(word, MAXWORD) != EOF)
		if(isalpha(word[0]))
			root = addtree(root, word);
	treeprint(root);
	return 0;
}

struct tnode *talloc(void);
struct wnode *walloc(void);
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
		p->line = addnode(p->line);
		p->left = p->right = NULL;

	}else if((cond = strcmp(w, p->word)) == 0)
		p->line = addnode(p->line);
	else if(cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);
	return p;
}

struct wnode *addnode(struct wnode *p){
	extern int linenum;
	if(p == NULL){
		p = walloc();
		p->linenum = linenum;
	}else if(p->linenum < linenum){
		p->next = addnode(p->next);
	}
	return p;
}

void lineprint(struct wnode *p){
	if(p != NULL){
		printf("%d ", p->linenum);
		lineprint(p->next);
	}
}

void treeprint(struct tnode *p){
	if(p != NULL){
		lineprint(p->line);
		treeprint(p->left);
		lineprint(p->line);
		printf("%s\n", p->word);
		treeprint(p->right);
	}
}

struct tnode *talloc(void){
	return (struct tnode *) malloc(sizeof(struct tnode));
}

struct wnode *walloc(void){
	return (struct wnode *) malloc(sizeof(struct wnode));
}

