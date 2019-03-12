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
    int maxim, minim, size;
    char *wordS=NULL, *wordB=NULL, *input=NULL, *point=NULL;
    
    input = (char*) malloc(MAX*sizeof(char));

    FILE *file = fopen("myfile.txt","r");
    
    fscanf(file,"%s",input);
        maxim = minim = strlen(input);
        wordB = (char*) malloc((maxim+1)*sizeof(char));
        wordS = (char*) malloc((minim+1)*sizeof(char));
        wordB = wordS = input;
        // fseek(file,strlen(input),SEEK_SET);
        puts(input);
    
    if(file)
    {
        while(!feof(file))
        {
            fscanf(file,"%s",input);
            size = strlen(input);

            if(size > maxim)
            {
                point = (char*) realloc(wordB,(size+1)*sizeof(char));
                puts("ERROR1");
                if(point)
                {
                    wordB = point;
                    maxim = size;
                    wordB = input;
                }
            }
            else if(size < minim)
            {
                point = (char*) realloc(wordS,(size+1)*sizeof(char));
                puts("ERROR2");
                if(point)
                {
                    wordS = point;
                    minim = size;
                    wordS = input;
                }
            }
        }
    }

    printf("Cel mai mare cuvant citit este %s, are %d litere\n", wordB, maxim);
    printf("Cel mai mic cuvant citit este %s, are %d litere\n", wordS, minim);
    
    fclose(file);
    free(input);
    free(wordB);
    free(wordS);
    return 0;
}