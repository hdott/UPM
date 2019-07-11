#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct bucket
{
    int nr;
    struct bucket *next;
} BUCKET;

BUCKET *New(int nr)
{
    BUCKET *newp = (BUCKET*) malloc(sizeof(BUCKET));

    newp -> nr = nr;
    newp -> next = NULL;

    return newp;
}

void Insert(BUCKET **tracer, BUCKET *newp)
{
    while(*tracer)  tracer = &(*tracer) -> next;

    *tracer = newp;
}

void Clear(BUCKET **tracer)
{
    BUCKET *_toRemove = NULL;

    while(*tracer)
    {
        _toRemove = *tracer;
        *tracer =   (*tracer) -> next;

        free(_toRemove);
    }
}

typedef struct toBucket
{
    BUCKET *head;
    int sizeBucket;
} TOBUCKET;


int findMaxArr(int *vector, int size)
{
    int max = vector[0];

    for(int i=1; i<size; ++i)
        if(max < vector[i])
            max = vector[i];

    return  max;
}

int findMaxBucket(BUCKET **tracer)
{
    int max = (*tracer) -> nr;
    tracer = &(*tracer) -> next;

    while(*tracer)
    {
        if(max < (*tracer) -> nr)   max = (*tracer) -> nr;

        tracer = &(*tracer) -> next;
    }

    return max;
}

void CoutingSort(BUCKET **tracer, int size)
{
    int max = findMaxBucket(tracer)+1;
    int *count = (int*) calloc(max, sizeof(int));
    int *output = (int*) malloc(size * sizeof(int));

    BUCKET **t = tracer;
    while(*t)
    {
        count[(*t) -> nr]++;

        t = &(*t) -> next;
    }
    
    for(int i=1; i<max; ++i)        count[i] += count[i-1];
    
    t = tracer;
    while(*t)
    {
        output[--count[(*t) -> nr]] = (*t) -> nr;

        t = &(*t) -> next;
    }

    int i=0;
    t = tracer;
    while(*t)
    {
        (*t) -> nr = output[i++];

        t = &(*t) -> next;
    }

    free(count);
    free(output);
}

void BucketSort(int *vector, int size)
{
    int max = findMaxArr(vector, size);

    //create Buckets
    TOBUCKET *buckets = (TOBUCKET*) malloc(size * sizeof(TOBUCKET));
    for(int i=0; i<size; ++i)
    {
        buckets[i].head = NULL;
        buckets[i].sizeBucket = 0;
    }

    for(int i=0; i<size; ++i)
    {
        int index = vector[i]*size/(max+1);
        Insert(&buckets[index].head, New(vector[i])); 
        buckets[index].sizeBucket++;
    }

    for(int i=0; i<size; ++i)
    {
        if(!buckets[i].head)            continue;
        if(buckets[i].sizeBucket == 1)  continue;

        CoutingSort(&buckets[i].head, buckets[i].sizeBucket);
    }

    for(int i=0, index=0; i<size; ++i)
    {
        if(!buckets[i].head)            continue;
        
        BUCKET **tracer = &buckets[i].head;
        while(*tracer)
        {
            vector[index] = (*tracer) -> nr;
            // printf("%d\n", vector[index]);
            index++;
            tracer = &(*tracer) -> next;
        }

        Clear(&buckets[i].head);
    }

    free(buckets);
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
    BucketSort(vector, size);
    printVector(vector, size);

    free(vector);
    return 0;
}