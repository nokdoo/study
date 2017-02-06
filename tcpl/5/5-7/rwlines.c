#define MAXLEN 1000
int getline_(char *, int);
char *alloc(int n, char *allocbuf_, char *allocp_){
	if(allocbuf_ + ALLOCSIZE_ - allocp_ >= n){
		allocp_ += n;
		return allocp_ - n;
	}else
		return 0;
}
int readlines(char *allocbuf_, char *allocp_, char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	while((len = getline_(line, MAXLEN)) > 0){
		if(nlines >= maxlines || (p = alloc(len, allocbuf_, allocp_)) == NULL)
			return -1;
		else{
			line[len-1] = '\0';
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
