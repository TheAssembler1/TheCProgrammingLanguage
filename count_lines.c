#include <stdio.h>

//NOTE::Count lines in input
main(){
	int c; n1;

	n1 = 0;
	while((c = getchar()) != EOF)
		if(c == '\n')
			++n1;

	printf("%d\n", n1);
}