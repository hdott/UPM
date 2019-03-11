/*
 * O functie care citeste de la tastatura o matrice de dimensiune mXn
 *  a. O functie care afiseaza datele citite
 *  b. O functie care afiseaza maximul si minimul elementelor matricii
 *  c. O functie care afiseaza maximul elementelor randului i
 *  d. O functie care afiseaza minimul elementelor coloanei j
 *  e. O functie care afiseaza maximul fiecarui rand si minimul fiecarei coloane
 */

#include <stdio.h>
#include <stdlib.h>

// generates dynamic collumns for a matrix
void genCollumns(int **Matrix, int row, int col)
{
    for(int i=0; i<row; ++i)
        *(Matrix+i) = (int*) malloc(col * sizeof(int));
}

// frees a dynamically allocated matrix
void freeMatrix(int **Matrix, int row)
{
    for(int i=0; i<row; ++i)
        free(*(Matrix+i));
    free(Matrix);
}

void readMatrix(int **Matrix, int row, int col)
{
    printf("\nIntroduceti elementele Matricei:\n");

    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            printf("[%d][%d] = ", i+1, j+1);
            scanf("%d",*(Matrix+i)+j);
        }
    }
}

void printMatrix(int **Matrix, int row, int col)
{
    printf("\nMatricea este:\n");
    
    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
            printf("%3d",Matrix[i][j]);
        puts("\n");
    }
}

// prints Max(Matrix) and Min(Matrix)
void printMaxMin(int **Matrix, int row, int col)
{
    int maxim=**(Matrix+0)+0, minim=**(Matrix+0)+0;

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
        {
            if(maxim < **(Matrix+i)+j)    maxim = **(Matrix+i)+j;
            if(minim > **(Matrix+i)+j)    minim = **(Matrix+i)+j; 
        }

    printf("\nMaximum este: %d\n", maxim);
    printf("Minimum este: %d\n", minim);
}

// prints maximum on a given row
void printMaximRow_i(int **Matrix, int row, int col)
{
    int maxim, poz_row;
    printf("\nIntroduceti numarul unui rand pentru a afla maximul: ");
        scanf("%d", &poz_row);

    maxim = **(Matrix+poz_row-1)+0;

    for(int j=1; j<col; ++j)
        if(maxim < **(Matrix+poz_row-1)+j)    
            maxim = **(Matrix+poz_row-1)+j;

    printf("MaxRow[%d] = %d\n", poz_row, maxim); 
}

// prints minimum on a given collumn
void printMinimCollumn_j(int **Matrix, int row, int col)
{
    int minim, poz_col;
    printf("\nIntroduceti numarul unei coloane pentru a afla minimul: ");
        scanf("%d", &poz_col);

    minim = **(Matrix+0)+(poz_col-1);
    for(int i=1; i<row; ++i)
        if(minim > **(Matrix+i)+poz_col-1)    
            minim = **(Matrix+i)+poz_col-1;
    
    printf("MinCollumn[%d] = %d\n", poz_col, minim);
}

// prints maximum on each row and minimum on each collumn
void printMaxRow_MinCol(int **Matrix, int row, int col)
{
    int minim, maxim;
    puts("\n");

    for(int i=0, j=0; i<row; ++i)
    {
        maxim = **(Matrix+i)+j;
        for(int j=1; j<col; ++j)
            if(maxim < **(Matrix+i)+j)    
                maxim = **(Matrix+i)+j;
        printf("MaximRow[%d] = %d\n", i, maxim);
    }

    for(int i=0, j=0; j<col; ++j)
    {
        minim = **(Matrix+i)+j;
        for(int i=1; i<row; ++i)
            if(minim > **(Matrix+i)+j)
                minim = **(Matrix+i)+j;
        printf("MinCollumn[%d] = %d\n", j, minim);
    }
}

int main(void)
{
    int row, col;

    printf("Introduceti marimile unei matrici (randuri coloane): ");
        scanf("%d%d",&row,&col);
    
    int **Matrix = (int**) malloc(row * sizeof(int*));
        genCollumns(Matrix,row,col);

    readMatrix(Matrix,row,col);
        system("clear");
    printMatrix(Matrix,row,col);

    printMaxMin(Matrix,row,col);

    printMaximRow_i(Matrix,row,col);

    printMinimCollumn_j(Matrix,row,col);

    printMaxRow_MinCol(Matrix,row,col);

    return 0;
}