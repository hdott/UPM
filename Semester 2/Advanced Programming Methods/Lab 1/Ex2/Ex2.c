/*
 * Sa se numere aparitia unui cuvant dat de la tastatura intr-un fisier text.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(void)
{
    char c;
    char *input_word = (char*) malloc(MAX*sizeof(char));
    char *word = (char*) malloc(MAX*sizeof(char));
    int count=0;

    printf("Introduceti un cuvant pentru a fi cautat in fisier: ");
        scanf("%[^\n]s",input_word);

    FILE *file = fopen("myfile.txt","r");
    if(file)
    {
        while(!feof(file))
        {
            fscanf(file,"%s",word);
            if(!strcmp(word,input_word))    ++count;
        }
    }

    (count > 1) ? printf("\"%s\" apare de %d ori in fisier.\n",input_word,count) :
    (count = 1) ? printf("\"%s\" apare o singura data in fisier.\n",input_word) :
                printf("\"%s\" NU apare in fisier.\n",input_word);


    fclose(file);
    free(input_word);
    free(word);

    return 0;
}