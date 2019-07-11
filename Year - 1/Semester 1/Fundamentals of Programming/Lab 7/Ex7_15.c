/*
Se  citesc n şi m, dimensiunile unei matrici de valori reale. 
Se citesc l şi c. 
Să se elimine linia l şi coloana c din matrice, după care să se afişeze matricea rezultată.
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

void elimina_row(int **M, int *row, int col, int row1)
{
    for(int i = 0; i < *row; ++i)
        for(int j = 0; j < col; ++j)
            if((i == row1-1 && i != (*row)-1) || (i > row1-1 && i != (*row)-1))
                M[i][j] = M[i+1][j];

    *row -= 1;
    M = (int**) realloc(M,(*row)*sizeof(int*));

}

void elimina_col(int **M, int row, int *col, int col1)
{
    for(int j = 0; j < *col; ++j)
        for(int i = 0; i < row; ++i)
            if((j == col1-1 && j != (*col)-1) || (j > col1-1 && j != (*col)-1))
                M[i][j] = M[i][j+1];

    *col -= 1;
    for(int i=0; i<row; ++i)
        M[i] = (int*) realloc(M[i],(*col)*sizeof(int));
}

void main()
{
    int row, col;
    read_row_col(&row,&col,"A");
    
    int **M = (int**) malloc(row*sizeof(int*));
    read_matrix(M,row,col);

    int del_row, del_col;
    printf("Introdu randul si coloana dorite a fi eliminate:\n");
        printf("row.A = "), scanf("%d", &del_row);
        printf("col.A = "), scanf("%d", &del_col), system("clear");

    print_matrix(M,row,col,"A Initial"),printf("\n");
    elimina_row(M,&row,col,del_row);
    elimina_col(M,row,&col,del_col);
    print_matrix(M,row,col,"A Modificata");

    freeM(M,row);
}
