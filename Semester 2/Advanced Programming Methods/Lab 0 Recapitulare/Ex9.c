// O functie care afiseaza matricea in zig zag

#include <stdio.h>
#include <stdlib.h>

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
    system("clear");    // linux command
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

void print_zig_zag(int **M, int row, int col)
{
    printf("Afiseaza Matricea in Zig Zag:\n");
    for(int repetitii = 0; repetitii < row+col-1; ++repetitii)
    {
        if(repetitii%2 == 1)
        {
            int i = repetitii < col ? 0 : repetitii-col+1;
            int j = repetitii < col ? repetitii : col-1;
            while(i < row && j >= 0)
                printf("%2d ", M[i++][j--]);
        }
        else
        {
            int i = repetitii < row ? repetitii : row-1;
            int j = repetitii < row ? 0 : repetitii-row+1;
            while(i >= 0 && j < col)
                printf("%2d ", M[i--][j++]);
        }
    }
    printf("\n");
}

int main(void)
{
    int row, col;
    printf("Introduceti marimea unei matrici mXn (randuri coloane): ");
        scanf("%d%d",&row,&col);
    
    int **M = (int**) malloc(row*sizeof(int*));
        gen_col(M,row,col);

    read_matrix(M,row,col);

    print_matrix(M,row,col,"A");
    print_zig_zag(M,row,col);
    
    freeM(M,row);

    return 0;
}