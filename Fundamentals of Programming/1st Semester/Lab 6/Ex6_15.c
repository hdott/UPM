/*
Se  citesc n şi m, dimensiunile unei matrici de valori reale. 
Se citesc l şi c. 
Să se elimine linia l şi coloana c din matrice, după care să se afişeze matricea rezultată.
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

void set_matrix_to_0(int M[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            M[i][j] = 0;
}

int elimina_row(int M[][MAX], int row, int col, int row1)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            if((i == row1-1 && i != row-1) || (i > row1-1 && i != row-1))
                M[i][j] = M[i+1][j];

    return row-1;
}

int elimina_col(int M[][MAX], int row, int col, int col1)
{
    for(int j = 0; j < col; ++j)
        for(int i = 0; i < row; ++i)
            if((j == col1-1 && j != col-1) || (j > col1-1 && j != col-1))
                M[i][j] = M[i][j+1];

    return col-1;
}

void main()
{
    int M1[MAX][MAX], row, col;

    row = read_row("A");
    col = read_col("A");
    read_matrix(M1,row,col);

    int M2[row][col], del_row, del_col;
    printf("Introdu randul si coloana dorite a fi eliminate:\n");
        printf("row.A = "), scanf("%d", &del_row);
        printf("col.A = "), scanf("%d", &del_col), system("clear");

    print_matrix(M1,row,col,"A Initial"),printf("\n");
    row = elimina_row(M1,row,col,del_row);
    col = elimina_col(M1,row,col,del_col);
    print_matrix(M1,row,col,"A Modificata");
}
