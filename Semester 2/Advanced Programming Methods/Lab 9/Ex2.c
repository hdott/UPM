#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 50


int tabla[MAX];
int dame, k;


void tipar()
{
    for(int i=1; i<=dame; ++i)
    {
        for(int j=1; j<=dame; ++j)
            if(tabla[i] == j)   printf("D ");
            else                printf("* ");
        puts("");
    }

    puts("");
}

int valid(int k)
{
    for(int i=1; i<k; ++i)
        if(tabla[k]==tabla[i] || abs(tabla[k]-tabla[i])==abs(k-1))
            return 0;

    return 1;
}

void back(int k)
{
    if(k==dame+1)
        tipar();
    else
        for(int i=1; i<=dame; ++i)
        {
            tabla[k] = i;

            if(valid(k))    back(k+1);
        }
}

int main(void)
{
    printf("Introduceti numarul de dame: ");
    scanf("%d", &dame);

    back(1);

    return 0;
}