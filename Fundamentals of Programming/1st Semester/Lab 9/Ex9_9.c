/*
Sa se determine prima si ultima aparitie a unui sir de caractere intr-un text.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 81
#define MAXARR 20

void printif_present(char *word, int counter, int poz[])
{
    if(counter==0)
        printf("\nElementul \"%s\" NU se regaseste in Textul dat\n", *word);
    else if(counter==1)
        printf("\nElementul \"%s\" apare o singura data in pozitia: %d\n",word,poz[0]);
    else
    {
        printf("\nElementul \"%s\" apare de %d ori.\n",word,counter);
        printf("Prima aparitie este pe pozitia: %d\n", poz[0]);
        printf("Ultima aparitie este pe pozitia: %d\n", poz[counter-1]);
    }
}

void checkif_present(char *word, char string[], int length)
{
    int aux[MAXARR], counter=0;
    
    for(int i=0; i<strlen(string)-length; ++i)
        if(!strncmp(string+i,word,length))
            aux[counter++] = i+1;

    printif_present(word,counter,aux);
}

void main()
{
    char string[MAXLEN], search_string[MAXLEN];

    puts("Introduceti un Text de maxim 80 de caractere:");
        fgets(string,MAXLEN,stdin);
    puts("Introduceti un sire de caractere pentru"
            " a fi cautat in Textul introdus");
        fgets(search_string,MAXLEN,stdin);

    search_string[strlen(search_string)-1] = '\0';

    checkif_present(search_string,string,strlen(search_string));
}
