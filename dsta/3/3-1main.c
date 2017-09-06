#include "./3-1.h"

int main(){
	stack *L = MakeEmptyStack();
	Push(1, L);
	Push(2, L);
	Push(3, L);
	Push(4, L);
	Push(5, L);
	print31(L);
	Pop(L);
	print31(L);

}
