/*
Se citește un caracter din alfabet (minusculă) de la tastatură (getch / scanf / cin / cin.get). 
Să se afișeze: 
- Caracterul majusculă corespunzător 
- Caracterul următor și caracterul precedent din alfabet 
- Se vor încerca variante cu putc, printf, cout, cout.put
*/

#include <stdio.h>

void main()
{
    char caracter;

    printf("Introduceti un caracter din alfabet (litera mica):\n");
        printf("caracter = "), scanf("%c", &caracter);
    
    printf("\nCaracterul (litera mare este):  %c\n", caracter-32);
    printf("Caracterul anterior este:\t%c\n", caracter-1);
    printf("Caracterul urmator este:\t%c\n", caracter+1);
}
