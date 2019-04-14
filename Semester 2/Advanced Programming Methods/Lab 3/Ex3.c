/* Fie o matrice de NxM citita dintr-un fisier. Pe prima linie a fisierului sunt m
 *  si n, apoi urmeaza matricea.
 * Sa se ordoneze liniile matricei dupa prima coloana, folosind qsort.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int Compare(const void *a, const void *b)
{
    int **A = (int **)a;
    int **B = (int **)b;

    if(**A > **B)     return 1;
    if(**A < **B)     return -1;
    if(**A == **B)    return 0;
}

int PrintMatrix(int **matrix, int row, int col)
{
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
            printf("%3d", matrix[i][j]);
        puts("");
    }
}

int main(void)
{
    int allocRow = 0;
    int allocCol = 0;
    int maximum = 0;
    int index = -1;

    int row, col;
    FILE *file = fopen("matrix.txt", "r");

    fscanf(file, "%d%d", &row, &col);

    int **matrix = (int**) malloc(row*sizeof(int*));
    for(int i=0; i<row; ++i)
        matrix[i] = (int*) malloc(col*sizeof(int));

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            fscanf(file, "%d", &matrix[i][j]);
    
    int temp;
    while(!feof(file))  fscanf(file, "%d", &temp);

    qsort(matrix, row, sizeof(matrix), Compare);

    printf("Ordered Matrix:\n");
    PrintMatrix(matrix, row, col);

    for(int i=0; i<row; ++i)    free(matrix[i]);
    free(matrix);
    fclose(file);
    return 0;
}