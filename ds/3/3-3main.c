#include "3-3.h"

int main(){
	list *L = MakeEmptyStack();
	Push(5, L);
	Push(2, L);
	Push(3, L);
	print33(L);
	printf("%d %d %d", L->next->info, L->next->next->info, 3);
	L->next = L->next->next;
	printf("%d", L->next->info);
}
