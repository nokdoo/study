#include <stdio.h>

#define ROW 8
#define COL 8

struct term{
	int row;
	int col;
	int value;
};

void print(int m[ROW][COL]){
	int i, j;
	for(i=0; i<ROW; i++){
		for(j=0; j<COL; j++){
			printf("%5d", m[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

void print2(struct term *a){
	int i;
	for(i=0; i<ROW*COL+1; i++){
		printf("%5d%5d%5d\n", a[i].row, a[i].col, a[i].value);
		if(i == a[0].value){
			break;
		}
	}
}

int main(){
	int m[ROW][COL] = {
		{3, 45, -34, 23, 2, 0, 53, 0},
		{0, 6, 4, 0, 0, 0, 3, -3},
		{-23, 123, 55, 0, 4, 33, 0, -23},
		{1, 10, 11, -12, -24, -355, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{99, -99, 43, 43, 34, 34, -43, -34},
		{456, 34,  23, -23, 34, -456, -34, -34},
		{0, 5, 1246, 553, 232, 44, -3, 0}
	};
	
	print(m);	

	struct term a[ROW*COL+1];
	a[0].row = ROW;
	a[0].col = COL;
	a[0].value = 0;
	int i, j, k = 0;
	for(i = 0; i<ROW; i++){
		for(j = 0; j<COL; j++){
			if(m[i][j]){
				a[0].value++;
				k++;
				a[k].row = i;
				a[k].col = j;
				a[k].value = m[i][j];
			}
		}
	}

	print2(a);

}
