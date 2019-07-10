#include <stdio.h>


int LinearSearch(int *vector, int size, int key)
{
    if(size>=0)
    {
        if(vector[size] != key)     return LinearSearch(vector, size-1, key);

        return 1;
    }

    return 0;
}

int main(void)
{
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(vector) / sizeof(vector[0]);
    
    if(LinearSearch(vector, size-1, 1))
        printf("Elementul a fost Gasit!\n");
    else
        printf("Elementul NU a fost Gasit!\n");

    return 0;
}