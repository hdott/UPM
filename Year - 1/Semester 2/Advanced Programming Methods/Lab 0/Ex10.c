/*
 * Se citesc 2 matrice de numere intregi. Sa se afiseze matricea suma; diferenta
 *  si produs; folosind cate un subprogram pentru efectuarea calculelor, a citirilor
 *  si a afisarilor.
 */

#include <stdio.h>
#define MAX 30

void read_matrix(int M[][MAX], int row, int col);   // function prototypes
void print_matrix(int M[][MAX], int row, int col);
void add_matrix(int M1[][MAX], int M2[][MAX], int row, int col);
void substract_matrix(int M1[][MAX], int M2[][MAX], int row, int col);
void set_M_to_0(int M[][MAX], int row, int col);
void product_matrix(int M1[][MAX], int M2[][MAX], int row, int col);

int main(void)
{
    int M1[MAX][MAX], M2[MAX][MAX], row, col;

    printf("Introduceti marimile unei matrici (linii coloane): ");
        scanf("%d%d",&row,&col);

    printf("\nIntroduceti elementele primei matrici:\n");
        read_matrix(M1,row,col);
    printf("\nIntroduceti elementele celei de a doua matrici:\n");
        read_matrix(M2,row,col);

    printf("\nMatricea A este:\n");
        print_matrix(M1,row,col);
    printf("\nMatricea B este:\n");
        print_matrix(M2,row,col);

    add_matrix(M1,M2,row,col);
    substract_matrix(M1,M2,row,col);
    product_matrix(M1,M2,row,col);
    
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

// the following functions take as parameter 2 nxn Matrix
// adds 2 matrices
void add_matrix(int M1[][MAX], int M2[][MAX], int row, int col)
{
    int M3[MAX][MAX];

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            M3[i][j] = M1[i][j] + M2[i][j];

    printf("\nMatricea C = A+B este:\n");
        print_matrix(M3,row,col);
}

// substracts a matrix from another
void substract_matrix(int M1[][MAX], int M2[][MAX], int row, int col)
{
    int M3[MAX][MAX];

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            M3[i][j] = M1[i][j] - M2[i][j];

    printf("\nMatricea C = A-B este:\n");
        print_matrix(M3,row,col);
}

// set all elements of a Matrix to 0
void set_M_to_0(int M[][MAX], int row, int col)
{
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            M[i][j] = 0;
}

// multiplies two matrices
void product_matrix(int M1[][MAX], int M2[][MAX], int row, int col)
{
    int M3[MAX][MAX];
    set_M_to_0(M3,row,col);

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            for(int x=0; x<row; ++x)
                M3[i][j] += M1[i][x]*M2[x][j];

    printf("\nMatricea C = A*B este:\n");
        print_matrix(M3,row,col);
}