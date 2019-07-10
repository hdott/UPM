#include <stdio.h>


int BinarySearchRecursively(int *vector, int start, int end, int key)
{
    if(end>=start)
    {        
        int mid = start + (end - start) / 2;
        
        if(vector[mid] > key)   return BinarySearchRecursively(vector, start, mid-1, key);
        
        if(vector[mid] < key)   return BinarySearchRecursively(vector, mid+1, end, key);

        return 1;
    }

    return 0;
}

int main(void)
{
    int vector[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(vector) / sizeof(vector[0]);
    
    if(BinarySearchRecursively(vector, 0, size-1, 1))
        printf("Elementul a fost Gasit!\n");
    else
        printf("Elementul NU a fost Gasit!\n");

    return 0;
}