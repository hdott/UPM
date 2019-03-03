/*
 * Sa se defineasca cate un subprogram care returneaza diagonalele (separat care
 *  principala si separat cea secundara) unei matrice patratice date ca parametru.
 * Afisarea diagonalelor se face in programul principal. Operatiile citire si
 *  ale matricei sa fie realizate tot prin subprograme.
 */

#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **M, int row, int col);   // function prototypes
void print_matrix(int **M, int row, int col);
void gen_col(int **M, int row, int col);
void freeM(int **M, int row);
int* main_diagonal(int **M, int row, int col);
int* secondary_diagonal(int **M, int row, int col);

int main(void)
{
    int row, col;

    printf("Introduceti marimimea unei matrici patratice: ");
        scanf("%d",&row);
        col = row;
        
    int **M = (int**) malloc(row*sizeof(int*));
        gen_col(M,row,col);

    printf("Introduceti elementele matricei:\n");
        read_matrix(M,row,col);

    printf("\nMatricea introdusa este:\n");
        print_matrix(M,row,col);

    int *m_diagonal = main_diagonal(M,row,col);
    int *s_diagonal = secondary_diagonal(M,row,col);

    printf("\nDiagonala principala este:\n");
        for(int i=0; i<row; ++i)
            printf("%d ", *(m_diagonal+i));
        printf("\n\n");

    printf("Diagonala secundara este:\n");
        for(int i=0; i<row; ++i)
            printf("%d ", *(s_diagonal+i));
        printf("\n");

    freeM(M,row);
    free(m_diagonal);
    free(s_diagonal);

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

// returns main diagonal
int* main_diagonal(int **M, int row, int col)
{
    int *m_diagonal = (int*) malloc(row*sizeof(int));

    for(int i=0, j=0; i<row || j<col; ++i, ++j)
        m_diagonal[i] = M[i][j];

    return m_diagonal;
}

// returns secondary diagonal
int* secondary_diagonal(int **M, int row, int col)
{
    int *s_diagonal = (int*) malloc(row*sizeof(int));

    for(int i=0, j=col-1; i<row || j>=0; ++i, --j)
        s_diagonal[i] = M[i][j];

    return s_diagonal;
}