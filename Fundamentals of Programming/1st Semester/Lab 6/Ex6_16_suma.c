/*
Fie două matrici (de nxm) date de la tastatură. 
Să se calculeze suma.
Pentru a putea calcula 2 matrici, ambele trebuie sa aibe acelasi nr de randuri si coloane.
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

void read_matrix(int M[][MAX], int row, int col, char s[])
{
    printf("Introduceti elementele Matricei %s:\n",s);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%s[%d][%d] = ",s,i+1,j+1), scanf("%d", &M[i][j]);
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

void suma(int M1[][MAX], int M2[][MAX], int M3[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            M3[i][j] = M1[i][j] + M2[i][j];
}

void main()
{
    int M1[MAX][MAX], M2[MAX][MAX], M3[MAX][MAX], row, col;

    row = read_row("A&B");
    col = read_col("A&B");
    read_matrix(M1,row,col,"A");
    read_matrix(M2,row,col,"B");

    print_matrix(M1,row,col,"A"),printf("\n");
    print_matrix(M2,row,col,"B"),printf("\n");
    suma(M1,M2,M3,row,col);
    print_matrix(M3,row,col,"A+B");
}
