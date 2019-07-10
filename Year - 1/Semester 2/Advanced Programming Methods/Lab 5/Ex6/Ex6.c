#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CountingSortInteger.h"
#include "BucketSortInteger.h"
#include "RadixSortInteger.h"


void autoGenerate(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        vector[i] = (random() % (size+size)) - (random() % (size+size));
}

int main(void)
{
    time_t t;
    srand((unsigned) time(&t));

    int size;
    printf("Introduceti marimea vectorului: ");
    scanf("%d", &size);

    int *vectorCounting = (int*) malloc(size * sizeof(int));
    int *vectorRadix = (int*) malloc(size * sizeof(int));
    int *vectorBucket = (int*) malloc(size * sizeof(int));

    autoGenerate(vectorCounting, size);

    for(int i=0; i<size; ++i)
    {
        vectorRadix[i] = vectorCounting[i];
        vectorBucket[i] = vectorCounting[i];
    }

    clock_t times = clock();
    CountingSortIntegers(vectorCounting, size);
    times = clock() - times;
    printf("CountingSort time   -> %lf\n", (double)times/CLOCKS_PER_SEC);

    times = clock();
    RadixSort(vectorRadix, size);
    times = clock() - times;
    printf("RadixSort time      -> %lf\n", (double)times/CLOCKS_PER_SEC);

    times = clock();
    BucketSort(vectorBucket, size);
    times = clock() - times;
    printf("BucketSort time     -> %lf\n", (double)times/CLOCKS_PER_SEC);

    free(vectorCounting);
    free(vectorRadix);
    free(vectorBucket);
    return 0;
}