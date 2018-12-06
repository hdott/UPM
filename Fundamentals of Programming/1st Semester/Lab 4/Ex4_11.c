/*
Se citesc trei numere întregi de la tastatură, după care se afișează meniul: 
- Afișare maxim 
- Afișare minim 
- Afișare sumă 
- Afișare produs 
- Afișarea soluțiilor ecuației de gradul II 
Introduceți opțiunea: 

Se citește un caracter reprezentând opțiunea corespunzătoare meniului dat. 
Să se execute operația corespunzătoare opțiunii selectate. 
Să se folosească instrucțiunea switch și macro (la subpunctele a, b, c, d)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max(a,b) a > b ? a : b
#define min(a,b) a < b ? a : b
char a[] = "Afisare maxim";
char b[] = "Afisare minim";
char c[] = "Afisare suma";
char d[] = "Afisare produs";
char e[] = "Afisarea solutiilor ecuatiei de gradul II";

int meniu()
{
    system("clear");
    printf("a. %s\n", a);
    printf("b. %s\n", b);
    printf("c. %s\n", c);
    printf("d. %s\n", d);
    printf("e. %s\n", e);

    int caracter;
    printf("Selectati optiunea: "), scanf("%lc", &caracter);
        scanf("%lc", &caracter), system("clear");

    return caracter;
}

void ec_gr_2(int x, int y, int z)
{
    double D, x1, x2, Re, Im;
    printf("Ecuatia este (%d)*x^2 + (%d)*x + (%d) = 0\n\n", x, y, z);

    D = pow(y,2) - (4 * x * z);

    if(D > 0)
    {
        x1 = (-y + sqrt(D)) / (2 * x);
        x2 = (-y - sqrt(D)) / (2 * x);
        printf("Solutiile ecuatiei sunt:\nx1 = %lf\nx2 = %lf\n", x1, x2);
    }
    else if(D == 0)
    {
	    x1 = x2 = (-y) / (2 * x);
	    printf("Solutiile ecuatiei sunt egale:\n x1 = x2 = %lf\n", x1);
    }
    else
    {
	    printf("Solutiile ecuatiei nu sunt reale.\n");
	    Re = (-y) / (2 * x);
	    Im = sqrt(-D) / (2 * x);
	    printf("Partea Reala este:\tRe = %lf\n", Re);
	    printf("Partea Imaginara este:\tIm = %lf\n\n", Im);
    
	    printf("Solutiile complexe sunt: \n");
	    printf("x1 = %lf + %lf*i\n", Re, Im);
	    printf("x2 = %lf - %lf*i\n", Re, Im);
    }
}

void main()
{
    int x, y, z, optiune;

    printf("Introduceti 3 numere intregi:\n");
        printf("x = "), scanf("%d", &x);
        printf("y = "), scanf("%d", &y);
        printf("z = "), scanf("%d", &z);

    switch(optiune = meniu())
    {
        case('a'):
            printf(" ~ %s ~\n\nMaxim(%d, %d, %d): %d\n", a, x, y, z, max(max(x,y),z));
            break;
        case('b'):
            printf(" ~ %s ~\n\nMinim(%d, %d, %d): %d\n", b, x, y, z, min(min(x,y),z));
            break;
        case('c'):
            printf(" ~ %s ~\n\nSuma(%d, %d, %d): %d\n", c, x, y, z, x+y+z);
            break;
        case('d'):
            printf(" ~ %s ~\n\nProdus(%d, %d, %d): %d\n", d, x, y, z, x*y*z);
            break;
        case('e'):
            printf(" ~ %s ~\n\n", e);
            ec_gr_2(x, y, z);
            break;
        default:
            printf("Optiunea selectata nu exista!\n");
            break;
    }
}
