#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

uint8_t C[] = { 17, 4, 1, 26, 0, 24, 23, 23, 10, 1, 28, 19, 19, 15, 20, 30, 6, 11, 4, 8,
          17, 29, 23, 1, 24, 23, 28, 17, 20, 18, 9, 27, 17, 13, 13, 10, 13,
          18, 7, 4, 22, 23, 10, 22, 13, 27, 8, 5, 28, 1, 23, 26, 19, 12, 6,
          0, 8, 7, 2, 15, 0, 3, 7, 0, 9, 7, 29, 19, 19, 3, 2, 29, 27, 8, 11,
          7, 0, 6, 17, 26, 10, 26, 31, 26 };


uint8_t * encode(char *s) {
  uint8_t *a = malloc(strlen(s));

  for(size_t i=0; i< strlen(s);i++) {
      char c = toupper(s[i]);
     if( !isupper(c) ) {
        free(a);
        return NULL;
     }
      a[i] = c-'A'+1;
   } 
  return a;
}

char * decode(uint8_t *a, int n) {
   char *s = malloc(n+1);
   for(int i=0; i<n;i++) {
     s[i] = a[i]+'A'-1;
     if ( ! isupper(s[i]) ) {
        free(s);
        return NULL; 
     }
   }
  s[n] = '\0';
  return s;
}

void xortest(uint8_t *a, char *s, size_t len) {
  uint8_t *b = encode(s);
  size_t n = strlen(s);
  uint8_t result[n];
  for(size_t i=0; i<len-n;i++) {
     for(size_t j=0;j<n;j++) result[j] = b[j] ^ a[i+j]; 
     char *s = decode(result,n);
     if(s) {
       printf("%ld. %s\n", i, s);
       free(s);
     }
  }
} 


int main() {
   size_t len = sizeof(C);
   xortest(C,"Kryptographie",len);
    xortest();
   //puts(decode(encode("Hallo"),5));
}
