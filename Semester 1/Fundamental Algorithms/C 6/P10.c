/*
Se considera functia f definita recursiv.
Ce va returna f(10)?
*/
/*
OUTPUT:
[10]    10
[7]     17
[4]     21
[1]     22
[-2]    return to main
f(10) = 22
*/

#include <stdio.h>
int debug=0;

int f(int x)
{
    if(x<1)
    {
        printf("[%d]\treturn to main\n",x);
        return 0;
    }
    else
    {
        printf("[%d]\t%d\n",x,debug+=x);
        return f(x-3)+x;
    }
}

void main()
{
    printf("f(10) = %d\n",f(10));
}
