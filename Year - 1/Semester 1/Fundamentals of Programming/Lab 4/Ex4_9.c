/*
Se citesc două numere întregi de la tastură, după care se afișează meniul: 
a. Suma 
b. Produsul 
c. Câtul (a / b) 
d. Restul (a mod b) 
e. Iesire 
Introduceți opțiunea: 

Se citește un caracter de la tastatură corespunzător opțiunii selectate. 
În funcție de caracter se va executa operația corespunzătoare. 
În caz de opțiune invalidă se va afișa un mesaj corespunzător.
*/

#include <stdio.h>
#include <stdlib.h>
char a[] = "Suma";
char b[] = "Produsul";
char c[] = "Catul";
char d[] = "Restul";
char e[] = "Iesire";

int meniu()
{
    system("clear");
    printf("a. %s\n", a);
    printf("b. %s\n", b);
    printf("c. %s\n", c);
    printf("d. %s\n", d);
    printf("e. %s\n", e);

    int optiune;
    printf("\nIntroduceti optiunea: "), getchar();
        optiune = getchar();

    return optiune;
}

int main()
{
    int x, y, optiune;

    printf("Introduceti 2 numere intregi:\n");
        printf("x = "), scanf("%d", &x);
        printf("y = "), scanf("%d", &y);
    
    optiune = meniu();
        system("clear");
    if(optiune == 'a')
        printf(" ~ %s ~\n\nSuma(%d,%d): %d\n", a, x, y, x+y);
    else if(optiune == 'b')
        printf(" ~ %s ~\n\nProdus(%d,%d): %d\n", b, x, y, x*y);
    else if(optiune == 'c')
        printf(" ~ %s ~\n\nCatul(%d,%d): %d\n", c, x, y, x/y);
    else if(optiune == 'd')
        printf(" ~ %s ~\n\nRestul(%d,%d): %d\n", d, x, y, x%y);
    else if(optiune == 'e')
        return 0;
    else
        printf("Optiunea selectata nu este disponibila!\n");

    return 0;
}
