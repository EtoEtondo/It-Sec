#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
    char cmd [6];
    strcpy ( cmd , "clear");

    char name [10];
    scanf ( "%s" , name );

    system ( cmd ) ;
    printf ( "Hallo %s\n" , name ) ;
}

// echo "BCDEFGHI./xcalc" | ./tr
