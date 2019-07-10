/*
 * Sa se afiseze cel mai lung si cel mai scurt cuvant ale unui sir citit dintr-un
 *  fisier.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main(void)
{
    int maxim, minim, count=0, size;
    char *maxWord = (char*) malloc(MAX*sizeof(char));
    char *minWord = (char*) malloc(MAX*sizeof(char));
    char *input_string = (char*) malloc(MAX*sizeof(char));

    FILE *file = fopen("myfile.txt","r");
    char *pWord;
    if(file)
    {
        while(!feof(file))
        {
            fscanf(file, "%s", input_string);

            pWord = strtok(input_string," ,.!?/");
            while(pWord != NULL)
            {
                size = strlen(pWord);

                if(!count)
                {
                    strcpy(maxWord,pWord);
                    strcpy(minWord,pWord);
                    maxim = minim = size;
                    count=1;
                }
                else if(maxim < size)
                {
                    strcpy(maxWord,pWord);
                    maxim = size;
                }
                else if(minim > size)
                {
                    strcpy(minWord,pWord);
                    minim = size;
                }

                pWord = strtok(NULL," ,.!?/");
            }
        }
    }

    printf("Cel mai mare cuvant citit este %s, are %d litere\n", maxWord, maxim);
    printf("Cel mai mic cuvant citit este %s, are %d litere\n", minWord, minim);
    
    fclose(file);
    free(input_string);
    free(maxWord);
    free(minWord);
    return 0;
}