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

int findMinArr(int *vector, int size)
{
    int min = vector[0];

    for(int i=1; i<size; ++i)
        if(min > vector[i])
            min = vector[i];

    return min;
}

void CountingSort(int *vector, int size)
{
    int max = findMaxArr(vector, size);
    int min = findMinArr(vector, size);
    int range = max-min+1;

    int *count = (int*) calloc(range, sizeof(int));
    int *output = (int*) malloc(size * sizeof(int));

    for(int i=0; i<size; ++i)       count[vector[i]-min]++;

    for(int i=1; i<range; ++i)      count[i] += count[i-1];

    for(int i=size-1; i>=0; --i)    output[--count[vector[i]-min]] = vector[i];

    for(int i=0; i<size; ++i)       vector[i] = output[i];

    free(count);
    free(output);
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
    CountingSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}