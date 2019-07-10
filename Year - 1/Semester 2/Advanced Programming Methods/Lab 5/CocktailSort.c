#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CocktailSort(int *vector, int size)
{
    _Bool swapped = 1;
    int start = 0;
    int end = size;

    while(swapped)
    {
        swapped = 0;

        for(int i=start; i<end-1; ++i)
            if(vector[i] > vector[i+1])
            {
                int aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
                swapped = 1;
            }

        if(!swapped)    break;

        swapped = 0;
        end--;

        for(int i=end-1; i>=start; --i)
            if(vector[i] > vector[i+1])
            {
                int aux = vector[i];
                vector[i] = vector[i+1];
                vector[i+1] = aux;
                swapped = 1;
            }

        start++;
    }
}

void printVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

int main(int argc, char **argv)
{
    int size = argc-1;

    int *vector = (int*) calloc(size, sizeof(int));

    for(int i=1, index=0; i<argc; ++i, ++index)
        for(int j=0; j<strlen(argv[i]); ++j)
        {
            vector[index] *= 10;
            vector[index] += argv[i][j] - '0';
        }

    printVector(vector, size);
    CocktailSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}