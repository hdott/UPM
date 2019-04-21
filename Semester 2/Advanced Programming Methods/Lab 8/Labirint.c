#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct punct
{
    int x, y;
} DRUM;
DRUM path[MAX];

int xStart, yStart, xEnd, yEnd, row, col;
int **labirint = NULL;

void AfisareDrum(int pasi)
{
    for(int i=0; i<pasi; ++i)
        printf("(x,y): (%d,%d)\n", path[i].x, path[i].y);
    puts("");
}

void ParcurgereLabirint(int x, int y, int pasi)
{
    if(x == xEnd && y == yEnd)  
        AfisareDrum(pasi);
    else if(x<0 || y<0 || x>=row || y>=col || labirint[x][y] == 1)
        return;
    else
    {
        path[pasi].x = x;
        path[pasi].y = y;
        labirint[x][y] = 1;

        ParcurgereLabirint(x, y-1, pasi+1);
        ParcurgereLabirint(x-1, y, pasi+1);
        ParcurgereLabirint(x, y+1, pasi+1);
        ParcurgereLabirint(x+1, y, pasi+1);
        labirint[x][y] = 0;
    }
}

int main(void)
{
    FILE *file = fopen("labirint.txt", "r");
    fscanf(file, "%d%d", &xStart, &yStart);
    fscanf(file, "%d%d", &xEnd, &yEnd);
    fscanf(file, "%d%d", &row, &col);

    labirint = (int**) malloc(row * sizeof(int*));
    for(int i=0; i<row; ++i)
        *(labirint+i) = (int*) malloc(col * sizeof(int));

    for(int i=0; i<row; ++i)
        for(int j=0; j<col; ++j)
            fscanf(file, "%d", &labirint[i][j]);
    
    fclose(file);

    ParcurgereLabirint(xStart, yStart, 0);

    for(int i=0; i<row; ++i)
        free(*(labirint+i));
    free(labirint);
    return 0;
}