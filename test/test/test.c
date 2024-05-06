#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
char cmd [6];
char name [10];
strcpy ( cmd , "clear") ;

scanf (" %9s " , name );

system ( cmd ) ;
printf ( " Hallo %s\n" , name ) ;
}