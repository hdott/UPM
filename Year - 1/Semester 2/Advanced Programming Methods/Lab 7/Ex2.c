#include <stdio.h>

int power(int x, int y)
{
    if(y==1)    return x;

    return x*power(x, --y);
}

int main(void)
{
    int x, y;

    printf("Introduceti 2 numere: \n");
    printf("(int^int): ");
    scanf("%d", &x);
    getchar();
    scanf("%d", &y);

    printf("pow -> %d\n", power(x, y));

    return 0;
}