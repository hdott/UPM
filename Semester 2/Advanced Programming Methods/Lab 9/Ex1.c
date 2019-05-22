// Heap's Algorithm

#include <stdio.h>


void swap(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void printVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

void heap(int *vector, int n, int size)
{
    if(n==1)
    {
        printVector(vector, size);
        return;
    }
    
    for(int i=0; i<n-1; ++i)
    {
        heap(vector, n-1, size);

        if(!(n%2))  swap(&vector[n-1], &vector[i]);
        else        swap(&vector[n-1], &vector[0]);
    }

    heap(vector, n-1, size);
}


int main(void)
{
    int vector[] = {1, 2, 3};
    int size = sizeof(vector)/sizeof(vector[0]);

    heap(vector, size, size);

    return 0;
}

