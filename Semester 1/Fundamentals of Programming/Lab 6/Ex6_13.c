/*
Se citeşte o matrice nxm de la tastatură. 
Să se interschimbe prima linie cu ultima, prima coloana cu ultima.
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

void change_row(int M[][MAX], int col, int row1, int row2)
{
    for(int j = 0; j < col; ++j)
    {
        int aux     = M[row1][j];
        M[row1][j]  = M[row2][j];
        M[row2][j]  = aux;
    }
}

void change_col(int M[][MAX], int row, int col1, int col2)
{
    for(int i = 0; i < row; ++i)
    {
        int aux     = M[i][col1];
        M[i][col1]  = M[i][col2];
        M[i][col2]  = aux;
    }
}

void main()
{
    int M[MAX][MAX], row, col;

    row = read_row("A");
    col = read_col("A");
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A Initiala"), printf("\n");
    change_row(M,col,0,row-1);
    change_col(M,row,0,col-1);
    print_matrix(M,row,col,"A Modificata");
}
