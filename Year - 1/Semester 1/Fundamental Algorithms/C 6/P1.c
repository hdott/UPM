/*
Se considera functia f definita recursiv.
Ce va returna f(5)?
*/

/*
OUTPUT:
[5] -5
[4] -1
[3] -4
[2] -2
[1] -3
[0] return to main
*/

#include <stdio.h>
int debug=0;

int f(int i)
{
    printf("[%d]\t",i);
    if(!i)
    {
        printf("return to main\n");
        return 0;
    }
    if(!(i%2))
    {
        printf("%2d\n",debug+=i);
        return f(i-1)+i;
    }
    else
    {
        printf("%2d\n",debug-=i);
        return f(i-1)-i;
    }
}

void main()
{
    printf("\nf(5) returneaza: %d\n",f(5));
}
