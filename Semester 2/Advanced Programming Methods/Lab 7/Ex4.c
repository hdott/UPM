#include <stdio.h>

void InverseOrder(int *vector, int start, int end)
{
    if(end<=start)  return;

    int aux = vector[start];
    vector[start] = vector[end];
    vector[end] = aux;

    InverseOrder(vector, ++start, --end);
}

void PrintVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

int main(void)
{
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(vector) / sizeof(vector[0]);

    PrintVector(vector, size);
    InverseOrder(vector, 0, size-1);
    PrintVector(vector, size);
    
    return 0;
}