/*
Se considera functia f definita recursiv.
Ce va returna f(3)?
*/
/*
OUTPUT:
[3] 12.00
[2] 18.00
[1] 20.00
[0] return to main
f(3) = 20.00
*/

#include <stdio.h>
float debug=0.0;

float f(int i)
{
    if(!i)
    {
        printf("[%d]\treturn to main\n",i);
        return 0;
    }
    
    printf("[%d]\t%.2f\n",i,debug+=i*(i+1));
    return f(i-1)+i*(i+1);
}

void main()
{
    printf("f(3) = %.2f\n",f(3));
}
