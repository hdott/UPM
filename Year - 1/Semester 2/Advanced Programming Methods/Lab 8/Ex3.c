#include <stdio.h>
#include <stdlib.h>


long long **generateMatrix(int row, int col)
{
    long long **vector = (long long**) malloc(row * sizeof(long long*));

    for(int i=0; i<row; ++i)
        *(vector+i) = (long long*) calloc(col, sizeof(long long));

    return vector;
}

void freeMatrix(long long **vector, int row)
{
    for(long long i=0; i<row; ++i)
        free(*(vector+i));

    free(vector);
}

long long findMaxMatrix(long long **vector, int row, int col)
{
    long long max = *(*(vector+0)+0);

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            if(*(*(vector+i)+j) > max)
                max = *(*(vector+i)+j);

    return max;
}

void printMatrix(long long **vector, int row, int col)
{
    long long maxNr = findMaxMatrix(vector, row, col);
    int width = 0;
    while(maxNr/10 || maxNr%10) 
    {
        maxNr /= 10;
        ++width;
    }
    ++width;

    for(int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
            printf("%*lld", width, *(*(vector+i)+j));
        puts("");
    }
}

void copyMatrix(long long **vectorSource, long long **vectorDestination, int row, int col)
{
    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            *(*(vectorDestination+i)+j) = *(*(vectorSource+i)+j);
}

void SquareMatrixMultiplication(long long **vector1, long long **vector2, long long **vector3, int row, int col)
{
    long long **vector = generateMatrix(row, col);

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            for(int k=0; k<row; ++k)
                *(*(vector+i)+j) +=  *(*(vector1+i)+k) * *(*(vector2+k)+j);

    copyMatrix(vector, vector3, row, col);
    free(vector);
}

long long **MatrixExponentiation(long long **vector, long long **vectorRez, int row, int col, int power, int index)
{
    if(1<<index > power)    return vectorRez;
    
    if((power & (1<<index)) && vectorRez)
        SquareMatrixMultiplication(vector, vectorRez, vectorRez, row, col);
    else if((power & (1<<index)) && !vectorRez)
    {
        vectorRez = generateMatrix(row, col);
        copyMatrix(vector, vectorRez, row, col);
    }

    SquareMatrixMultiplication(vector, vector, vector, row, col);
    MatrixExponentiation(vector, vectorRez, row, col, power, index+1);
}


int main(void)
{
    long long **vector = generateMatrix(3, 3);
    int k = 1;
    for(int i=0; i<3; ++i)
        for(int j=0; j<3; ++j)
            vector[i][j] = 1;
    long long **vectorRez = NULL;

    long long power = 30;

    printMatrix(vector, 3, 3);

    vectorRez = MatrixExponentiation(vector, vectorRez, 3, 3, power, 0);

    puts("");
    printMatrix(vectorRez, 3, 3);

    free(vector);
    free(vectorRez);
    return 0;
}