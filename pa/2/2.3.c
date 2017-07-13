#include <stdio.h>

#define ROW 5
#define COL 5

int map[ROW][COL] = {
	1,2,2,1,5,
	1,4,4,3,1,
	2,1,1,1,2,
	1,3,5,1,1,
	1,5,1,2,2
};

enum {LEFT, UP};

int map2[ROW][COL] = {0};

int path[ROW][COL] = {0};

int max(int a, int b){
	return a>b ? a : b;
}

void setPath(){
	int i, j;
	map2[0][0] = map[0][0];
	for(i = 1; i<ROW; i++){
		map2[i][0] = map2[i-1][0] + map[i][0];
		path[i][0] = LEFT;
	}
	for(j = 0; j<COL; j++){
		map2[0][j] = map2[0][j-1] + map[j][0];
		path[0][j] = UP;
	}
	for(i=1; i<ROW; i++){
		for(j = 1; j<COL; j++){
			path[i][j] = map2[i-1][j] > map2[i][j-1] ? UP : LEFT;
			map2[i][j] = max(map2[i-1][j], map2[i][j-1]) + map[i][j];
		}
	}
}

void print(){
	int r = ROW-1;
	int c = COL-1;
	while(r != 0 && c != 0){
		printf("%d, %d\n", r, c);
		if(path[r][c] == LEFT){
			c--;
		}else if(path[r][c] == UP){
			r--;
		}
	}
		printf("%d, %d\n", r, c);
}

int main(){
	setPath();
	print();	
}
