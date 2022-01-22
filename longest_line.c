#include <stdio.h>

#define MAXLINE 1000 //NOTE::Max input line size

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len; //NOTE::Current line length
	int max; //NOTE::Maximum length seen so far
	char line[MAXLINE]; //NOTE::Current input line
	char longest[MAXLINE]; //NOTE::Longest line saved here

	max = 0;
	while((len = getline(line, MAXLINE)) > 0){
		if(len > max){
			max = len;
			copy(longest, line);
		}
	}

	if(max > 0) //NOTE::There was a line
		printf("%s", longest);
	
	return 0;
}

//NOTE::getline: read a line into so, return length
int getline(char s[], int lim){
	int c, i;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if(c == '\n'){
		s[i] = c;
		++i;
	}

	s[i] = '\n';
	return i;
}

//NOTE::copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;
}
