/*
Se citește un număr întreg de la tastatură. Să se determine dacă:
- Este par 
- Este divizbil cu 4 
- Este multiplu de 5 

Pentru fiecare caz se va afișa un mesaj corespunzător (atât pentru afirmativ cât și pentru negativ).
*/

#include <stdio.h>

void main()
{
    int nr;

    printf("Introduceti un numar intreg:\n");
        printf("nr = "), scanf("%d", &nr), printf("\n");
    
    if((nr%10) % 2 == 0)
        printf("%d este PAR\n", nr);
    else
        printf("%d este IMPAR\n", nr);

    if((nr%100) % 4 == 0)
        printf("%d este divizibil cu 4\n", nr);
    else
        printf("%d NU este divizibil cu 4\n", nr);

    if((nr%10) == 0 || (nr%10) == 5)
        printf("%d este multiplu de 5\n", nr);
    else
        printf("%d NU este multiplu de 5\n", nr);
}
