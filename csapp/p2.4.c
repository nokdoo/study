#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
	int i ;
	for(i=len-1; i>=0; i--){
		printf("%d - ", start[i]);
		printf("%.2x\n", start[i]);
	}
	printf("\n");
}

void show_int(int x){
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
	show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void *x){
	show_bytes((byte_pointer) &x, sizeof(void *));
}


int main(){
	int i = 2607352;
	show_int(i);
	int f = 3510593.0;
	show_float(f);
}
