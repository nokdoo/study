#include <stdio.h>
#include <time.h>

#define ROW 8
#define COL 7

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
	printf("\n\n\n");
}

void convert(struct term *a, struct term *b){
	int acolnum = a[0].col;
	int avalue = a[0].value;
	int rowterm[acolnum];
	int startingpos[acolnum];
	startingpos[0] = 1;
	int i, j;
	for(i = 0; i<acolnum; i++){
		rowterm[i] = 0;
	}	
	
	for(i=1; i<=avalue; i++){
		rowterm[a[i].col]++;
	}
	for(i=1; i<acolnum; i++){
		startingpos[i] = startingpos[i-1] + rowterm[i-1];
	}
	for(i=1; i<=avalue; i++){
		j = startingpos[a[i].col]++;
		b[j].row = a[i].col;
		b[j].col = a[i].row;
		b[j].value = a[i].value;
	}
}

int main(){
	int m[ROW][COL] = {
		{3, 45, -34, 23, 2, 0, 53},
		{0, 6, 4, 0, 0, 0, 3},
		{-23, 123, 55, 0, 4, 33, 0},
		{1, 10, 11, -12, -24, -355, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{99, -99, 43, 43, 34, 34, -43},
		{456, 34,  23, -23, 34, -456, -34},
		{0, 5, 1246, 553, 232, 44, -3}
	};
	
	print(m);	

	struct term a[ROW*COL+1];
	struct term b[ROW*COL+1];
	a[0].row = ROW;
	a[0].col = COL;
	a[0].value = 0;
	b[0].row = COL;
	b[0].col = ROW;
	b[0].value = 0;
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

	b[0].value = a[0].value;

	print2(a);
	
	clock_t start = clock();
	convert(a, b);
	clock_t stop = clock();

	print2(b);

	printf("%10f", ((double)(stop-start))/CLOCKS_PER_SEC);


}
