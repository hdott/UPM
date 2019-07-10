/*
 * O functie care afiseaza reprezentarea in baza 2 a unui numar intreg citit de
 *  la tastatura.
 */

#include <stdio.h>

void print_dec_to_binary(int n);

int main(void)
{
    int n;

    printf("Input a number n to find its binary representation: ");
        scanf("%d",&n);
    
    printf("Binary: ");
        print_dec_to_binary(n);

    return 0;
}

// prints a decimal number in its binary form
void print_dec_to_binary(int n)
{
    _Bool bit, conditie=0;

    for(int i=(sizeof(int)*8)-1; i>=0; --i)
    {
        bit=n&(1<<i);

        if(!bit && !conditie)       // if(bit == 0 && conditie == 0)
            continue;
        else if(bit && !conditie)   // if(bit == 1 && conditie == 0)
        {
            conditie=1;
            printf("%d",bit);
        }
        else
            printf("%d",bit);
    }
    printf("\n");
}