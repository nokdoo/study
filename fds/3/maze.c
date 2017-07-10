#include <stdio.h>
#include "stack_maze.c"

typedef struct{
	short int vert;
	short int horiz;
}offsets;
offsets move[8];

int maze[14][17]={
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
		1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1,
		1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1,
		1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,
		1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1,
		1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1,
		1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
		1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1,
		1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1,
		1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1,
		1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1,
		1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1,
		1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1,
		1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
	};

	location start = {.vert = 12, .horiz = 15};
	location end = {.vert = 1, .horiz = 1};


void test(){
	while(!IsEmpty()){
		location current = Pop();
		Push(current);
		if(current.vert == end.vert && current.horiz == end.horiz){
			printf("도착\n");
			int i;
			for(i=0; i<top; i++){
				printf("%d, %d\n", e[i].vert, e[i].horiz);
			}
			break;
		}
			
		int i;
		for(i=0; i<8; i++){
			int nextVert = current.vert + move[i].vert;
			int nextHoriz = current.horiz + move[i].horiz;
			if(maze[nextVert][nextHoriz] == 0){
				location p;
				p.vert = nextVert;
				p.horiz = nextHoriz;
				Push(p);
				test();
			}
		}
	}
}

int main(){
	

move[0].vert = -1;
move[0].horiz = 0;
move[1].vert = -1;
move[1].horiz = 1;
move[2].vert = 0;
move[2].horiz = 1;
move[3].vert = 1;
move[3].horiz = 1;
move[4].vert = 1;
move[4].horiz = 0;
move[5].vert = 1;
move[5].horiz = -1;
move[6].vert = 0;
move[6].horiz = -1;
move[7].vert = -1;
move[7].horiz = -1;

	CreateS(14*17);
	Push(start);
	test();
	
	
}
