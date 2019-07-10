/*
Fie două matrici (de nxm si mxn) date de la tastatură. 
Să se calculeze produsul.
Pentru a putea inmulti 2 matrici, Matriciile trebuie sa aibe A[m][n] si B[n][p] randuri si coloane.
Iar matricea rezultata e A*B[m][p]
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

void prod(int **M1, int **M2, int m, int n, int p)
{
    int **M3 = (int**) calloc(m,sizeof(int*));
    for(int i=0; i<m; ++i)
        M3[i] = (int*) calloc(p,sizeof(int));
        
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < p; ++j)
            for(int x = 0; x < n; ++x)
                M3[i][j] += M1[i][x] * M2[x][j];

    print_matrix(M1,m,n,"A"),printf("\n");
    print_matrix(M2,n,p,"B"),printf("\n");
    print_matrix(M3,m,p,"A*B");

    freeM(M1,m);
    freeM(M2,n);
    freeM(M3,m);
}

void main()
{
    int m, n, p;

    read_row_col(&m,&n,"A");              //A[m][n]
    read_row_col(&n,&p,"B");              //B[n][p]

    int **M1 = (int**) malloc(m*sizeof(int));
    read_matrix(M1,m,n,"A");
    int **M2 = (int**) malloc(n*sizeof(int));
    read_matrix(M2,n,p,"B");
    
    prod(M1,M2,m,n,p);
}
