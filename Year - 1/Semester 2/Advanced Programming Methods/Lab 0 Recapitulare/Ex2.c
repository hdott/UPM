/*
 * O functie care calculeaza al n-lea numar prim. n se citeste de la tastatura
 */

#include <stdio.h>
#include <math.h>

int nth_prime(int n);

int main(void)
{
    int n;
    
    printf("Input a number n to find the n-th prime number: ");
        scanf("%d",&n);

    printf("%d-th prime number is: %d\n",n,nth_prime(n));

    return 0;
}

// returns n-th prime number
int nth_prime(int n)
{
    int counter=0;

    for(int i=2; ; ++i)
    {
        int conditie=0;
        for(int j=2;j<=sqrt(i); ++j)
            if(!(i%j))  // if(i%j == 0)
            {
                conditie=1;
                break;
            }
        
        if(!conditie)   // if(conditie == 0) -> nr is prime
            counter++;

        if(counter == n)
            return i;
    }           
}