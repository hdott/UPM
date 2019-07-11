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


static int findMaxArr(int *vector, int size)
{
    int max = vector[0];

    for(int i=1; i<size; ++i)
        if(max < vector[i])
            max = vector[i];

    return  max;
}

static int findMinArr(int *vector, int size)
{
    int min = vector[0];

    for(int i=1; i<size; ++i)
        if(min > vector[i])
            min = vector[i];

    return min;
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

void CountingSort(BUCKET **tracer, int size)
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

//divide the vector in 2 vectors of buckets
//1 for negative numbers
//1 for positive numbers
void BucketSort(int *vector, int size)
{   
    int negative = 0;
    for(int i=0; i<size; ++i)
        if(vector[i] < 0)
            negative++;
    int positive = size-negative;

    int max = findMaxArr(vector, size);
    int min = findMinArr(vector, size);

    //create Buckets
    //and initialize them
    TOBUCKET *bucketsNEG = (TOBUCKET*) malloc(negative * sizeof(TOBUCKET));
    TOBUCKET *bucketsPOZ = (TOBUCKET*) malloc(positive * sizeof(TOBUCKET));

    if(negative)
    {
        for(int i=0; i<negative; ++i)
        {
            bucketsNEG[i].head = NULL;
            bucketsNEG[i].sizeBucket = 0;
        }
    }

    //for positive
    for(int i=0; i<positive; ++i)
    {   
        bucketsPOZ[i].head = NULL;
        bucketsPOZ[i].sizeBucket = 0;
    }

    //distribute the numbers to buckets
    if(negative)
    {
        for(int i=0; i<size; ++i)
            if(vector[i] < 0)
            {
                int index = (-vector[i])*negative/((-min)+1);
                Insert(&bucketsNEG[index].head, New(-vector[i]));
                bucketsNEG[index].sizeBucket++;
            }
    }

    //for positive
    for(int i=0; i<size; ++i)
        if(vector[i] > 0)
        {
            int index = vector[i]*positive/(max+1);
            Insert(&bucketsPOZ[index].head, New(vector[i]));
            bucketsPOZ[index].sizeBucket++;
        }

    //sort the buckets with more than 1 element
    //using counting sort
    if(negative)
    {
        for(int i=0; i<negative; ++i)
        {
            if(!bucketsNEG[i].head)             continue;
            if(bucketsNEG[i].sizeBucket == 1)   continue;

            CountingSort(&bucketsNEG[i].head, bucketsNEG[i].sizeBucket);
        }
    }

    //for positive
    for(int i=0; i<positive; ++i)
    {
        if(!bucketsPOZ[i].head)             continue;
        if(bucketsPOZ[i].sizeBucket == 1)   continue;

        CountingSort(&bucketsPOZ[i].head, bucketsPOZ[i].sizeBucket);
    }

    int index = 0;

    if(negative)
    {
        for(int i=0; i<negative; ++i)
        {
            if(!bucketsNEG[i].head)     continue;

            BUCKET **tracer = &bucketsNEG[i].head;
            while(*tracer)
            {
                vector[index++] = -(*tracer) -> nr;

                tracer = &(*tracer) -> next; 
            }

            Clear(&bucketsNEG[i].head);
        }

        free(bucketsNEG);
    }

    //for positive
    for(int i=0; i<positive; ++i)
    {
        if(!bucketsPOZ[i].head)     continue;

        BUCKET **tracer = &bucketsPOZ[i].head;
        while(*tracer)
        {
            vector[index++] = (*tracer) -> nr;

            tracer = &(*tracer) -> next;
        }

        Clear(&bucketsPOZ[i].head);
    }

    free(bucketsPOZ);

    for(int i=0, j=negative-1; i<negative/2; ++i, --j)
    {
        int aux = vector[i];
        vector[i] = vector[j];
        vector[j] = aux;
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

    // printVector(vector, size);
    BucketSort(vector, size);
    // printVector(vector, size);

    free(vector);
    return 0;
}

// int main(void)
// {
//     int vector[] = {-10, 74, 23, -40, 2, 4, -3, 55, 91, -21, 65, 97, -46, 20};
//     int size = sizeof(vector)/sizeof(vector[0]);

//     printVector(vector, size);
//     BucketSort(vector, size);
//     printVector(vector, size);

//     return 0;
// }