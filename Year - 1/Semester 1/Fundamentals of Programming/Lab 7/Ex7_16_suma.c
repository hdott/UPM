/*
Fie două matrici (de nxm) date de la tastatură. 
Să se calculeze suma.
Pentru a putea aduna 2 matrici, ambele trebuie sa aibe acelasi nr de randuri si coloane.
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

void read_matrix(int **M, int row, int col, char s[])
{
    gen_col(M,row,col);
    printf("Introduceti elementele Matricei %s:\n",s);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%s[%d][%d] = ",s,i+1,j+1), scanf("%d", &M[i][j]);
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

void suma(int **M1, int **M2, int row, int col)
{
    int **M3 = (int**) malloc(row*sizeof(int*));
        gen_col(M3,row,col);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            M3[i][j] = M1[i][j] + M2[i][j];

    print_matrix(M1,row,col,"A"),printf("\n");
    print_matrix(M2,row,col,"B"),printf("\n");
    print_matrix(M3,row,col,"A+B");

    freeM(M1,row);
    freeM(M2,row);
    freeM(M3,row);
}

void main()
{
    int row, col;

    read_row_col(&row,&col,"A&B");

    int **M1 = (int**) malloc(row*sizeof(int));
    read_matrix(M1,row,col,"A");
    int **M2 = (int**) malloc(row*sizeof(int));
    read_matrix(M2,row,col,"B");

    suma(M1,M2,row,col);
}
