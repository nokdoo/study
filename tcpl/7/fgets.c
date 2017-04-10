char *fgets_(char *s, int n, FILE *iop){
	register int c;
	register char *cs = s;
	while(--n>0 && (c = getc(iop)) != EOF)
		if((*cs++ = c) == '\n')
			break;
	*cs = '\0';
	return (c == EOF && cs == s) ? NULL : s;
}

int fputs_(char *s, FILE *iop){
	int c;
	while(c = *s++)
		putc(c, iop);
	return ferror(iop) ? EOF : 0;
}
