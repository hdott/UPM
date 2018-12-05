/*
Să se afişeze următorul text pe ecran (fără a folosi caracterul spaţiu):
AA
    AA
        "AA"
    AA
BB
    BB
    BB  "BB"
    BB
BB
*/

#include <stdio.h>

void main()
{
    printf("AA\n");
    printf("\tAA\n");
    printf("\t\t\"AA\"\n");
    printf("\tAA\n");
    printf("BB\n");
    printf("\tBB\n");
    printf("\tBB\t\"BB\"\n");
    printf("\tBB\n");
    printf("BB\n");
}
