#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int r, c, n;
int time = 0;

struct cell{
	char bomb;
	int count;
};

void plantbomb(struct cell grid[r][c]){
	for(int r_i=0; r_i<r; r_i++){
		for(int c_i=0; c_i<c; c_i++){
			if(grid[r_i][c_i].bomb == '.'){
				grid[r_i][c_i].bomb = 'O';
				grid[r_i][c_i].count = n;
			}
		}
	}
}

void detonate(struct cell grid[r][c], int r_i, int c_i){
	grid[r_i][c_i].bomb = '.';
	grid[r_i][c_i].count = 0;
	if(r_i < r-1){
		if(grid[r_i+1][c_i].bomb == 'O' && grid[r_i+1][c_i].count-n >= 3){
			detonate(grid, r_i+1, c_i);
		}else{
			grid[r_i+1][c_i].bomb = '.';
			grid[r_i+1][c_i].count = 0;
		}
	}
	if(0 < r_i){
		if(grid[r_i-1][c_i].bomb == 'O' && grid[r_i-1][c_i].count-n >= 3){
			detonate(grid, r_i-1, c_i);
		}else{
			grid[r_i-1][c_i].bomb = '.';
			grid[r_i-1][c_i].count = 0;
		}
	}
	if(c_i < c-1){
		if(grid[r_i][c_i+1].bomb == 'O' && grid[r_i][c_i+1].count-n >= 3){
			detonate(grid, r_i, c_i+1);
		}else{
			grid[r_i][c_i+1].bomb = '.';
			grid[r_i][c_i+1].count = 0;
		}
	}
	if(0 < c_i){
		if(grid[r_i][c_i-1].bomb == 'O' && grid[r_i][c_i-1].count-n >= 3){
			detonate(grid, r_i, c_i-1);
		}else{
			grid[r_i][c_i-1].bomb = '.';
			grid[r_i][c_i-1].count = 0;
		}
	}
}

void printgrid(struct cell grid[r][c]){
	for(int r_i=0; r_i<r; r_i++){
		for(int c_i=0; c_i<c; c_i++){
			printf("%c", grid[r_i][c_i].bomb);
		}
		printf("\n");
	}
}

void bomb(struct cell grid[r][c]){
	for(int r_i=0; r_i<r; r_i++){
		for(int c_i=0; c_i<c; c_i++){
			if(grid[r_i][c_i].bomb == 'O' && grid[r_i][c_i].count-n >= 3){
				detonate(grid, r_i, c_i);
			}
		}
	}

}

int main() {
	extern int r, c, n;
	scanf("%d %d %d", &r, &c, &n);
	struct cell grid[r][c];
	char ch;
	scanf("%c", &ch);
	for(int r_i=0; r_i<r; r_i++){
		for(int c_i=0; c_i<=c; c_i++){
			scanf("%c", &ch);
			if(ch == '\n'){
				break;
			}
			if(ch == 'O'){
				grid[r_i][c_i].bomb = ch;
				grid[r_i][c_i].count = n;
			}else if(ch == '.'){
				grid[r_i][c_i].bomb = '.';
				grid[r_i][c_i].count = 0;
			}
		}
	}

	//printgrid(grid);
	if(n == 1){
		n=0;
	}else if(n == 2){
		n = 2;
	}else if(n == 3){
		n = 2;   
	}else if(n%2 == 0){
		n = 2;
	}else if(n%4 == 2){
		n = 1;
	}else if(n%4 == 0){
		n = 4;
	}else if(n%4 == 1){
		n = 4;
	}else if(n%4 == 3){
		n = 1;
	}else{
		printf("default\n");
	}
	//n--;
	while(n>0){
		//printf("\n\n%d\n", ++time);printgrid(grid);
		n--;
		plantbomb(grid);
		bomb(grid);
	}

	printgrid(grid);



	/* Enter your code here. Read input from STDIN. Print output to STDOUT */    
	return 0;
}

