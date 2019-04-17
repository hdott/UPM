#include <stdio.h>


int FindMax(int *vector, int size, int max)
{
    if(size<0)              return max;

    if(max<vector[size])    return FindMax(vector, size-1, vector[size]);
    else                    return FindMax(vector, size-1, max);
}

void PrintVector(int *vector, int size)
{
    for(int i=0; i<size; ++i)
        printf("%d ", vector[i]);
    puts("");
}

int main(void)
{
    int vector[] = {55, 2, 3, 44, 5, 6, 7, 8, 9};
    int size = sizeof(vector) / sizeof(vector[0]);

    PrintVector(vector, size);
    FindMax(vector, 0, size-1);
    printf("max -> %d\n", FindMax(vector, size-2, vector[size-1]));
    
    return 0;
}