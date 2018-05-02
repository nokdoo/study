#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
	static char *number[] = {
		"zero", 
		"one", "two", "three", "four", "five", "six", 
		"seven", "eight", "nine", "ten", "eleven", "twelve",
		"thirteen", "fourteen", "fifteen", "sixteen", "seven teen", "eighteen",
		"nineteen", "twenty", "twenty one", "twenty two", "twenty three", "twenty four",
		"twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"

	};
	int h; 
	scanf("%d",&h);
	int m; 
	scanf("%d",&m);
	if(m == 0){
		printf("%s o' clock", number[h]);
	}else if(m == 15){
		printf("quarter past %s", number[h]);
	}else if(m < 30 && m > 0){
		printf("%s minutes past %s", number[m], number[h]);
	}else if(m == 30){
		printf("half past %s", number[h]);
	}else if(m == 45){
		if(h == 12){
			printf("quarter to %s", number[1]);    
		}else{
			printf("quarter to %s", number[h+1]);
		}
	}else{
		if(h == 12){
			printf("%s minutes to %s", number[60-m], number[1]);    
		}else{
			printf("%s minutes to %s", number[60-m], number[h+1]);
		}

	}
	return 0;
}

