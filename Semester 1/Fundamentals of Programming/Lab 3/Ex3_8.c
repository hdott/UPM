/*
Se citesc doi întregi de la tastatură, a si b. Să se afișeze: 
- Media aritmetică 
- Media geometrică 
- Media armonică
*/

#include <stdio.h>
#include <math.h>

void main()
{
    int a, b;
    printf("Introduceti 2 numere intreg:\n");
        printf("a = "), scanf("%d", &a);
        printf("b = "), scanf("%d", &b);
    printf("\n");

    printf("Media Aritmetica este: %.4lf\n", (double)((a+b)/2));
    printf("Media Geometrica este: %.4lf\n", (double)(sqrt(a*b)));
    printf("Media Armonica este: %.4lf\n", (double)(2/((1/(double)a)+(1/(double)b))));    
}
