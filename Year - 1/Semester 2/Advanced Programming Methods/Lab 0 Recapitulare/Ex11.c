/*
 * O functie care citeste de la tastatura numere intregi pana la prima aparitie a lui 0
 *  a. O functie care afiseaza datele citite
 *  b. O functie care modifica elementul de pe pozitia i cu o valoarea data
 *  c. O functie care insereaza o valoare pe o pozitie data
 *  d. O functie care sterge valoarea de pe pozitia data
 */

#include <stdio.h>
#include <stdlib.h>

// reads until 0 is entered
// vector is continuously resized for each element -> not ideal
// function returns the size of the vector and the address of the vector
// via the double ref pointer
int readUntil_0(int **pV)
{
    int count=0, input;
    int *aux = NULL;
    int *V = NULL;

    while(1)
    {    
        printf("Introduceti un intreg (0 to exit): ");
            scanf("%d",&input);
        if(!input)  break;

        aux = (int*) realloc(V,(count+1)*sizeof(int));
        
        if(aux != NULL) 
        {
            V = aux;
            V[count++] = input;
        }
        else
        {
            free(V);
            printf("ERROR\n");
            exit(1);
        }
    }

    *pV = V;
    return count;
}

// prints the elements of the vector
void printElements(int *V, int size)
{
    printf("\nElementele sunt:\n");
        for(int i=0; i<size; ++i)
            printf("%d ",V[i]);
        printf("\n");
}

void modifyElement(int *V)
{
    int poz, value;
    
    printf("\nIntroduceti pozitia elementului de inlocuit si valoarea dorita");
    printf(" (pozitia valoarea): ");
    scanf("%d%d",&poz,&value);

    *(V+poz-1) = value;
}

// inserts an element in a given position
void insertElement(int **pV, int size)
{
    int poz, value;

    printf("\nIntroduceti pozitia pe care doriti a introduce elementul si ");
    printf("valoarea dorita (pozitia valoarea):\n");
    scanf("%d%d",&poz,&value);

    int *V = *pV;
    int *aux = NULL;
    aux = (int*) realloc(V,size*sizeof(int));

    if(aux!=NULL)
    {
        V = aux;
        for(int i=size-1; i>0; --i)
            if(i == poz-1)
            {
                *(V+i) = value;
                break;
            }
            else    *(V+i) = *(V+i-1);
        
    }
    else
    {
        free(V);
        printf("ERROR\n");
        exit(1);
    }

    *pV = V;
}

// deletes an element from a given position
void deleteElement(int **pV, int size)
{
    int poz;

    printf("\nIntroduceti pozitia elementului dorit sters: ");
    scanf("%d",&poz);   

    int *V = *pV;
    int *aux = NULL;

    for(int i=0; i<size; ++i)
        if(i<poz-1) continue;
        else    *(V+i) = *(V+i+1);

    aux = (int*) realloc(V,size*sizeof(int));

    if(aux != NULL) V = aux;
    else
    {
        free(V);
        printf("ERROR\n");
        exit(1);
    }

    *pV = V;
}

int main(void)
{
    int *pV = NULL;
    int size = readUntil_0(&pV);
    printElements(pV,size);

    modifyElement(pV);
    printElements(pV,size);

    insertElement(&pV,++size);
    printElements(pV,size);

    deleteElement(&pV,--size);
    printElements(pV,size);

    free(pV);
    return 0;
}