// O functie care calculeaza suma, diferenta si produsul a doua polinoame.

#include <stdio.h>
#include <stdlib.h>

void read_polinom_coeficients(int *P, int size, char *name);
void print_polinom(int *P, int size, char *name);
void reverse_vector(int *P, int size);
void add_two_polinoms(int *P1, int *P2, int size1, int size2, char *name);
void multiply_two_polinoms(int *P1, int *P2, int size1, int size2, char *name);

int main(void)
{
    int size1, size2;

    printf("Introduceti numarul de elemente al primului polinom: ");
        scanf("%d",&size1);

    int *P1 = (int*) malloc(size1*sizeof(int));
        read_polinom_coeficients(P1,size1,"Polinomului[1]");

    printf("\nIntroduceti numarul de elementele al celui de al doilea polinom: ");
        scanf("%d",&size2);
    
    int *P2 = (int*) malloc(size2*sizeof(int));
        read_polinom_coeficients(P2,size2,"Polinomului[2]");

    print_polinom(P1,size1,"Polinomul[1]");
    print_polinom(P2,size2,"Polinomul[2]");

    if(size1>size2)
        add_two_polinoms(P1,P2,size1,size2,"P3 = P1 + P2");
    else
        add_two_polinoms(P2,P1,size2,size1,"P3 = P1 + P2");

    multiply_two_polinoms(P1,P2,size1,size2,"P3 = P1 * P2");    

    free(P1);
    free(P2);

    return 0;
}

// reads a polynomial's coeficients from stdin
void read_polinom_coeficients(int *P, int size, char *name)
{
    printf("\nIntroduceti coeficientii %s\n",name);

    for(int i=size-1; i>=0; --i)
    {
        printf("X^%d * ",i);
            scanf("%d",&P[i]);
    }
}

// prints a polynomial to stdout
void print_polinom(int *P, int size, char *name)
{
    printf("\n%s este:\n",name);

    for(int i=size-1; i>=0; --i)
        printf("%+d*X^%d ",P[i],i);
    printf("= 0\n");
}

// reverse elements of a vector
void reverse_vector(int *P, int size)
{
    for(int i = 0, j=size-1; i < size/2; ++i, --j)
    {
        int aux = P[i];
        P[i] = P[j];
        P[j] = aux;
    }
}

// adds two polynomials, this assumes size1 > size2
void add_two_polinoms(int *P1, int *P2, int size1, int size2, char *name)
{
    int *P3 = (int*) malloc(size1*sizeof(int));
    
    for(int i=0; i<size2; ++i)
        P3[i] = P2[i] + P1[i];
    for(int i=size2; i<size1; ++i)
        P3[i] = P1[i];

    reverse_vector(P3,size1);
    print_polinom(P3,size1,name);

    free(P3);
}

// multiplies two polynomials
void multiply_two_polinoms(int *P1, int *P2, int size1, int size2, char *name)
{
    int *P3 = (int*) calloc((size1+size2-1),sizeof(int));

    for(int i=0; i<size1; ++i)
        for(int j=0; j<size2; ++j)
            P3[i+j] += P1[i] * P2[j];

    // reverse_vector(P3,size1+size2-1);
    print_polinom(P3,size1+size2-1,name);
            
    free(P3);
}