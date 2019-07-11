/*
Se citeşte o matrice nxm. 
Sa se afişeze minimul pe coloane şi maximul pe linii.
*/

#include <stdio.h>
#include <stdlib.h>
#define min(a,b) a < b ? a : b
#define max(a,b) a > b ? a : b

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

void print_minim_col(int **M, int row, int col)
{
    printf("Minimul pe coloane este:\n");
    for(int j = 0; j < col; ++j)
    {
        int minim = M[0][j];
        for(int i = 1; i < row; ++i)
            minim = min(minim,M[i][j]);
        printf("[i][%d] = %d\t",j+1,minim);
    }
    printf("\n");
}

void print_maxim_row(int **M, int row, int col)
{
    printf("Maximul pe randuri este:\n");
    for(int i = 0; i < row; ++i)
    {
        int maxim = M[i][0];
        for(int j = 1; j < col; ++j)
            maxim = max(maxim,M[i][j]);
        printf("[%d][j] = %d\n",i+1,maxim);
    }
    printf("\n");
}

void main()
{
    int row, col;
    read_row_col(&row,&col,"A");
    
    int **M = (int**) malloc(row*sizeof(int*));
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A"),printf("\n");
    print_minim_col(M,row,col),printf("\n");
    print_maxim_row(M,row,col);

    freeM(M,row);
}
