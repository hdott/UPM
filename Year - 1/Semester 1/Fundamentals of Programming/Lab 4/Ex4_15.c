/*
Se citesc 3 numere întregi reprezentând: ora, minutul, secunda. 
Să se afișeze ora, minutul și secunda rezultată din adăugarea a N secunde la timpul citit inițial, 
unde N este un număr întreg citit de la tastatură. 
Se va folosi operatorul ternar. 
Condiție ? Expr1 : Expr2;
*/

#include <stdio.h>
#include <stdlib.h>
#define max_ora 24
#define max_m_s 60
#define incrementeaza(x,y,max) x >= max ? (y = y + x/max) && (x = x%max) : (x = x)
    // macroul verifica daca secunda/minut/ora este mai mare decat maximul respectiv
    // si modifica ambele variante in asa fel cat sa nu depaseasca limitele respective
    
void main()
{
    int ora, minut, secunda, zi, N;

    printf("Introduceti 3 numere care sa reprezinte:\n");
        printf("ora\t= "), scanf("%d", &ora);
        printf("minut\t= "), scanf("%d", &minut);
        printf("secunda\t= "), scanf("%d", &secunda);     
    system("clear");

    printf("Introduceti un numar de secunde pentru a incrementa timpul:\n");
        printf("N = "), scanf("%d", &N);
    system("clear");

    printf("Timp initial:\t%2d:%2d:%2d\n", ora, minut, secunda);
    
    secunda = secunda + N;
    incrementeaza(secunda, minut, max_m_s);
    incrementeaza(minut, ora, max_m_s);
    incrementeaza(ora, zi, max_ora);

    printf("Timp modificat:\t%2d:%2d:%2d\n", ora, minut, secunda);
}
