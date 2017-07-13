#include <stdio.h>
#define ROW 5
#define COL 5
int map1[5][5] = {
	1,1,1,1,0,
	1,1,1,1,1,
	1,1,1,1,1,
	1,0,1,1,1,
	1,1,1,1,1
};

int map2[5][5] = {
	1,1,1,1,1,
	1,1,0,0,1,
	1,1,1,1,1,
	1,1,1,0,1,
	0,0,1,1,1
};

int map3[5][5] = {0};

void set(int row, int col){

	int i, j;
	map3[0][0] = 1;
	for(i=1; i<row; i++){
		if(map2[i][0] == 0){
			map3[i][0] = 0;
		}else{
			map3[i][0] = map3[i-1][0];
		}
	}

	for(j=1; j<col; j++){
		if(map2[0][j] == 0){
			map3[0][j] = 0;
		}else{
			map3[0][j] = map3[0][j-1];
		}
	}

	for(i=1; i<row; i++){
		for(j=1; j<col; j++){
			if(map2[i][j] == 0){
				map3[i][j] = 0;
			}else{
				map3[i][j] = map3[i-1][j] + map3[i][j-1];
			}
		}
	}
}

int main(){
	int i=0, j=0;
	set(ROW, COL);
	printf("%d\n", map3[ROW-1][COL-1]);
}
