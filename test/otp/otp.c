#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>

static void usage() {
  fputs("Usage: otp <text> <key(optional)>\n",stderr);
  exit(EXIT_FAILURE);
}

uint8_t* crypt(char *text, char *key){
	uint8_t *result[strlen(text)];
	printf("nr, text, key\n");
	for(size_t i=0; i<strlen(text); i++){
		printf("%zu: %x, %x\n", i,text[i],key[i]);
		result[i] = (uint8_t) text[i] ^ (uint8_t) key[i];
	}
	printf("Result: %x\n", result);
	return result;
}

char* key_gen(size_t tlen){
    char *c = malloc(sizeof(char)*(tlen+1));
	c[tlen] = '\0';
    srand(time(NULL));
    for(size_t i=0; i<tlen; i++){
		uint8_t k = (uint8_t)(rand()%256);
		c[i]= (char) k;
    }

	return c;
}

void check_key(size_t tlen, size_t klen){
	if(tlen != klen){
		fputs("Usage: <key> is optional and must be same length like text\n",stderr);
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char **argv){
	
	if(argc < 2 || argc > 3) usage();
	
	char *text = argv[1];
	char *key;
	
	if(argc == 3){
		key = argv[2];
		check_key(strlen(text), strlen(key));
	}else if(argc == 2){
		key = key_gen(strlen(text));
	}else{
		fputs("Usage: Error\n",stderr);
		exit(EXIT_FAILURE);
	}
	
	uint8_t *chiffre = crypt(text,key);
	uint8_t *plain = crypt((char)chiffre,key);
	printf("%s\n", plain);
	
	return 0;
}