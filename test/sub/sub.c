// ./sub 1 beispielklartext XCFNITKJUOLBPDAHSGQMZVWERY
// ./sub 2 CIUQHUIBLBXGMIEM XCFNITKJUOLBPDAHSGQMZVWERY
// ./sub 1 beispielklartext

#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

static void usage() {
  fputs("Usage: sub <mode> <text> <key(optional)>\n",stderr);
  exit(EXIT_FAILURE);
}

void encrypt(char *ktext, char *key, char *alphabet){
	int arrae[strlen(ktext)];
	for(size_t i=0; i<strlen(ktext); i++){
		for(size_t j=0; j<strlen(alphabet); j++){
			if(ktext[i] == 'A'+j) arrae[i]=j; //statt alphabet könnte 'A'+j alphabet[j]
		}
	}
	puts("Encrypted Text below:");
	for(size_t k=0; k<strlen(ktext); k++){
		printf("%c", key[arrae[k]]);
	}
}

void decrypt(char *ktext, char *key, char *alphabet){
	int arrae[strlen(ktext)];
	for(size_t i=0; i<strlen(ktext); i++){
		for(size_t j=0; j<strlen(key); j++){
			if(ktext[i] == key[j]) arrae[i]=j;
		}
	}
	
	for(size_t k=0; k<strlen(ktext); k++){
		printf("%c", alphabet[arrae[k]]); //statt alphabet könnte 'A'+arrae[k]
	}
}

void check_key(char* key, size_t key_len){
	if(key_len != 26){
	    fputs("Usage: <key> needs to be in range of the alphabet (26) and no double Chars\n",stderr);
	    exit(EXIT_FAILURE);
	}
	
	for(size_t i=0; i<key_len; i++){
		for(size_t j=i+1; j<key_len; j++){
			if(key[i] == key[j]){
			    fputs("Usage: <key> needs to be in range of the alphabet (26) and no double Chars\n",stderr);
			    exit(EXIT_FAILURE);
			}
		}
	}
}

void check_mode_nstart(int mode, char *ktext, char *key, char *alphabet){
	if(mode == 1){
		encrypt(ktext, key, alphabet);
	}else if(mode == 2){
		decrypt(ktext, key, alphabet);
	}else{
	    fputs("Usage: <mode> 1 for encrypt; 2 for decrypt\n",stderr);
	    exit(EXIT_FAILURE);
	}
}

char* key_generator(char *alphabet){
    char *c = malloc(sizeof(char)*(strlen(alphabet)+1));
	c[26] = '\0';
    srand(time(NULL));
    for(size_t i=0; i<strlen(alphabet); i++){
        while(1){
            int ok = 1;
            int k = ((unsigned int) rand())%26;
            for(size_t j=0; j < i; j++) if(c[j] == alphabet[k]) {ok = 0; break;}; //oder alphabet[k]
            if(!ok) continue;
            c[i] = alphabet[k];
            break;
        }
    }

    printf("Generated Key: %s \n", c);
    return c;
}

int main(int argc, char **argv){
	char alphabet[26];
	for(int n=0; n<26; n++) alphabet[n]= 'A'+n; //ASCII
	
	if(argc < 3 || argc > 4) usage(); 
	
	int mode = atoi(argv[1]);
	char *ktext = argv[2];
	char *key;
	
	if(argc == 4){
		key = argv[3];
		check_key(key, strlen(key));
	}else if(argc == 3 && mode == 1){
		key = key_generator(alphabet);
	}else{
		fputs("Usage: <key> is optional but works only for encrypt mode (1)\n",stderr);
		exit(EXIT_FAILURE);
	}
	
	size_t key_len = strlen(key);
	size_t ktext_len = strlen(ktext);
	for(size_t i=0; i<ktext_len; i++) ktext[i]=toupper(ktext[i]);
	for(size_t j=0; j<key_len; j++) key[j]=toupper(key[j]);

	check_mode_nstart(mode, ktext, key, alphabet);
	
	return 0;
}