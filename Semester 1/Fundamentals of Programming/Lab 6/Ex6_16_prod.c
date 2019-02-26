/*
Fie două matrici (de nxm si mxn) date de la tastatură. 
Să se calculeze produsul.
Pentru a putea inmulti 2 matrici, Matriciile trebuie sa aibe A[m][n] si B[n][p] randuri si coloane.
Iar matricea rezultata e A*B[m][p]
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

void read_matrix(int M[][MAX], int row, int col, char s[])
{
    printf("Introduceti elementele Matricei %s:\n",s);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%s[%d][%d] = ",s,i+1,j+1), scanf("%d", &M[i][j]);
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

void set_matrix_to_0(int M[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            M[i][j] = 0;
}

void prod(int M1[][MAX], int M2[][MAX], int M3[][MAX], int m, int n, int p)
{
    set_matrix_to_0(M3,m,p);
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < p; ++j)
            for(int x = 0; x < n; ++x)
                M3[i][j] += M1[i][x] * M2[x][j];
}

void main()
{
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX];
    int m, n, p;

    m = read_row("A");              //A[m][n]
    n = read_col("A");              //B[n][p]
    p = read_col("B");              //A*B[m][p]
    read_matrix(M1,m,n,"A");
    read_matrix(M2,n,p,"B");
    
    prod(M1,M2,M3,m,n,p);
    print_matrix(M1,m,n,"A"),printf("\n");
    print_matrix(M2,n,p,"B"),printf("\n");
    print_matrix(M3,m,p,"A*B");
}
