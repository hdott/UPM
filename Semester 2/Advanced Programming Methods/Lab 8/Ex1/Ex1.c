#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "MergeSort.h"
#include "QuickSortMo3.h"
#include "QuickSortRnd.h"


void autoGenerate(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        vector[i] = (random() % (size*4)) - 
                    (random() % (size*4));
}

int Compare(const void *a, const void *b)
{
    const int *x = (const int *)a;
    const int *y = (const int *)b;

    if(*x > *y) return 1;
    if(*x < *y) return -1;

    return 0;
}

void printVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

int main(void)
{
    time_t t;
    srand((unsigned) time(&t));

    int size;
    printf("Introduceti marimea vectorilor: ");
    scanf("%d", &size);

    int *vectorQSORT = (int*) malloc(size * sizeof(int));
    int *vectorQUICK = (int*) malloc(size * sizeof(int));
    int *vectorMERGE = (int*) malloc(size * sizeof(int));
    int *vectorQUICKR = (int*) malloc(size * sizeof(int));

    autoGenerate(vectorQSORT, size);

    for(int i=0; i<size; ++i)
        vectorQUICK[i] = vectorMERGE[i] = vectorQUICKR[i] =  vectorQSORT[i];

    // printVector(vectorQSORT, size);
    clock_t elapsed = clock();
    qsort(vectorQSORT, size, sizeof(int), Compare);
    elapsed = clock() - elapsed;
    printf("QSORT    time -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);
    // printVector(vectorQSORT, size);

    // printVector(vectorQUICK, size);
    elapsed = clock();
    QuickSortMo3(vectorQUICK, 0, size-1);
    elapsed = clock() - elapsed;
    printf("QUICKMO3 time -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);
    // printVector(vectorQUICK, size);

    // printVector(vectorMERGE, size);
    elapsed = clock();
    MergeSort(vectorMERGE, 0, size-1);
    elapsed = clock() - elapsed;
    printf("MERGE    time -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);
    // printVector(vectorMERGE, size);

    // printVector(vectorQUICKR, size);
    elapsed = clock();
    QuickSortRnd(vectorQUICKR, 0, size-1);
    elapsed = clock() - elapsed;
    printf("QUICKRND time -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);
    // printVector(vectorQUICKR, size);


    free(vectorQSORT);
    free(vectorQUICK);
    free(vectorMERGE);
    free(vectorQUICKR);
    return 0;
}