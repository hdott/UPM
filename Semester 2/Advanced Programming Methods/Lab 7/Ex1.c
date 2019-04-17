#include <stdio.h>

int gcd(int x, int y)
{
    if(!y)  return x;

    return gcd(y, x%y);
}


int main(void)
{
    int x, y;

    printf("Introduceti 2 numere:\n");
    printf("(int,int): ");
    scanf("%d%d", &x, &y);

    printf("gcd -> %d\n", gcd(x, y));

    return 0;
}