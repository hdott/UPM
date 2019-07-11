// O functie recursiva care inverseaza un sir de caractere

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

void PrintVector(int *vector, int size, char *text)
{
    printf("\nVectorul %s este:\n", text);

    for(int i=0; i<size; ++i)
        printf("%d ", *(vector+i));
    puts("");
}

void InverseElementsOfVector(int *vector, int l, int r)
{
    if(l<r) 
    {
        int aux = *(vector+l);
        *(vector+l) = *(vector+r);
        *(vector+r) = aux;
        return InverseElementsOfVector(vector,l+1,r-1);
    }
}

int main(void)
{
    int size, nr;

    printf("Introduceti marimea unui vector: ");
        scanf("%d", &size);

    int *vector =  (int*) malloc(size*sizeof(int));

    ReadVector(vector,size);
    PrintVector(vector,size,"introdus");
    InverseElementsOfVector(vector,0,size-1);
    PrintVector(vector,size,"inversat");

    free(vector);
    return 0;
}