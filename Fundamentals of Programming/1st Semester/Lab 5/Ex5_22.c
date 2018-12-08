/*
Fie un număr de 4 cifre. 
Să se afișeze toate numerele care pot fi formate din cifrele numărului dat.
*/

#include <stdio.h>
int n1, n2, n3, n4;

int factorial(int x)
{
    int rezultat=1;
    for(int i = 1; i <= x; ++i)
        rezultat *= i;

    return rezultat;
}

void afla_cifrele(int x)
{
    n4  = x % 10;
    x   = x / 10;
    n3  = x % 10;
    x   = x / 10;
    n2  = x % 10;
    x   = x / 10;
    n1  = x % 10;
}

void heap_permutation_4()
{
    printf("%d%d%d%d\n", n1,n2,n3,n4);
    for(int i = 1; i < factorial(4); ++i)
    {
        if(i%2 != 0)                    //conditia_1
        {
            int aux = n1;
            n1 = n2;
            n2 = aux;
        }
        else if(i%2 == 0 && i%6 != 0)   //conditia_2
        {
            int aux = n1;
            n1 = n3;
            n3 = aux;
        }
        else if(i/6 == 1 && i%6 == 0)   //conditia_3
        {
            int aux = n1;
            n1 = n4;
            n4 = aux;
        }
        else if(i/6 == 2 && i%6 == 0)   //conditia_4
        {
            int aux = n2;
            n2 = n4;
            n4 = aux;
        }
        else if(i/6 == 3 && i%6 == 0)   //conditia_5
        {
            int aux = n3;
            n3 = n4;
            n4 = aux;
        }

        printf("%d%d%d%d\n", n1,n2,n3,n4);
    }
}

void main()
{
    int nr;

    printf("Introduceti un numar de 4 cifre:\n");
        printf("nr = "), scanf("%d", &nr);

    printf("\nToate numerele ce pot fi formate din cifrele numarului %d sunt:\n", nr);
        afla_cifrele(nr);
        heap_permutation_4();
}
