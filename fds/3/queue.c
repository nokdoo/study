#include <stdio.h>

#define MAXSIZE 100


typedef struct{
	int key;
}element;

element e[MAXSIZE];
int cnt = 0;
int front = -1;
int rear = -1;
int qsize;

int IsFull(){
	return cnt==qsize ? 1 : 0;
}

int IsEmpty(){
	return cnt==0 ? 1 : 0;
}

void Add(element el){
	if(!IsFull()){
		rear==qsize-1 ? rear=0 : rear++;
		e[rear] = el;
		cnt++;
	}else{
		printf("Q is full\n");
	}
		
}

element Pop(){
	if(!IsEmpty()){
		front == qsize-1 ? front = 0 : front++;
		cnt--;
		return e[front];
	}else{
		printf("Q is empty\n");
	}
}

int main(){
	element el;
	qsize = 5;
	el.key = 1;
	Add(el);
	el.key = 2;
	Add(el);
	el.key = 3;
	Add(el);
	el.key = 4;
	Add(el);
	el.key = 5;
	Add(el);
	el.key = 6;
	Add(el);
	printf("%d ", Pop().key);
	printf("%d ", Pop().key);
	printf("%d ", Pop().key);
	printf("%d ", Pop().key);
	printf("%d ", Pop().key);
	Add(el);
	printf("%d ", Pop().key);

}
