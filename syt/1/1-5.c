#include <stdio.h>

main(){
	float celsius;
	for(celsius = 300; celsius >= 0; celsius = celsius - 20){
		printf("%6.1f %3f\n", celsius, (9.0/5.0)*celsius + 32.0);
	}
}
