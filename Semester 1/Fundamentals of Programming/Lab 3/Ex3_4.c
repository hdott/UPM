/*
Se  citesc de la tastatură un număr întreg(int) și un număr real(double) (n1 și n2).
Citirea și afișarea valorilor numerice se va realiza prin afișarea în prealabil al unui mesaj corespunzător.
Se cere să se afișeze: 
- Valorea de adevăr pentru: 
	#Negat(n1 este egal cu 2) 
	#N2 este diferit de 5 
	#(n1 este mai mare decât 2) și (n2 este mai mic sau egal decât 5.5) 
	#N1 sau n2 sunt pozitive 
- Valoarea expresiei (n1^3 - n2^2 - n1*n2 + 10) 
- Valoarea expresiei n1^n2 
- Valorea expresiei n1/n2 
- Câtul împărțirii lui n1 la n2 
- Restul împărțirii lui n1 la n2
*/

#include <stdio.h>
#include <math.h>

void val_adevar(int x)
{
    if(x == 0)
        printf("FALSE\n");
    else if(x == 1)
        printf("TRUE\n");
    else
        printf("dunno\n");
}

void main()
{
    int n1;
    double n2;

    printf("Introduceti un numar intreg:\n");
        printf("n1 = "), scanf("%d", &n1);
    printf("Introduceti un numar real:\n");
        printf("n2 = "), scanf("%lf", &n2);

    
    printf("\na. Valoarea de adevar pentru:\n");
        printf("\t1. !(n1 == n2) => "), val_adevar(!(n1 == n2));
        printf("\t2. n2 != 5 => "), val_adevar(n2 != 5);
        printf("\t3. ((n1 > 2) && (n2 <= 5.5)) => "), val_adevar((n1>2) && (n2<=5.5));
        printf("\t4. (n1 >= 0) || (n2 >= 0) => "), val_adevar((n1>=0) || (n2>=0));
    printf("b. (n1^3 - n2^2 - n1 * n2 + 10 = %lf\n", pow(n1,3)-pow(n2,2)-n1*n2+10);
    printf("c. n1^n2 = %.4lf\n", pow(n1,n2));
    printf("d. n1 / n2 = %.4lf\n", n1/n2);
    printf("e. n1 / n2 = %d\n", (int)(n1/n2));
    printf("f. n1 %% n2 = %.4lf\n", fmod(n1,n2));
}
