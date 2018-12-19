#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <time.h>

int MAXLEVEL=0;

struct Node{
	int key;
	struct Node* bottom;
	struct Node* forward;
};

int MaxLevel(double a){
	return (int)( log(a)/log(2.0) );
};

struct Node* mkList(){
	struct Node* head = (struct Node*) malloc(sizeof(struct Node)*(MAXLEVEL+1));
	struct Node* tail = (struct Node*) malloc(sizeof(struct Node));
	tail->key = INT_MAX;
	tail->bottom = NULL;
	tail->forward = NULL;
	struct Node* tmp = NULL;
	for(int i=0; i<=MAXLEVEL; i++){
		head[i].key = INT_MIN;
		head[i].forward = tail;
		if(tmp != NULL) tmp->bottom = &head[i];
		tmp = &head[i];
	}
	return head;
}

struct Node* SkipListLookUp(int K, struct Node* L){
	int i = MAXLEVEL;
	
	struct Node* P = &L[i];
	while(i>=0){
		if(P == NULL) return NULL;
		while(P->forward->key < K){
			P = P->forward;
		}
		if(i==0) break;
		P = P->bottom;
		i--;
	}
	if(K == P->key) return P;
	else NULL;
}

int RandomLevel(){
	srand(clock());
	int v = 0;
	int i = random()%2;
	while(rand()%2 == 0 && v < MAXLEVEL) v++;
	return v;
}

void SkipListInsert(int K, struct Node* L){
	if(SkipListLookUp(K, L) != NULL) return;

	int i, NewLevel;
	i = NewLevel = RandomLevel();
	struct Node* tmp;
	struct Node* P;

	while(i>=0){
		P = &L[i];
		while(K > P->forward->key){
			P = P->forward;
		}
		struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
		newNode->key = K;
		newNode->forward = P->forward;
		newNode->bottom = NULL;

		if(tmp != NULL) tmp->bottom = newNode;

		P->forward = newNode;
		i--;
	}
}

int main(){

	MAXLEVEL = MaxLevel(18);
	
	struct Node* SkipList = mkList();
	SkipListInsert(3, SkipList);
	SkipListInsert(7, SkipList);
	SkipListInsert(19, SkipList);
	SkipListInsert(22, SkipList);
	SkipListInsert(43, SkipList);
	SkipListInsert(48, SkipList);
	SkipListInsert(55, SkipList);
	SkipListInsert(70, SkipList);
	SkipListInsert(-120, SkipList);
	SkipListInsert(-32, SkipList);
	SkipListInsert(-56, SkipList);
	SkipListInsert(-5, SkipList);
	SkipListInsert(234, SkipList);
	SkipListInsert(100, SkipList);
	SkipListInsert(-345, SkipList);
	SkipListInsert(434, SkipList);
	SkipListInsert(99, SkipList);
	SkipListInsert(-99, SkipList);
	struct Node* P = NULL;
	for(int i=MAXLEVEL; i>=0; i--){
		P = &SkipList[i];
		while(P->forward != NULL){
			P = P->forward;
			printf("%d -> ", P->key);
		}
		printf("\n\n");
	}
}
