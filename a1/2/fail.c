# include <stdio.h>
# include <stdlib.h>

enum { BUFFER_SIZE = 10 };

int main () {
    int check1 = 0;
    char buffer [ BUFFER_SIZE ];
    int check2 = 0;

    scanf (" %s " , buffer );

    if( check1 || check2 ) puts (" You Win " );

    return EXIT_SUCCESS ;
}

// mit 11 überschreiben
// canarie flags und %9s  und umsortieren um abzusichern
