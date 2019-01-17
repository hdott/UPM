#include <stdio.h>
#include <stdlib.h>
#define max(a,b) a > b ? a : b

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

void compare_Dp_Ds(int **M, int row, int col)
{
    for(int i=0,j=0,x=col-1; i<row; ++i,++j,--x)
        printf("max_of(row[%d]) = %d\n",i,max(M[i][j],M[i][x]));
}

void main()
{
    int size;
    puts("Introduceti un nmar n pentru a forma o matrice nXn");
        printf("n = "),scanf("%d",&size);

    int **M = (int**)malloc(sizeof(int*)*size);
        gen_col(M,size,size);

    read_matrix(M,size,size);
    print_matrix(M,size,size,"A");
    compare_Dp_Ds(M,size,size);

    freeM(M,size);
}
