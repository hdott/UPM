/*
Se citește un caracter de la tastatură. 
Să se determine dacă este un caracter numeric (0-9) sau un operator matematic (+, -, *, /, %).
*/

#include <stdio.h>

void main()
{
    int caracter;

    printf("Introduceti un caracter numeric sau un operator matematic:\n");
        printf("caracter = "), caracter = getchar();

    if(caracter > 47 && caracter < 58)
        printf("\n%c este un caracter numeric\n", caracter);
    else if(caracter > 36 && caracter < 48)
        printf("\n%c este un operator matematic\n", caracter);    
}
