/*
Sa se citeasca o propozitie formata din mai multe cuvinte.
Sa se verifice daca este palindrom.
Ex:
    Ele fac cafele.
O propozitie este palindrom, daca ignorand diferenta dintre literele mari si mici
    si separatorii propozitiei, este identica cu propozitia cititida de la dreapta la stanga.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 81

void print_bool_palindrom(int x)
{
    if(x)
        puts("Propozita este palindrom!");
    else
        puts("Propozitia NU este palindrom!");
}

void checkif_palindrom_string(char *string)
{
    int j = strlen(string)-2;
    int check = 1;

    for(int i=0; i<j; ++i, --j)
        if(*(string+i) == ' ')
            ++j;
        else if(*(string+j) == ' ')
            --i;
        else if((*(string+i) != *(string+j) && *(string+i) != (*(string+j)+32)) &&
                    *(string+i) != *(string+j) && *(string+i) != (*(string+j)-32))
        {
            check = 0;
            break;
        }

    print_bool_palindrom(check);    
}

void main()
{
    char *string = (char*) malloc(MAXLEN);
    puts("Introduceti o propozitie pentru a verifica daca este palindrom");
    fgets(string,MAXLEN,stdin);

    checkif_palindrom_string(string);

    free(string);
}
