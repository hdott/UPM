#include <stdio.h>

void InsertionSortRecursive(int *vector, int size)
{
    if(size<1)     return;

    InsertionSortRecursive(vector, size-1);

    int j, temp = vector[size];

    for(j=size-1; j>=0 && vector[j] > temp; --j)
        vector[j+1] = vector[j];

    vector[j+1] = temp;
}

void printVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

int main(void)
{
    int vector[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(vector)/sizeof(vector[0]);

    printVector(vector, size);
    InsertionSortRecursive(vector, size-1);
    // insertionSortRec(vector, size-1);
    printVector(vector, size);

    return 0;
}