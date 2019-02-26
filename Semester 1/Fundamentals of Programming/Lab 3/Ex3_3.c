/*
Se citesc trei variabile întregi x, y și z de la tastatură. Să se afișeze: 
- Radical(x^2 + y^2 + z^2) // funcția sqrt(număr_double) sau sqrtf(număr_float) în biblioteca <math.h> 
- Exp(x * ln(y * z) // exp, log în <math.h> 
- |x - y - z| // abs în <math.h> 
- (x + y + z)^2 
- Restul împărțirii lui x la y 
- Valoarea întreagă a împărțirii lui x la z
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int x, y, z;

    printf("Introduceti un numar intreg:\n");
        printf("x = "), scanf("%d", &x);
    printf("Introduceti un numar intreg:\n");
        printf("y = "), scanf("%d", &y);
    printf("Introduceti un numar intreg:\n");
        printf("z = "), scanf("%d", &z);
    printf("\n");

    printf("a. radical(x^2 + y^2 + z^2) = %.4f\n", sqrt(pow(x,2)+pow(y,2)+pow(z,2)));
    printf("b. exp(x * ln(y * z)) = %.4f\n", exp(x*log(y*z)));
    printf("c. |x - y - z| = %d\n", abs((x-y-z)));
    printf("d. (x + y + z)^2 = %d\n", pow((x+y+z),2));
    printf("e. x % y = %d\n", x%y);
    printf("f. x / z = %d\n", x/z);    
}
