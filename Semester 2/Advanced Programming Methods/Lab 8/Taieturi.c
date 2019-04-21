#include <stdio.h>
#include <stdlib.h>
#define MAX 50


typedef struct punct
{
    int x,y;
} doTT;

doTT Punct[MAX];
int size;
doTT hole;

typedef struct dreptunghi
{
    int x, y, length, height;
} RECTANGLE;

RECTANGLE recMax;


_Bool hasHole(int x, int y, int length, int height)
{
    for(int i=0; i<size; ++i)
        if(Punct[i].x > x && 
            Punct[i].y > y && 
            Punct[i].x < (x+length) &&
            Punct[i].y < (y+height))     
        {
            hole.x = Punct[i].x;
            hole.y = Punct[i].y;
            return 1;
        }

    return 0;
}

_Bool isMaxim(int length, int height)
{
    if(recMax.length * recMax.height < 
        length * height)    return 1;

    return 0;
}

void Cuts(int x, int y, int length, int height)
{
    if(hasHole(x, y, length, height))
    {
        Cuts(x, y, hole.x-x, height);
        Cuts(hole.x, y, length-hole.x+x, height);
        Cuts(x, y, length, hole.y-y);
        Cuts(x, hole.x, length, height-hole.y+y);
    }
    else if(isMaxim(length, height))
    {
        recMax.x = x;
        recMax.y = y;
        recMax.length = length;
        recMax.height = height;
    }
}


// int main(void)
// {


//     return 0;
// }