/*
Fie doua siruri de caractere de lungimi egale citite de la tastatura.
Primul este format din litere, celelalt din cifre.
Sa se repete fiecare litera de atatea ori cat inidica cifre de pe aceasi pozitie.
Ex.
    "abcd" "5123" => "aaaaabccddd"
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 30

void main()
{
    char a[MAXLEN], b[MAXLEN];

    puts("Introduceti un sire de caractere");
    fgets(a,MAXLEN,stdin);
    puts("Introduceti un sire de cifre");
    fgets(b,MAXLEN,stdin);

    for(int i=0; a[i]; ++i)
        for(int j=0; j<b[i]-'0'; ++j)
            printf("%c",a[i]);
    printf("\n");
}
