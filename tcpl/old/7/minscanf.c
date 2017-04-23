#include <stdarg.h>

int minscanf(char *fmt, ...){
	va_list ap;
	char *p;
	int *ival;
	double dval;
	int cnt = 0;

	va_start(ap, fmt);
	for(p=fmt; *p; p++){
		if(*p != '%'){
			putchar(*p);
			continue;
		}		
		switch(*++p){
			case 'd':
				ival = va_arg(ap, int *);
				if(scanf("%d", ival) != 1)
					break;
				cnt++;
			default:
				break;
		}
	}


	va_end(ap);

	return cnt;
}
