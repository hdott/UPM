#include <stdio.h>

static void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

static int partition(int *vector, int start, int end)
{
    int mid = start + (end-start)/2;

    if(vector[mid] < vector[start]) swap(&vector[mid], &vector[start]);
    if(vector[end] < vector[start]) swap(&vector[end], &vector[start]);
    if(vector[mid] < vector[end])   swap(&vector[mid], &vector[end]);

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

void QuickSortMo3(int *vector, int start, int end)
{
    if(start<end)
    {
        int p = partition(vector, start, end);
        QuickSortMo3(vector, start, p-1);
        QuickSortMo3(vector, p+1, end);
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
//     int vector[] = {10, 7, 8, 9, 1, 5};
//     int size = sizeof(vector)/sizeof(vector[0]);

//     printVector(vector, size);
//     QuickSort(vector, 0, size-1);
//     printVector(vector, size);

//     return 0;
// }