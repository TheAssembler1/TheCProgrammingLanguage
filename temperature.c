#include <stdio.h>

//NOTE::Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300
main(){
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;   //NOTE::Lower limit of temperature table
	upper = 300; //NOTE::Upper limit
	step = 20;   //NOTE::Step size

	fahr = lower;
	while(fahr <= upper){
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
