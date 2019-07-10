/*
Să se afişeze triunghiul superior şi triunghiul inferior.
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

void print_triunghi_superior(int **M, int row, int col)
{
    printf("Triunghiul Superior este:\n");
    for(int i=0, limit=col-1; i!=limit && i!=limit-1; ++i && --limit)
    {
        for(int j = i+1; j > i && j < limit; ++j)   //limit reprezinta diagonala secundara
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void print_triunghi_inferior(int **M, int row, int col)
{
    int aux;                    //limit1 reprezinta diagonala secundara
    if(col%2 != 0)              //limit2 reprezinta diagonala principala
        aux = col/2;            //aux reprezinta valoarea pe care o ia j cand loop-ul este initiat
    else
        aux = col/2-1;

    printf("Triunghiul Inferior este:\n");
    for(int i=row/2+1, limit2=col/2+1; i < row || limit2 < col; ++i && ++limit2 && --aux)
    {
        //printf("j=%d\ti=%d\tlimit=%d\n",j,i,limit);
        for(int j=aux, limit1=j-1; j > limit1 && j < limit2; ++j && --limit1)
            printf("%d ", M[i][j]);
        printf("\n");
    }
}

void main()
{
    int row, col;

    read_row_col(&row,&col,"A");
    int **M = (int**) malloc(row*sizeof(int*));
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A"), printf("\n");
    print_triunghi_superior(M,row,col);
    print_triunghi_inferior(M,row,col);

    freeM(M,row);
}
