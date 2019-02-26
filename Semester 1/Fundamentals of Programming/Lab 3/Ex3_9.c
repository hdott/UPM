/*
Se citește un număr natural de la tastatură, să se determine: 
- Dacă este pătrat perfect 
- Să se afiseze un mesaj corespunzător
*/

#include <stdio.h>
#include <math.h>

void main()
{
    unsigned int nr;
    printf("Introduceti un numar natural pentru a afla daca este patrat perfect:\n");
        scanf("%u", &nr);

    double aux_nr = nr;
    if((int)(sqrt(nr)) == sqrt(aux_nr))
        printf("%d este Patrat Perfect\n", nr);
    else
        printf("%d NU este Patrat Perfect\n", nr);
}
