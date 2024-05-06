#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char * decode(int key, char* text){
	char *s = malloc(strlen(text)+1);
	for(int i=0; i<strlen(text); i++){
		if(text[i] == ' ') s[i] = ' ';
		else s[i]= (((text[i]-'A') - i +26) % 26) + 'A';
	}
	return s;
}

int main(int argc, char *argv[]){

    char *text = argv[2];
	char *s;
	
	
	for(int i=0;i<26;i++){
		s = decode(i, text);
		printf("%d: %s",i,s);
	}

	 
	return 0;
}
