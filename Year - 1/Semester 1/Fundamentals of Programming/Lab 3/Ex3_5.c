/*
Se citesc trei numere naturale (atenție la tip!) de la tastatură reprezentând lungimile laturilor unui triunghi
(se citesc pe rând valorile catetelor și a ipotenuzei). Să se determine: 
- Daca triunghiul este dreptunghic și/sau isoscel sau echilateral 
- Să se afișeze un mesaj corespunzător atât pentru cazurile afirmative cât și pentru cele negative.
*/

#include <stdio.h>

int power_2(int x)
{
    int aux_x = 1;
    for(int i = 0; i < 2; ++i)
        aux_x = aux_x * x;

    return aux_x;
}

void main()
{
    unsigned int cat1, cat2, ipot;
    
    printf("Introduceti laturile unui triunghi:\n");
        printf("cateta1 = "), scanf("%u", &cat1);
        printf("cateta2 = "), scanf("%u", &cat2);
        printf("ipotenuza = "), scanf("%u", &ipot);

    if(cat1+cat2 <= ipot)
        printf("Valorile introduse nu pot forma un triunghi!");
    else
    {
        if((power_2(cat1) + power_2(cat2)) == power_2(ipot))
            printf("Triunghiul\teste Dreptunghic\n");
        else
            printf("Triunghiul NU\teste Dreptunghic\n");
        
        if(cat1 == cat2 && cat2 != ipot)
            printf("Triunghiul\teste Isoscel\n");
        else
            printf("Triunghiul NU\teste Isoscel\n");

        if(cat1 == cat2 && cat2 == ipot)
            printf("Triunghiul\teste Echilateral\n");
        else
            printf("Triunghiul NU\teste Echilateral\n");
    }
}
