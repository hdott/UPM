// Toate submultimile unei multimi date

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void readSet(int *V, int size)
{
    printf("Introduceti elementele Multimii:\n");

    for(int i=0; i<size; ++i)
    {
        printf("[%d] = ",i+1);
        scanf("%d",&V[i]);
    }
}

void printSubSet(int *V, int size)
{
    int size_outter = 1 << size;

    for(int i=0; i<size_outter; ++i)
    {
        for(int j=0; j<size; ++j)
            if(i & (1<<j))
                printf("%d ", V[j]);
        printf("\n");
    }
}

int main(void)
{
    int size;
    printf("Introduceti numarul de elemente al unei Multimi: ");
        printf("size = "), scanf("%d",&size);

    int *V = (int*) malloc(size*sizeof(int));
        readSet(V,size);

    printSubSet(V,size);

    free(V);
    return 0;
}