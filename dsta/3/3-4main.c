#include "3-4.h"

int main(){
	list *L = MakeEmptyQueue();
	Enqueue(1, L);
	Enqueue(2, L);
	Enqueue(3, L);
	Enqueue(4, L);
	Enqueue(5, L);
	print34(L);
	printf("%d\n", Front(L));
	printf("%d\n", Dequeue(L));
	print34(L);
}
