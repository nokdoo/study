#include <stdio.h>

main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = -25;
	upper = 25;
	step = 3;

	celsius = lower;
	printf("1-4\n");
	while(celsius <= upper){
		fahr = 32 + celsius*(9.0/5.0);
		printf("%6.2f %6.2f\n", celsius, fahr);
		celsius += step;
	}


}
