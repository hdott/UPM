// O functie recursiva care implementeaza cautarea binara

#include <stdio.h>
#include <stdlib.h>

void ReadVector(int *vector, int size)
{
    printf("\nIntroduceti elementele vectorului:\n");
    
    for(int i=0; i<size; ++i)
    {
        printf("[%d] = ", i+1);
        scanf("%d", vector+i);
    }
}

void PrintVector(int *vector, int size)
{
    printf("\nVectorul introdus este:\n");

    for(int i=0; i<size; ++i)
        printf("%d ", *(vector+i));
    puts("");
}

int BinarySearchRecursive(int *vector, int l, int r, int nr)
{
    int mid = (r+l) / 2;
    
    if(l > r)   return 0;

    if(*(vector+mid) == nr) return mid;

    if(nr < *(vector+mid))
        return BinarySearchRecursive(vector,l,mid-1,nr);

    if(nr > *(vector+mid))
        return BinarySearchRecursive(vector,mid+1,r,nr);

    return 0;
}

int main(void)
{
    int size, nr;

    printf("Introduceti marimea unui vector: ");
        scanf("%d", &size);

    int *vector =  (int*) malloc(size*sizeof(int));

    ReadVector(vector,size);

    printf("\nIntroduceti un numar pentru a fi cautat in vector: ");
        scanf("%d", &nr);

    PrintVector(vector,size);

    if(BinarySearchRecursive(vector,0,size-1,nr))
        puts("\nElementul exista in vectorul dat!");
    else
        puts("\nElementul NU exista in vectorul dat!");

    free(vector);
    return 0;
}