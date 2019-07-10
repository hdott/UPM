/*
Se citesc trei numere întregi de la tastatură, după care se afișează meniul: 
a. Afișare maxim 
b. Afișare minim 
c. Afișare sumă 
d. Afișare produs 
e. Afișarea soluțiilor ecuației de gradul II 
Selectați opțiunea: 

Se citește un caracter reprezentând opțiunea corespunzătoare meniului dat. 
Să se execute operația corespunzătoare opțiunii selectate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
        scanf("%lc", &caracter);

    return caracter;
}

int maxim(int x, int y, int z)
{
    if(x > y && x > z)
        return x;
    else if(y > x && y > z)
        return y;
    else
        return z;
}

int minim(int x, int y, int z)
{
    if(x < y && x < z)
        return x;
    if(y < x && y < z)
        return y;
    else
        return z;
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
    int x, y, z, caracter;

    printf("Introduceti 3 numere intregi:\n");
        printf("x = "), scanf("%d", &x);
        printf("y = "), scanf("%d", &y);
        printf("z = "), scanf("%d", &z);

    caracter = meniu();
        system("clear");

    if(caracter == 'a')
        printf(" ~ %s ~\n\nMaxim(%d, %d, %d): %d\n", a, x, y, z, maxim(x, y, z));
    else if(caracter == 'b')
        printf(" ~ %s ~\n\nMinim(%d, %d, %d): %d\n", b, x, y, z, minim(x, y, z));
    else if(caracter == 'c')
        printf(" ~ %s ~\n\nSuma(%d, %d, %d): %d\n", c, x, y, z, x+y+z);
    else if(caracter == 'd')
        printf(" ~ %s ~\n\nProdus(%d, %d, %d): %d\n", d, x, y, z, x*y*z);
    else if(caracter == 'e')
    {
        printf(" ~ %s ~\n\n", e);
        ec_gr_2(x, y, z);
    }
    else
        printf("Optiunea selectata nu exista!\n");
}
