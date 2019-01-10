/*
Se considera functia f definita recursiv.
Ce va returna f(6)?
*/
/*
OUTPUT:
[6] 6
[4] 10
[2] 12
[0] return to main
f(6) = 12
*/

#include <stdio.h>
int debug=0;

int f(int x)
{
    if(x<=1)
    {
        printf("[%d]\treturn to main\n",x);
        return x;
    }
    else
    {
        printf("[%d]\t%d\n",x,debug+=x);
        return f(x-2)+x;
    }
}

void main()
{
    printf("f(6) = %d\n",f(6));
}
