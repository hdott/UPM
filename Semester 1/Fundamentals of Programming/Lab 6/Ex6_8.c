/*
Să se determine elementul maxim al unei matrici, 
să se afişeze poziţia lui (linia şi coloana).
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 30
#define max(a,b) a > b ? a : b

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

void read_matrix(int M[][MAX], int row, int col)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("[%d][%d] = ",i+1,j+1), scanf("%d", &M[i][j]);
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

int maxim(int M[][MAX], int row, int col)
{
    int maxim = M[0][0];
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            maxim = max(maxim,M[i][j]);

    return maxim;
}

void print_poz(int M[][MAX], int row, int col, int elem)
{
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            if(elem == M[i][j])
                printf("[%d][%d]\n",i+1,j+1);
}

void main()
{
    int M[MAX][MAX], row, col, maxE;

    row = read_row("A");
    col = read_col("A");
    read_matrix(M,row,col);

    print_matrix(M,row,col,"A"), printf("\n");
    maxE = maxim(M,row,col);
    printf("Cel mai mare element al Matricei A este [%d] si se afla la pozitia: ",maxE);
    print_poz(M,row,col,maxE);
}
