/*
Să se afişeze diagonala principală şi diagonala secundară a unei matrici pătratice date.
*/

#include <stdio.h>
#include <stdlib.h>

void read_row_col(int *row, int *col, char s[])
{
    printf("Introduceti numarul de randuri al Matricei %s:\n",s);
        printf("row.%s = ",s), scanf("%d", row), system("clear");
    printf("Introduceti numarul de coloane al Matricei %s:\n",s);
        printf("col.%s = ",s), scanf("%d", col), system("clear");
}

void gen_col(int **M, int row, int col)
{
    for(int i=0; i<row; ++i)
        M[i] = (int*) malloc(col*sizeof(int));
}

void freeM(int **M, int row)
{
    for(int i = 0; i<row; ++i)
        free(M[i]);
    free(M);
}

void read_matrix(int **M, int row, int col)
{
    gen_col(M,row,col);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("[%d][%d] = ",i+1,j+1), scanf("%d", &M[i][j]);
    system("clear");
}

void print_matrix(int **M, int row, int col, char s[])
{
    printf("Matricea %s este:\n",s);
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
            printf("%2d ",M[i][j]);
        printf("\n");
    }
}

void print_diagonala_principala(int **M, int row, int col)
{
    printf("Diagonala principala este:\t");
    for(int i=0, j=0; i < row || j < col; ++i && ++j)
        printf("%d ",M[i][j]);
    printf("\n");
}

void print_diagonala_secundara(int **M, int row, int col)
{
    printf("Diagonala secundara este:\t");
    for(int i=0, j=col-1; i < row || j >= 0; ++i && --j)
        printf("%d ",M[i][j]);
    printf("\n");
}

void main()
{
    int row, col;
    read_row_col(&row,&col,"A");
    
    int **M = (int**) malloc(row*sizeof(int*));
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A"), printf("\n");
    print_diagonala_principala(M,row,col);
    print_diagonala_secundara(M,row,col);

    freeM(M,row);
}
