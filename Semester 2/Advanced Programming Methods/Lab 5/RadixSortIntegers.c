#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void CountingSortBytes(int *vector, int size, int bytePoz)
{
    int count[256] = {0};
    int *output = (int*) malloc(size * sizeof(int));
    int range = 256;
    __uint8_t *pI = NULL;

    for(int i=0; i<size; ++i)       
    {
        pI = (__uint8_t*) &vector[i];
        count[*(pI+bytePoz)]++;
    }

    for(int i=1; i<range; ++i)      count[i] += count[i-1];

    for(int i=size-1; i>=0; --i)    
    {
        pI = (__uint8_t*) &vector[i];
        output[--count[*(pI+bytePoz)]] = vector[i];
    }

    int index;
    for(index=0; index<size; ++index)
        if(output[index]<0) break;

    for(int i=0; i<size; ++i, ++index)
    {
        if(index==size) index=0;

        vector[i] = output[index];
    }

    free(output);
}

void RadixSort(int *vector, int size)
{
    for(int i=sizeof(int)-1; i>=0; --i)
        CountingSortBytes(vector, size, i);
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
    RadixSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}