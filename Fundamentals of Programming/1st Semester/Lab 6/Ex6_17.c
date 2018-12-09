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
    int i_jos=0, j_jos=0, repetitii=row, conditie=0;
    for( ; j_jos < col; ++j_jos)
        printf("%2d ", M[i_jos][j_jos]);

    int i_stanga,j_stanga,i_sus,j_sus,i_dreapta,j_dreapta;
    i_stanga = row;
    j_stanga = col-1;
    i_sus   = row-1;
    j_sus   = -1;
    i_dreapta = 0;
    j_dreapta = 0;

    for(int aux = 0; aux < row+col-2; ++aux)
    {
        if(aux%2 == 0)
            --repetitii;
        
        if(conditie == 0)
        {
            ++i_jos,--j_jos;
            for(int jos=1, i=i_jos, j=j_jos; jos<=repetitii; ++jos && ++i)
                printf("%2d ", M[i][j]);
            ++conditie;
        }
        else if(conditie == 1)
        {
            --i_stanga,--j_stanga;
            for(int stanga=1, i=i_stanga, j=j_stanga; stanga<=repetitii; ++stanga && --j)
                printf("%2d ", M[i][j]);
            ++conditie;
        }
        else if(conditie == 2)
        {
            --i_sus,++j_sus;
            for(int sus=1, i=i_sus, j=j_sus; sus<=repetitii; ++sus && --i)
                printf("%2d ", M[i][j]);
            ++conditie;
        }
        else if(conditie == 3)
        {
            ++i_dreapta,++j_dreapta;
            for(int dreapta=1, i=i_dreapta, j=j_dreapta; dreapta<=repetitii; ++dreapta && ++j)
                printf("%2d ", M[i][j]);
            conditie = 0;
        }

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
