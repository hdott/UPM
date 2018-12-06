/*
Se citește un număr întreg de 4 cifre de la tastatură, după care se afișează meniul: 
a. Afișare paritate ultima cifră 
b. Afișare paritate prima cifră 
c. Afișare suma cifrelor 
d. Afișare număr rezultat după inserarea cifrei 0 la mijlocul numărului
*/

#include <stdio.h>
#include <stdlib.h>
char a[] = "Afisare paritate ultima cifra";
char b[] = "Afisare paritate prima cifra";
char c[] = "Afisare suma cifrelor";
char d[] = "Afisare numar rezultat dupa inserarea cifrei 0 la mijlocul numarullui";

int meniu()
{
    system("clear");
    printf("a. %s\n", a);
    printf("b. %s\n", b);
    printf("c. %s\n", c);
    printf("d. %s\n", d);

    int optiune;
    printf("Alegeti optiunea: "), getchar();
    optiune = getchar();

    return optiune;
}

void paritate(int x)
{
    if(x % 2 == 0)
        printf("PARA\n");
    else
        printf("IMPARA\n");
}

int sum_digit(int x)
{
    int sum = 0;
    sum = sum + x%10, x = x/10;
    sum = sum + x%10, x = x/10;
    sum = sum + x%10, x = x/10;
    sum = sum + x;

    return sum;
}

int insert_0_middle(int x)
{
    int aux1, aux2;
    aux1 = x / 100;
    aux2 = x % 100;
    x = aux1 * 1000 + aux2;

    return x;
}

void main()
{
    int nr, optiune;
    
    printf("Introduceti un numar intreg de 4 cifre:\n");
        printf("nr = "), scanf("%d", &nr);

    optiune = meniu();
        system("clear");
    if(optiune == 'a')
        printf(" ~ %s ~\n\nUltima cifra este: ", a), paritate(nr%10);
    else if(optiune == 'b')
        printf(" ~ %s ~\n\nPrima cifra este: ", b), paritate(nr/1000);
    else if(optiune == 'c')
        printf(" ~ %s ~\n\nSuma cifrelor este: %d\n", c, sum_digit(nr));
    else if(optiune == 'd')
        printf(" ~ %s ~\n\nRezultatul este: %d\n", d, insert_0_middle(nr));
}
