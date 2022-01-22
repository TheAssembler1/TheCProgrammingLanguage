#include <stdio.h>

#define LOWER 0   //NOTE::Lower limit of table
#define UPPER 300 //NOTE::Upper limit
#define STEP 20   //NOTE::Step size

//NOTE::print Fahrenheit-Celsius table
main(){
	int fahr;

	for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32)); 
}
