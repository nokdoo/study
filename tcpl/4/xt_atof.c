#include <ctype.h>
#include <math.h>
#include <stdio.h>
double xt_atof(char s[]){
	double val, power;
	int i, sign;
	int e;

	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;

	if(s[i] == '+' || s[i] == '-')
		i++;

	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	
	if(s[i] == '.')
		i++;
	
	for(power = 1.0; isdigit(s[i]); i++){
		val = 10.0 *val + (s[i] - '0');
		power *= 10.0;
	}

	val = sign*val/power;
	if(s[i] == 'e' || s[i] == 'E'){
		i++;
		sign = (s[i++] == '-') ? -1 : 1;
		for(e = 0; isdigit(s[i]); i++){
			e = 10 * e + (s[i] - '0');	
		}
		printf("e : %d\n", e);
		printf("val : %f\n", val);
		printf("pow : %f\n", pow(10,e*sign));
		val = val*(pow(10, e*sign));
		printf("val * pow : %f\n", (double)val);
	}

	return (double)val;
}
