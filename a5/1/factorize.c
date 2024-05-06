#include <stdio.h>
#include <stdlib.h>
#include <math.h>


static void usage() {
  fputs("Usage: factorize <n> <Phi(n)>\n",stderr);
  exit(EXIT_FAILURE);

}


long factorp(long n, long phin) {
   long z = n - phin;
   long x = (z+1) * (z+1);
   long y = x - 4*n;
   long p = (long)  (sqrt((double) x) + sqrt((double) y)) / 2;
   return p;
}



int main(int args, char *argv[]) {
   if(args != 3) usage();

   long n    = atol(argv[1]);
   long phin = atol(argv[2]);
  
   if( (n<6) || (phin < 2) || (phin >= n)) usage();
  
   long p = factorp(n, phin);
   long q = n/p;

   printf("%ld, %ld\n",p, q);


    
}

