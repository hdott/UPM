#include <stdio.h>
#include <stdlib.h>
#include <time.h>


static void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

static int partition(int *vector, int start, int end)
{
    int pivot = vector[end],
        i = start;

    for(int j=start; j<end; ++j)
        if(vector[j] < pivot)
        {
            swap(&vector[i], &vector[j]);
            ++i;
        }
    
    swap(&vector[i], &vector[end]);
    
    return i;
}

static int randomizedPartition(int *vector, int start, int end)
{
    int i = random() % (end-start) + start;
    
    swap(&vector[end], &vector[i]);

    return partition(vector, start, end);
}

void QuickSortRnd(int *vector, int start, int end)
{
    if(start<end)
    {
        int p = randomizedPartition(vector, start, end);
        QuickSortRnd(vector, start, p-1);
        QuickSortRnd(vector, p+1, end);
    }
}


// void printVector(int *vector, int size)
// {
//     for(int i=0; i<size; ++i)
//         printf("%d ", vector[i]);
//     puts("");
// }

// int main(void)
// {
//     time_t t;
//     srand((unsigned) time(&t));

//     int vector[] = {10, 7, 8, 9, 1, 5, 4, 15, 13, 11, 2};
//     int size = sizeof(vector)/sizeof(vector[0]);

//     printVector(vector, size);
//     QuickSortRnd(vector, 0, size-1);
//     printVector(vector, size);

//     return 0;
// }