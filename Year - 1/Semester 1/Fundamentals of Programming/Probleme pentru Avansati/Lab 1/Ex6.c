/*
 * O functie care calculeaza suma, diferenta si produsul a doua matrici 
 *  patratice de dimensiune n.
 */

#include <stdio.h>
#include <stdlib.h>

void read_matrix(int **M, int row, int col);
void print_matrix(int **M, int row, int col);
void gen_col(int **M, int row, int col);
void freeM(int **M, int row);
void add_matrix(int **M1, int **M2, int row, int col);
void substract_matrix(int **M1, int **M2, int row, int col);
void product_matrix(int **M1, int **M2, int row, int col);

int main(void)
{
    int row, col;

    printf("Introduceti marimea unei matrice patratice: ");
        scanf("%d",&row);
        col = row;

    int **M1 = (int**) malloc(row*sizeof(int));
        gen_col(M1,row,col);
    int **M2 = (int**) malloc(row*sizeof(int));
        gen_col(M2,row,col);

    printf("Introduceti elementele primei matrici:\n");
        read_matrix(M1,row,col);
    printf("Introduceti elementele celei de a doua matrici:\n");
        read_matrix(M2,row,col);

    add_matrix(M1,M2,row,col);
    substract_matrix(M1,M2,row,col);
    product_matrix(M1,M2,row,col);

    freeM(M1,row);
    freeM(M2,row);

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

// the following functions take as parameter 2 nxn Matrix
// adds 2 matrices
void add_matrix(int **M1, int **M2, int row, int col)
{
    int **M3 = (int**) malloc(row*sizeof(int*));
        gen_col(M3,row,col);

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            M3[i][j] = M1[i][j] + M2[i][j];

    printf("\nMatricea C = A+B este:\n");
        print_matrix(M3,row,col);

    freeM(M3,row);
}

// substracts a matrix from another
void substract_matrix(int **M1, int **M2, int row, int col)
{
    int **M3 = (int**) malloc(row*sizeof(int*));
        gen_col(M3,row,col);

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            M3[i][j] = M1[i][j] - M2[i][j];

    printf("\nMatricea C = A-B este:\n");
        print_matrix(M3,row,col);

    freeM(M3,row);
}

// multiplies two matrices
void product_matrix(int **M1, int **M2, int row, int col)
{
    int **M3 = (int**) calloc(row,sizeof(int*));
        for(int i=0; i<row; ++i)
            M3[i] = (int*) calloc(row,sizeof(int));

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            for(int x=0; x<row; ++x)
                M3[i][j] += M1[i][x]*M2[x][j];

    printf("\nMatricea C = A*B este:\n");
        print_matrix(M3,row,col);

    freeM(M3,row);
}

