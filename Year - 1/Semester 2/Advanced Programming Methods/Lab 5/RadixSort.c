#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int findMaxArr(int *vector, int size)
{
    int max = vector[0];

    for(int i=1; i<size; ++i)
        if(max < vector[i])
            max = vector[i];

    return  max;
}

void CountingSortDigits(int *vector, int size, int exp)
{
    int count[10] = {0};
    int *output = (int*) malloc(size * sizeof(int));

    for(int i=0; i<size; ++i)       count[(vector[i]/exp)%10]++;

    for(int i=1; i<10; ++i)         count[i] += count[i-1];

    for(int i=size-1; i>=0; --i)   output[--count[(vector[i]/exp)%10]] = vector[i];

    for(int i=0; i<size; ++i)       vector[i] = output[i];

    free(output);
}

void RadixSort(int *vector, int size)
{
    int max = findMaxArr(vector, size);

    for(int exp=1; max/exp > 0; exp*=10)
        CountingSortDigits(vector, size, exp);
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