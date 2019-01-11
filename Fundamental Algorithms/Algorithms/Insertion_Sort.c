// Insertion Sort

#include <stdio.h>

void insertion_sort(int vector[], int x)
{
    for(int i=1,j=0; i<x; ++i)
    {
        int key=vector[i];

        for(j=i-1;j>=0 && vector[j]>key;--j)
            vector[j+1]=vector[j];
            
        vector[j+1]=key;
    }
}
