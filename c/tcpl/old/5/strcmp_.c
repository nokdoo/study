#include <stdio.h>
#include <ctype.h>

int strcmp_(char const *s, char const *t){
	
	extern int fold;
	for(; (fold) ? (tolower(*s) == tolower(*t)) : (*s == *t); *s++, *t++){
		if(*s == '\0')
			return 0;
	}

	return (fold) ? (tolower(*s) - tolower(*t)) : (*s - *t);
}	
