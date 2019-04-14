/* Sa se sorteze liniile unui fisier in ordine inversa alfabetic. Sa se foloseasca
 *  functia predefinita qsort.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int Compare(const void *a, const void *b)
{
    const char **A = (const char **)a;
    const char **B = (const char **)b;

    if(strcmp(*A, *B) < 0)  return 1;
    if(strcmp(*A, *B) > 0)  return -1;
    return strcmp(*A, *B);
}

void PrintList(char **stringS, int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("%s\n", stringS[i]);
    }
}

int main(void)
{
    FILE *file = fopen("ozymandias.txt", "r");

    int alloc = 0;
    int maximum = 0;
    int index = -1;

    char **stringS = NULL;

    while(!feof(file))
    {
        if(index == maximum-1)
        {
            ++alloc;

            char **_aux = (char**) realloc(stringS, (maximum = alloc*MAX) * sizeof(stringS));

            if(!_aux)   return -1;
            else        stringS = _aux;
        }

        char line[MAX];

        fgets(line, MAX, file);

        stringS[++index] = (char*) malloc(strlen(line)+1);
        strcpy(stringS[index], line);
    }
    fclose(file);

    qsort(stringS, index, sizeof(stringS), Compare);

    PrintList(stringS, index);

    for(int i=0; i<=index; ++i) free(stringS[i]);
    free(stringS);
    return 0;
}