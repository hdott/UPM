/*
Fie o propozitie data de la tastatura.
Sa se inlocuiasca fiecare numar cu un sir de * de lungimea numarului.
Ex.
    Aceasta propozitie contine 12 stelute.
    Aceasta propozitie contine ************ stelute.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 81

void main()
{
    char string[MAXLEN];

    puts("Introduceti o porpozitie care sa contina cel putin un numar");
    fgets(string,MAXLEN,stdin);

    char *pstring = strtok(string," ,.-\n");

    while(pstring)
    {
        int x;
        if(sscanf(pstring,"%d",&x))
        {
            for(int i=0; i<x; ++i)
                putchar('*');
            printf(" ");
        }
        else
            printf("%s ",pstring);
        
        pstring = strtok(NULL," ,.-\n");
    }
    printf("\n");
}
