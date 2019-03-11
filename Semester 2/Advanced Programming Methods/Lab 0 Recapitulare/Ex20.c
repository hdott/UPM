// O functie recursiva care implementeaza sortarea prin interclasare

#include <stdio.h>
#include <stdlib.h>

void merge(int *vector, int l, int m, int r)
{
    int i, j, k;
    int size1 = m-l + 1;
    int size2 = r-m;
    
    int *temp1 = (int*) malloc(size1 * sizeof(int));
    int *temp2 = (int*) malloc(size2 * sizeof(int));

    for(i=0; i<size1; ++i)  *(temp1+i) = *(vector+l+i);
    for(i=0; i<size2; ++i)  *(temp2+i) = *(vector+m+1+i);

    i=0, j=0, k=l;

    while(i<size1 && j<size2)
    {
        if(*(temp1+i) <= *(temp2+j))
                *(vector+k++) = *(temp1+i++);
        else    *(vector+k++) = *(temp2+j++);
    }

    while(i<size1)  *(vector+k++) = *(temp1+i++);
    while(j<size2)  *(vector+k++) = *(temp2+j++);

    free(temp1);
    free(temp2);
}

void mergeSort(int *vector, int l, int r)
{
    if(l<r)
    {
        int m = l + (r-l)/2;
        mergeSort(vector,l,m);
        mergeSort(vector,m+1,r);

        merge(vector,l,m,r);
    }
}

void readVector(int *vector, int size)
{
    printf("\nIntroduceti elementele vectorului:\n");
    
    for(int i=0; i<size; ++i)
    {
        printf("[%d] = ", i+1);
        scanf("%d", vector+i);
    }
}

void printVector(int *vector, int size, char *text)
{
    printf("\nVectorul %s este:\n", text);

    for(int i=0; i<size; ++i)
        printf("%d ", *(vector+i));
    puts("");
}

int main(void)
{
    int size;

    printf("Introduceti numarul de elemente ale unui vector: ");
        scanf("%d",&size);

    int *vector = (int*) malloc(size * sizeof(int));

    readVector(vector,size);
    printVector(vector,size,"initial");

    mergeSort(vector,0,size-1);
    printVector(vector,size,"sortat");
    
    free(vector);
    return 0;
}