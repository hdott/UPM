/*
 * Sa se afiseze cel mai lung si cel mai scurt cuvant ale unui sir citit dintr-un
 *  fisier.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

static int maxim, minim;
static char *maxWord=NULL;
static char *minWord=NULL;

char *newItem(char *text, int size)
{
    char *point = realloc(text,size+1);
    
    return point;
}

static void findMaxMinWord_inString(char *input)
{   
    // printf("%s\t%s\n",*maxWord,*minWord); 
    char *pointMax=NULL, *pointMin=NULL;
    int size;
    char *pWord = strtok(input, " ,.!?");
    while(pWord)
    {
        size = strlen(pWord);

        if(size > maxim && maxWord)
        {
            pointMax = realloc(maxWord,size+1);
            printf("\t\t%zd\n",sizeof(pointMax));
            if(pointMax)
            {
                maxWord = pointMax;
                // memcpy(*maxWord,pWord,size);
                strcpy(maxWord,pWord);
                maxim = size;
            }
            else    exit(1);

            printf("ERROR1\t%s\n",maxWord);
        }
        else if(size < minim && minWord)
        {
            pointMin = realloc(minWord,size+1);

            if(pointMin)
            {
                minWord = pointMin;
                // memcpy(*minWord,pWord,size);
                strcpy(minWord,pWord);
                minim = size;
            }
            else    exit(1);

            printf("ERROR2\t%s\n",minWord);
        }
        else if(!maxWord && !minWord)
        {
            maxWord = (char*) malloc(size+1);
            minWord = (char*) malloc(size+1);

            maxWord = minWord = pWord;
            maxim = minim = size;

            printf("ERROR3\t%s\t%s\n",maxWord,minWord);
        }

        pWord = strtok(NULL, " ,.!?");
    }
}

int main(void)
{
    // char **maxWord = (char*) malloc(MAX);
    // char **minWord = (char*) malloc(MAX);
    char *input_string = (char*) malloc(MAX);

    // char *maxWord=NULL;
    // char *minWord=NULL;

    FILE *file = fopen("myfile.txt","r");
    
    if(file)
    {
        while(!feof(file))
        {
            fscanf(file, "%s", input_string);
            // printf("%p\t%p\n",&*maxWord,&*minWord);
            printf("%s\t%s\n",maxWord,minWord);
            findMaxMinWord_inString(input_string);
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