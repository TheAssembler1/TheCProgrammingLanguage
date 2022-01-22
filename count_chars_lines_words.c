#include <stdio.h>

#define IN 1  //NOTE::Inside a word
#define OUT 0 //NOTE::Outside a word

//NOTE::Count lines, words, and characters in input
int main(){
	int c, nl, nw, nc, state;

	state = OUT;
	n1 = nw = nc = 0;
	while((c = getchar()) != EOF){
		++nc;
		if(c == "\n")
			++nl;
		if(c == ' ' || c == '\n' || c == '\t')
			state = OUT;
		else if(state == OUT){
			state = IN;
			++nw;
		}
	}

	printf("%d %d %d\n", nl, nw, nc);
}