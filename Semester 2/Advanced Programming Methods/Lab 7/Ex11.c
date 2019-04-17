#include <stdio.h>

int Something(int nr)
{
    scanf("%d", &nr);

    if(!nr)             return 0;

    if(!(nr%2) && nr)   printf("%d\n", nr);
    
    Something(nr);

    if(nr%2 && nr)      printf("%d\n", nr);
}

int main(void)
{
    Something(0);

    return 0;
}