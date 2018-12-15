/*
Se citeşte o matrice nxm de la tastatură. 
Să se interschimbe prima linie cu ultima, prima coloana cu ultima.
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

void change_row(int **M, int col, int row1, int row2)
{
    for(int j = 0; j < col; ++j)
    {
        int aux     = M[row1][j];
        M[row1][j]  = M[row2][j];
        M[row2][j]  = aux;
    }
}

void change_col(int **M, int row, int col1, int col2)
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
    int row, col;
    read_row_col(&row,&col,"A");
    
    int **M = (int**) malloc(row*sizeof(int*));
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A Initiala"), printf("\n");
    change_row(M,col,0,row-1);
    change_col(M,row,0,col-1);
    print_matrix(M,row,col,"A Modificata");

    freeM(M,row);
}
