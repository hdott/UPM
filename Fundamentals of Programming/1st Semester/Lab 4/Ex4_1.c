/*
Să se afișeze codul ASCII al caracterelor: 
'a', 'A', 'z', 'Z', 'o', '9', '.', '-', '+'
*/

#include <stdio.h>

void main()
{
    printf("  Element\tASCII\n");
        printf("-----------------------\n");
        printf("%6c\t\t%4d\n", 'a', 'a');
        printf("%6c\t\t%4d\n", 'A', 'A');
        printf("%6c\t\t%5d\n", 'z', 'z');
        printf("%6c\t\t%4d\n", '0', '0');
        printf("%6c\t\t%4d\n", '9', '9');
        printf("%6c\t\t%4d\n", '.', '.');
        printf("%6c\t\t%4d\n", '-', '-');
        printf("%6c\t\t%4d\n", '+', '+');
}
