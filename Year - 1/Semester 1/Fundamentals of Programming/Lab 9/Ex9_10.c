/*
Se da un cuvant de lla tastatura.
Sa se codifice acest cuvant in lima "pasareasca",
    adica dupa fiecare vocala sa se adauge grupul de litere format din
    caracterul 'p' urmat de vocala respectiva
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 81

void pasareascato_initial(char string[])
{
    char *stringto_initial = (char*) calloc(MAXLEN,sizeof(char));

    for(int i=0; i<=strlen(string); ++i)
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' ||
                string[i] == 'o' || string[i] == 'u')
        {
            strncat(stringto_initial,&string[i],1);
            i += 2;
        }
        else
            strncat(stringto_initial,&string[i],1);
    
    printf("Cuvantul \"%s\" decodat din pasareasca este: %s\n",
                string,stringto_initial);
    free(stringto_initial);
}

void pasareasca(char string[])
{
    char *string_modified = (char*) calloc(MAXLEN,sizeof(char));

    for(int i=0; i<=strlen(string); ++i)
        if(string[i] == 'a' || string[i] == 'e' || string[i] == 'i' ||
                string[i] == 'o' || string[i] == 'u')
        {
            strncat(string_modified,&string[i],1);
            strcat(string_modified,"p");
            strncat(string_modified,&string[i],1);
        }
        else
            strncat(string_modified,&string[i],1);

    printf("\nCuvantul \"%s\" in pasareasca este %s\n",string,string_modified);
    pasareascato_initial(string_modified);
    free(string_modified);
}

void main()
{
    char string_to_modify[MAXLEN];

    puts("Introduceti un cuvant pentru a fi transformat in pasareasca");
        scanf("%s",string_to_modify);
    
    pasareasca(string_to_modify);
}
