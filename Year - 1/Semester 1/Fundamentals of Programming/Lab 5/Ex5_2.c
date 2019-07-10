/*
Să se afișeze toate caracterele din tabela ASCII (0,255) separate prin spațiu.
*/

#include <stdio.h>

void main()
{
    int i = 0;

    printf("while:\t  ");
        while(i < 256)
        {
            printf("%c ", i);
            ++i;
        }    
    printf("\n\n");

    printf("do while: ");
        i = 0;
        do
        {
            printf("%c ", i);
            ++i;
        }   while(i < 256);
    printf("\n\n");

    printf("for:\t  ");
        for(i = 0; i < 256; ++i)
            printf("%c ", i);
    printf("\n");
}
