/*
 * O functie care cauta un numar dat dintr-un vector. (Cautare secventiala)
 */

#include <stdio.h>
#define MAX 30

_Bool find_number_within_vector(int V[MAX],size_t size, int nr);

int main(void)
{
    int V[] = {1,2,3,4,5,6,7,8,9,10};
    int nr;

    printf("Input an integer to check whether it exists in a given vector: ");
        scanf("%d",&nr);

    if(find_number_within_vector(V,sizeof V/ sizeof(int),nr))
        printf("%d exists within the given vector!\n",nr);
    else
        printf("%d does not exist within the given vector!\n",nr);

    return 0;
}

// returns true if the number is found within the given vector
_Bool find_number_within_vector(int V[MAX],size_t size, int nr)
{
    for(int i=0; i<size; ++i)
        if(nr == V[i])
            return 1;

    return 0;
}