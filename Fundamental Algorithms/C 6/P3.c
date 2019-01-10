/*
Ce valor vor cintine variabilele x si y pentru valorile initiale:
a=75, b=12, x=0, y=0, in urma executarii functiei f?
*/
/*
OUTPUT:
x=0
y=0
*/

#include <stdio.h>

void f(long a, long b, long *x, long *y)
{
    printf("%ld\t%ld\t%ld\t%ld\n",a,b,*x,*y);
    if(*y>=b)
    {
        *y=a-b;
        *x++;
        f(a-b,b,x,y);
    }
}

void main()
{
    long x=0, y=0;

    f(75,12,&x,&y);
    printf("x = %ld\n",x);
    printf("y = %ld\n",y);
}
