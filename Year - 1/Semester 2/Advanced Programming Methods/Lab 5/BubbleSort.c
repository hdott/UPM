#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void BubbleSort(int *vector, int size)
{
    for(int i=0; i<size-1; ++i)
        for(int j=0; j<size-i-1; ++j)
            if(vector[j] > vector[j+1])
            {
                int aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
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
    BubbleSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}