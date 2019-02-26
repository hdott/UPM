/*
Sa se scrie un program care afiseaza numarul de aparitii ale fiecarui cuvant dintr-un text.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 81

int word_apparitions(char str[], char *p)
{
    char *pointerpoz = str;
    int counter = 0;

    pointerpoz = strstr(pointerpoz,p);
    while(pointerpoz)
    {
        ++counter;
        pointerpoz += strlen(p);
        pointerpoz = strstr(pointerpoz,p);
    }

    return counter;
}

void main()
{
    char string[MAXLEN], concat_string[MAXLEN], aux_string[MAXLEN];
    
    puts("Introduceti o propozitie sau o fraza de maxim 80 de caractere");
    fgets(string,MAXLEN,stdin);
    
    // copiem string-ul citit intr-un string auxiliar deoarce,
    // string-ul initial se va modifica cand folosim strtok()
    strcpy(aux_string,string);

    char *pstring = strtok(string," ,./!?\n");
    while(pstring)
    {
        // contorizeaza aparitia cuvantului in sirul initial
        int initial_counter          = word_apparitions(aux_string,pstring);
        
        // verifica daca cuvantul a mai fost verificat inainte
        int avoid_repetition_counter = word_apparitions(concat_string,pstring);
        
        strcat(concat_string,pstring);
        strcat(concat_string," ");

        if(!avoid_repetition_counter)
            printf("\"%-20s\" apare de %d ori\n",pstring,initial_counter);
        
        pstring = strtok(NULL," ,./!?\n");
    }
}
