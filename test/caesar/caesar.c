#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc , char* argv[])
    {
       if(argc != 2)
         {
            return -1;
         }
    int k = atoi(argv[1]);
    printf("Enter the text to be encrypted: ");
    char text[20];
    scanf("%s", text);
    int length = strlen(text);
    for(int i=0 ; i<length ; i++)
       {
           int p = toupper(text[i]);
           int c = ((p - 'A') + k) % 26 + 'A'; 
           printf("%c",c);
        }
   }
