/*
 * Sa se defineasca cate un subprogram care citeste o matrice; afiseaza o matrice;
 *  returneaza maximul si pozitia acestuia, a.i. valoarea lor sa poata fi schimbata
 *  in subprogram. Matricea sa fie alocata static.
 */

#include <stdio.h>
#define MAX 30

void read_matrix(int M[][MAX], int row, int col);   // function prototypes
void print_matrix(int M[][MAX], int row, int col);
void maxim_and_poz(int M[][MAX], int row, int col, int *maximum, int *poz_row, int *poz_col);

int main(void)
{
    int row, col, M[MAX][MAX], maximum, poz_row, poz_col;
    
    printf("Introduceti marimile unei matrici (linii coloane): ");
        scanf("%d%d",&row,&col);

    read_matrix(M,row,col);
        printf("\n");
    
    print_matrix(M,row,col);
    
    maximum = M[0][0];
    poz_row = poz_col = 0;
    maxim_and_poz(M,row,col,&maximum,&poz_row,&poz_col);

    printf("\nMaximul Matricei este %d iar pozitia sa [%d][%d].\n",
            maximum,poz_row,poz_col);

    return 0;
}

// reads a matrix
void read_matrix(int M[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("[%d][%d] = ",i+1,j+1), scanf("%d", &M[i][j]);
}

// prints a matrix
void print_matrix(int M[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            printf("%2d ",M[i][j]);
        printf("\n");
    }
}

// finds the maximum within a bi-dimensional matrix and its position
void maxim_and_poz(int M[][MAX], int row, int col, int *maximum, int *poz_row, int *poz_col)
{
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            if(M[i][j] > *maximum)
                *maximum = M[i][j];

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            if(M[i][j] == *maximum)
            {
                *poz_row = i+1;
                *poz_col = j+1;
                break;
            }
}