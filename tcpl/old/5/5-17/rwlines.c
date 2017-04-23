#include "../../libs/getline_.c"
#include "../alloc.c"

#define MAXLEN 1000
int getline_(char *, int);
char *alloc(int);

int strcmp_(char const *s, char const *t);

int idx = 0;

int getword_(char *word, char *line, int len){
	extern int idx;
	int i = 0;
	char c;
	for(; idx<len-1 && (c = line[idx]) != '\0'; idx++, i++){
		
		word[i] = c;
		if(c == ' '){
			word[i++] = '\0';
			idx++;
			return i;
		}
	}
	return i;
}
void writeword(char *wordptr[], int nlines){
	int i;
	for(i = 0; i<nlines; i++){
		printf("%s ", wordptr[i]);
	}
	printf("\n");
}

int readlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	int len2, nwords;
	char *pw, word[100];
	extern int reverse;
	extern char *wordptr[];

	nlines = 0;
	nwords = 0;
	while((len = getline_(line, MAXLEN)) > 0){
		if(nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len-1] = '\0';

			idx = 0;
			while((len2 = getword_(word, line, len)) > 0){
				if((pw = alloc(len2)) == NULL){
					return -1;
				}else{
					strcpy(pw, word);
					wordptr[nwords++] = pw;
				}
			}

			qsort_((void**)wordptr, 0, nwords-1,
					(int (*)(void *, void *))strcmp_, reverse);

			writeword(wordptr, nwords);


			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}

	return nlines;
}

void writelines(char *lineptr[], int nlines){
	int i;
	for(i = 0; i<nlines; i++){
		printf("%s\n", lineptr[i]);
	}
}
