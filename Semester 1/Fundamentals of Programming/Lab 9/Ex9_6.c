/*
Fie o propozitie data de la tastatura.
Sa se rastoarne fiecare cuvant in ea.
Sa se afiseze propozitia obtinuta.
Ex.
    Mi-am terminat temele de laborator.
    Ma-iM tanimret elemet ed rotarobal.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 81

void main()
{
    char string[MAXLEN];

    puts("Introduceti o propozitie");
    fgets(string,MAXLEN,stdin);

    char *pstring = strtok(string," \n");

    while(pstring)
    {
        for(int i=strlen(pstring)-1; i>= 0; --i)
            printf("%c",*(pstring+i));
        printf(" ");

        pstring = strtok(NULL," \n");
    }
    printf("\n");
}
