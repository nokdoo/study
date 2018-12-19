#include "./3-2.h"

int main(){
	queue *L = MakeEmptyQueue();
	Enqueue(3, L);
	printf("%d", Dequeue(L));
}
