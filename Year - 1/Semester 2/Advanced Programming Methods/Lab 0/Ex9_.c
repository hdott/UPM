/*
 * Sa se defineasca cate un subprogram care citeste o matrice; afiseaza o matrice;
 *  returneaza maximul si pozitia acestuia, a.i. valoarea lor sa poata fi schimbata
 *  in subprogram. Matricea sa fie alocata dinamic.
 */

#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **M, int row, int col);   // function prototypes
void print_matrix(int **M, int row, int col);
void gen_col(int **M, int row, int col);
void freeM(int **M, int row);
void maxim_and_poz(int **M, int row, int col, int *maximum, int *poz_row, int *poz_col);


int main(void)
{
    int row, col, maximum, poz_row, poz_col;

    printf("Introduceti marimile unei matrici (linii coloane): ");
        scanf("%d%d",&row,&col);

    // allocates memory in heap for matrix M
    int **M = (int**) malloc(row*sizeof(int*));
        gen_col(M,row,col);
        
    read_matrix(M,row,col);
        printf("\n");
    
    print_matrix(M,row,col);
    
    maximum = M[0][0];
    poz_row = poz_col = 0;
    maxim_and_poz(M,row,col,&maximum,&poz_row,&poz_col);
    printf("\nMaximul Matricei este %d iar pozitia sa [%d][%d].\n",
            maximum,poz_row,poz_col);
    
    freeM(M,row);
    return 0;
}

// reads a matrix
void read_matrix(int **M, int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("[%d][%d] = ",i+1,j+1), scanf("%d", &M[i][j]);
}

// prints a matrix
void print_matrix(int **M, int row, int col)
{
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            printf("%2d ",M[i][j]);
        printf("\n");
    }
}

// generates collumns for a Matrix in heap
void gen_col(int **M, int row, int col)
{
    for(int i=0; i<row; ++i)
        M[i] = (int*) malloc(col*sizeof(int));
}

// frees the heap of the allocated Matrix;
void freeM(int **M, int row)
{
    for(int i = 0; i<row; ++i)
        free(M[i]);
    free(M);
}

// finds the maximum within a bi-dimensional matrix and its position
void maxim_and_poz(int **M, int row, int col, int *maximum, int *poz_row, int *poz_col)
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