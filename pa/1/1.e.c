#include <stdio.h>

int circle[20];
int n=0;
int m=0;
int killed=0;

void findM(){
	int cnt = 0;
	while(cnt < 2 && killed < n){
		m = (m+1) % (n);
		if(circle[m] == 1){
			cnt++;
		}
	}
}


void kill(){
	findM();
	circle[m] = 0;
	killed++;
}

int main(){
	scanf("%d", &n);

	int i;
	for(i = 0; i<n; i++){
		circle[i] = 1;
	}

	scanf("%d", &m);
	m -= 1;

	while(killed < n)
		kill();
	printf("%d\n", m+1);
}
