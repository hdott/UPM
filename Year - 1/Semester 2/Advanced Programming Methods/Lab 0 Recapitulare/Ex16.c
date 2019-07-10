// O functie recursiva care calculeaza maximul/minimul dintr-un vector

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

int MaximRecursive(int *vector, int size, int maxim)
{
    if(size >= 0 && maxim < *(vector+size))
        return MaximRecursive(vector,size-1,maxim=*(vector+size));
    else if(size >= 0)
        return MaximRecursive(vector,size-1,maxim);
    else return maxim;
}

int MinimRecursive(int *vector, int size, int minim)
{
    if(size >= 0 && minim > *(vector+size))
        return MinimRecursive(vector,size-1,minim=*(vector+size));
    else if(size >= 0)
        return MinimRecursive(vector,size-1,minim);
    else return minim;
}

int main(void)
{
    int size;

    printf("Introduceti marimea unui vector: ");
        scanf("%d", &size);
    
    int *vector =  (int*) malloc(size*sizeof(int));

    ReadVector(vector,size);
    PrintVector(vector,size);

    printf("\nMaximul Vectorului este: %d\n",
            MaximRecursive(vector,size-2,*(vector+size-1)));
    printf("Minimul Vectorului este: %d\n",
            MinimRecursive(vector,size-2,*(vector+size-1)));

    free(vector);
    return 0;
}