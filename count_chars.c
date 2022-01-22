#include <stdio.h>

//NOTE::Count characters in input; 1rst version
main(){
	long no;

	no = 0;
	while(getchar() != EOF)
		++no;

	printf("%ld\n", no);
}