/*
Ce calculeaza functia de mai jos?
*/
/*
OUTPUT:
[8] 9
[7] 9
[6] 16
[5] 16
[4] 21
[3] 21
[2] 24
[1] 24
[0] return to main
Suma elementelor pe pozitie impara este: 24
*/

#include <stdio.h>
int debug=0;
int a[]={1,2,3,4,5,6,7,8,9};

int f(int i)
{
    if(!i)
    {
        printf("[%d]\treturn to main\n",i);
        return 0;
    }
    else if(a[i]%2)
    {
        printf("[%d]\t%d\n",i,debug+=a[i]);
        return f(i-1)+a[i];
    }
    else
    {
        printf("[%d]\t%d\n",i,debug);
        return f(i-1);
    }
}

void main()
{
    printf("Suma elementelor pe pozitie impara este: %d\n",f(sizeof(a)/4-1));
}
