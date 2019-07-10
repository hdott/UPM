/*
Să se afişeze diagonala principală şi diagonala secundară a unei matrici pătratice date.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int read_row(char s[])
{
    int row;
    printf("Introduceti numarul de randuri al Matricei %s:\n",s);
        printf("row.%s = ",s), scanf("%d", &row), system("clear");
    
    return row;
}

int read_col(char s[])
{
    int col;
    printf("Introduceti numarul de coloane al Matricei %s:\n",s);
        printf("col.%s = ",s), scanf("%d", &col), system("clear");

    return col;
}

void read_matrix(int M[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("[%d][%d] = ",i+1,j+1), scanf("%d", &M[i][j]);
    system("clear");
}

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

void print_diagonala_principala(int M[][MAX], int row, int col)
{
    printf("Diagonala principala este:\t");
    for(int i=0, j=0; i < row || j < col; ++i && ++j)
        printf("%d ",M[i][j]);
    printf("\n");
}

void print_diagonala_secundara(int M[][MAX], int row, int col)
{
    printf("Diagonala secundara este:\t");
    for(int i=0, j=col-1; i < row || j >= 0; ++i && --j)
        printf("%d ",M[i][j]);
    printf("\n");
}

void main()
{
    int M[MAX][MAX], row, col;

    row = read_row("A");
    col = read_col("A");
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A"), printf("\n");
    print_diagonala_principala(M,row,col);
    print_diagonala_secundara(M,row,col);
}
