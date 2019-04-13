/* Sa se implementeze citirea cu validare, numarul citit sa fie in intervalul dat [a,b].
 *  Sa se citeasca numere pana cand se da o valoare din interval. Sa se foloseasca
 *  instructiuni de salt.
 */

#include <stdio.h>

_Bool Interval(int min, int max, int x)
{
    if(x >= min && x <= max)    return 1;

    return 0;
}


int main(void)
{
    int min, max;

    printf("Introduceti intervalul:\n");
    printf("[min,max]: ");
    scanf("%d%d", &min, &max);

    while(1)
    {
        volatile int temp;
        printf("Introduceti un numar: ");
        printf("(int): ");
        scanf("%d", &temp);

        if(Interval(min, max, temp))
        {
            printf("\nNumarul face parte din intervalul introdus anterior!\n");
            break;
        }
        else    printf("\nTry again...\n");
    }

    return 0;
}