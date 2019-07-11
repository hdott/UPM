// O functie recursiva care calculeaza suma cifrelor unui numar intreg

#include <stdio.h>

static int sum = 0;

int SumOfDigitsRecursive(int x)
{
    sum += x%10;

    if((x%10) || (x/10))
        return SumOfDigitsRecursive(x/10);

    return sum;
}

int main(void)
{
    int nr;

    printf("Introduceti un numar pentru a afla suma cifrelor sale: ");
        scanf("%d", &nr);

    printf("\nSuma cifrelor lui %d este: %d\n", nr, SumOfDigitsRecursive(nr));

    return 0;
}