/*
Sa se citeasca o propozitie (formata din mai multe cuvinte) de la tastatura.
Sa se afiseze de cate ori apare fiecare caracter.
Obs.
    Se declara un tablou de 256 de elemente.
    Indexul tabloului reprezinta codul ASCII al caracterului.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 81
#define MAXARR 256

void count_print_characters(int *T, char *string)
{
    for(int i=0; i<81; ++i)
        (*(T+*(string+i)))++;

    for(int i=35; i<256; ++i)
        if(*(T+i))
            printf("[%c] apare de %d ori\n",i,*(T+i));
}

void main()
{
    char *string = (char*) calloc(MAXLEN,sizeof(char));
    int *T = (int*) calloc(MAXARR,sizeof(int));

    puts("Introduceti o propozitie cu mai multe cuvinte (max 80 caractere)");
    fgets(string,MAXLEN,stdin);
    
    count_print_characters(T,string);

    free(T);
    free(string);
}
