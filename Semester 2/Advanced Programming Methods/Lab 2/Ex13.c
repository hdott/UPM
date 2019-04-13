// Sa se caute cea mai mica pereche de numere prietene intr-un interval (citit).


#include <stdio.h>
#include <stdlib.h>

typedef struct pereche
{
    int nr1, nr2;
} FRIENDS;

FRIENDS *CeaMaiMicaPereche(int min, int max)
{
    FRIENDS *newp = (FRIENDS*) malloc(sizeof(FRIENDS));

    int sum1, sum2; 

    for(int i=min; i<=max; ++i)
    {
        sum1 = sum2 = 0;

        for(int j=1; j<=i/2; ++j)   if(!(i%j))  sum1+=j;

        for(int j=1; j<=sum1/2; ++j)    if(!(sum1%j))   sum2+=j;

        if(i == sum2)    goto Iesire;
    }

    Iesire: 
    newp -> nr1 = sum2;
    newp -> nr2 = sum1;

    return newp;
}

int main(void)
{
    int min, max;

    printf("Introduceti intervalul:\n");
    printf("[min,max]: ");
    scanf("%d%d", &min, &max);

    FRIENDS *pStruct = CeaMaiMicaPereche(min, max);

    printf("Perechea este -> (%d , %d)\n", pStruct -> nr1, pStruct -> nr2);

    free(pStruct);
    return 0;
}