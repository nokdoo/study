//메모리의 부족으로 malloc실패 시

#include <stdlib.h>
#define MALLOC(p, s) \
	if(! ((p) = malloc(s))) {\
		fprintf(stderr, "Insufficiend memory"); \
		exit(EXIT_FAILURE);\
	}
