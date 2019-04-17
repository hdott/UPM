#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void SelectionSort(int *vector, int size)
{
    for(int i=0; i<size-1; ++i)
    {
        int minI = i;

        for(int j=i+1; j<size; ++j)
            if(vector[j] < vector[minI])
                minI = j;

        int aux = vector[minI];
        vector[minI] = vector[i];
        vector[i] = aux;
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
    SelectionSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}