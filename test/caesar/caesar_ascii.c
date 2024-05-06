#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *klartext, int key, int length){
    char chiffre[length];

    for(int i = 0; i<length; i++){
     	chiffre[i] = (((klartext[i]-'A') + key) % 26) + 'A'; 	
    }

    printf("Der Chiffretext lautet: %s", chiffre);
}

void decrypt(char *chiffretext, int key, int length){
    char klar[length];

    for(int i = 0; i<length; i++){
     	klar[i] = (((chiffretext[i]-'A') - key +26) % 26) + 'A';
    }

    printf("Der Klartext lautet: %s", klar);
}

int main(int argc, char *argv[]){

   if(argc < 4){
     printf("Sie müssen diese Parameter eingeben: key, mode(encrypt oder decrypt), message/chiffre");
   	 return -1;
   }

     int key = atoi(argv[1]);
     char *mode = argv[2];
     char *text = argv[3];
     int length = strlen(text);
	 
	 
 	for(size_t i=0; i<strlen(mode); i++) mode[i]=toupper(mode[i]);
 	for(size_t j=0; j<strlen(text); j++){text[j]=toupper(text[j]);}
	
    if(strcmp(mode, "ENCRYPT") == 0) encrypt(text, key, length);
    else if(strcmp(mode, "DECRYPT") == 0) decrypt(text, key, length);
	 
	return 0;
}


