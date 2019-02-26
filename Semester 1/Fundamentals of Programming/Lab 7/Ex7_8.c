/*
Să se determine elementul maxim al unei matrici, 
să se afişeze poziţia lui (linia şi coloana).
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

int maxim(int **M, int row, int col, int *pozI, int *pozJ)
{
    int maxim = M[0][0];
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            if(M[i][j]>maxim)
            {
                maxim = M[i][j];
                *pozI = i+1;
                *pozJ = j+1;
            }
            
    return maxim;
}

void main()
{
    int row, col, maxE, i, j;
    read_row_col(&row,&col,"A");
    int **M = (int**) malloc(row*sizeof(int*));
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A"), printf("\n");
    maxE = maxim(M,row,col,&i,&j);
    printf("Cel mai mare element al Matricei A este [%d] si se afla la pozitia: [%d][%d]\n",maxE,i,j);

    freeM(M,row);
}
