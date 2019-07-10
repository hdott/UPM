#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int BinarySearchIterrative(int *vector, int size, int key)
{
    int start = 0,
        mid,
        end = size;

    while(start<end)
    {
        mid = start + (end-start)/2;

        if(key < vector[mid])   
        {
            end = mid;
            continue;
        }

        if(key > vector[mid])   
        {
            start = mid+1;
            continue;
        }

        return 1;
    }
}

int BinarySearchRecursive(int *vector, int start, int end, int key)
{
    if(start<end)
    {
        int mid = start + (end-start)/2;

        if(key < vector[mid])   
            return BinarySearchRecursive(vector, start, mid, key);

        if(key > vector[mid])
            return BinarySearchRecursive(vector, mid+1, end, key);

        return 1;
    }
}

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

int main(void)
{
    int size;
    printf("Introduceti marimea vectorului: ");
    scanf("%d", &size);

    time_t t;
    srand((unsigned) time(&t));

    int *vector = (int*) malloc(size * sizeof(int));

    autoGenerate(vector, size);

    //for n/4
    printf("Elapsed time for n/4:\n");

    clock_t elapsed = clock();
    BinarySearchIterrative(vector, size, vector[size/4]);
    elapsed = clock() - elapsed;
    printf("BSIterrative time   -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    elapsed = clock();
    BinarySearchRecursive(vector, 0, size-1, vector[size/4]);
    elapsed = clock() - elapsed;
    printf("BSRecursive time    -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    elapsed = clock();
    bsearch(&vector[size/4], vector, size, sizeof(int), Compare);
    elapsed = clock() - elapsed;
    printf("BSearch time        -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    //for n/2
    printf("\nElapsed time for n/5:\n");

    elapsed = clock();
    BinarySearchIterrative(vector, size, vector[size/5]);
    elapsed = clock() - elapsed;
    printf("BSIterrative time   -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    elapsed = clock();
    BinarySearchRecursive(vector, 0, size-1, vector[size/5]);
    elapsed = clock() - elapsed;
    printf("BSRecursive time    -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    elapsed = clock();
    bsearch(&vector[size/5], vector, size, sizeof(int), Compare);
    elapsed = clock() - elapsed;
    printf("BSearch time        -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    //for n-1
    printf("\nElapsed time for n-1:\n");

    elapsed = clock();
    BinarySearchIterrative(vector, size, vector[size-1]);
    elapsed = clock() - elapsed;
    printf("BSIterrative time   -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    elapsed = clock();
    BinarySearchRecursive(vector, 0, size-1, vector[size-1]);
    elapsed = clock() - elapsed;
    printf("BSRecursive time    -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);

    elapsed = clock();
    bsearch(&vector[size-1], vector, size, sizeof(int), Compare);
    elapsed = clock() - elapsed;
    printf("BSearch time        -> %lf\n", (double)elapsed/CLOCKS_PER_SEC);
    
    
    free(vector);
    return 0;
}