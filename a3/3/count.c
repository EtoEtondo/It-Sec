#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define LEN 26

typedef struct  {
  int ctr[LEN];
  int total;
} c_ctx;

static const char *C1= "GPSBONLPZ BRP JINL PRZEKNL PRZFKH JRPBPZ CHKSYPWY ILZP CPZZYZRB JPB BNLHOPBBPHB TOPZY BNLHO PBBPHZ";
                 //   es ist wahr  wir lieben das leben nicht weil wir ans leben sondern
static const char *C2="PB RBY QKLS QRS HRPXPZ JKB HPXPZ ZRNLY QPRH QRS KZB HPXPZ BIZJPSZ QPRHQRS KZBHR PXPZA PQIPL ZYBRZ JPBRB YRFFP SPYQK BQKLZ BRZZR ZJPSH RPXPP BRBYK XPSRF FPSKO NLPYQ KBGPS ZOZEY RFQKL ZBRZZ";

//enirtsadhlugmocbfkwzpvüäjößyxq


void _cleanout(char *m) {
  for(size_t i=0; i<strlen(m); i++) 
      if(isupper(m[i])) m[i]='_';
}


void cleanout(char *m1, char *m2) {
  _cleanout(m1);
  _cleanout(m2);
   puts(m1);
   puts(m2);
}


   
void _replace(char a, char b, char *m) {
  for(size_t i=0; i<strlen(m); i++) 
      if(m[i] ==  a) m[i]=b;
}

void replace(char a, char b, char *m1, char *m2) {
  _replace(a,b,m1);
  _replace(a,b,m2);
}



void count(c_ctx *ctx, const char *m) {
  for(size_t i=0; i<strlen(m); i++) 
     if(isupper(m[i])) {
         ctx->total +=1;
         ctx->ctr[m[i]-'A'] +=1;
  }
}  


void output(c_ctx *ctx) {
  double t = ctx->total;   
  for(int i=0; i<LEN; i++) 
      printf("%c = %02.2lf\n", (char) (i+'A'), 100* (double) (ctx->ctr[i])/t);  
}

int main() {
  c_ctx ctx = { {0}, 0 };
  count(&ctx ,C1);
  count(&ctx ,C2);
  output(&ctx);

  char *m1 = malloc(strlen(C1)+1);
  char *m2 = malloc(strlen(C2)+1);
  strncpy(m1,C1,strlen(C1));
  strncpy(m2,C2,strlen(C2));

   replace('G','v', m1,m2);
   replace('P','e', m1,m2); 
   replace('S','r', m1,m2);
   replace('B','s', m1,m2);
   replace('O','u', m1,m2);
   replace('N','c', m1,m2);
   replace('L','h', m1,m2);
   replace('Z','n', m1,m2);
   replace('R','i', m1,m2);
   replace('I','o', m1,m2);
   replace('J','d', m1,m2);
   replace('E','f', m1,m2);
   replace('K','a', m1,m2);
   replace('F','m', m1,m2);
   replace('H','l', m1,m2);
   replace('C','k', m1,m2);
   replace('Y','t', m1,m2);
   replace('W','x', m1,m2);
   replace('T','z', m1,m2);
   replace('Q','w', m1,m2);
   replace('X','b', m1,m2);
   replace('A','g', m1,m2);
    
   //puts(m2);
   cleanout(m1,m2);


  free(m1);
  free(m2);

}

