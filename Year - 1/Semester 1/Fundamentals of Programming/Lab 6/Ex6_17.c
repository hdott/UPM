/*
Sa se afişeze matricea pătratică de nxn
(elementele matricei să fie generate aleatoriu din intervalul [0,50]: 
- Afişează de la diagonala principală în jos. 
- Afişează de la diagonala secundară în dreapta. 
- Afişează în Zig~Zag. 
- Afişează în spirală.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 30
#define MAX_row_col 7

void print_matrix(int M[][MAX], int row, int col, char s[])
{
    printf("Matricea %s este:\n",s);
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            printf("%2d ",M[i][j]);
        printf("\n");
    }
}

unsigned int randomgen(int gen)
{
    unsigned int r; 
    srand((unsigned)time(NULL));

    for(int a = 0; a < 100; ++a) 
        for(int b = 0; b < 10; ++b) 
            r = rand() % gen + 3;

    return r;
}

void genereaza_matrix(int M[][MAX], int row, int col)
{
    srand((unsigned)time(NULL));

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            for(int a = 0; a < 100; ++a) 
                for(int b = 0; b < 10; ++b) 
                    M[i][j] = rand() % 50 + 1; 
}

void print_from_diagonala_principala(int M[][MAX], int row, int col)
{
    printf("Afiseaza Matricea de la diagonala principala in jos:\n");
    for(int j = 0, limit = 0; j < col; ++j && ++limit)
        for(int i = limit; i < row; ++i)
            printf("%2d ", M[i][j]);
    printf("\n");
}

void print_from_diagonala_secundara(int M[][MAX], int row, int col)
{
    printf("Afiseaza Matricea de la diagonala secundara in stanga:\n");
    for(int i = 0, limit = col-1; i < row; ++i && --limit)
        for(int j = limit; j >= 0; --j)
            printf("%2d ", M[i][j]);
    printf("\n");
}

void print_zig_zag(int M[][MAX], int row, int col)
{
    printf("Afiseaza Matricea in Zig Zag:\n");
    for(int repetitii = 0; repetitii < row+col-1; ++repetitii)
    {
        if(repetitii%2 == 1)
        {
            int i = repetitii < col ? 0 : repetitii-col+1;
            int j = repetitii < col ? repetitii : col-1;
            while(i < row && j >= 0)
                printf("%2d ", M[i++][j--]);
        }
        else
        {
            int i = repetitii < row ? repetitii : row-1;
            int j = repetitii < row ? 0 : repetitii-row+1;
            while(i >= 0 && j < col)
                printf("%2d ", M[i--][j++]);
        }
    }
    printf("\n");
}

void print_spirala(int M[][MAX], int row, int col)
{
    printf("Afiseaza Matricea in Spirala:\n");
    int i=0, j=0, repetitii=row;
    for(j = 0 ; j < col; ++j)
        printf("%2d ", M[i][j]);

    for(int conditie = 1, directie = 1; conditie < row+col-1; ++conditie)
    {
        if(conditie%4 == 1)             //jos
            for(directie=1, ++i, --j, --repetitii; directie <= repetitii; ++directie)
                printf("%2d ", M[i++][j]);
        else if(conditie%4 == 2)        //stanga
            for(directie=1, --i, --j             ; directie <= repetitii; ++directie)
                printf("%2d ", M[i][j--]);
        else if(conditie%4 == 3)        //sus
            for(directie=1, --i, ++j, --repetitii; directie <= repetitii; ++ directie)
                printf("%2d ", M[i--][j]);
        else                            //dreapta
            for(directie=1, ++i, ++j             ; directie <= repetitii; ++directie)
                printf("%2d ", M[i][j++]);
    }
    printf("\n");
}

void main()
{
    int M[MAX][MAX];
    unsigned row, col;

    row = col = randomgen(MAX_row_col);
    genereaza_matrix(M,row,col);

    print_matrix(M,row,col,"A"),printf("\n");
    print_from_diagonala_principala(M,row,col);
    print_from_diagonala_secundara(M,row,col);
    print_zig_zag(M,row,col);
    print_spirala(M,row,col);
}
