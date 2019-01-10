/*
Se considera functia f definita recursiv.
Ce va returna f(5)?
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
