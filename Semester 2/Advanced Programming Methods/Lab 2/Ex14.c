/* Sa se genereze numere intregi aleatoare in intervalul [-RAND_MAX, RAND_MAX]. Dupa
 *  fiecare generare utilzatorul sa fie intrebat daca doreste sa continue sau nu.
 * Sa se verifice cate numere sunt in fiecare interval dat (intervalele nu se suprapun).
 *  Lista intervalelor se da intr-un fisier. Nu se precizeaza numarul total de linii
 *  in fisier.
 * Sa se foloseasca continue si break sau goto.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

_Bool Continue()
{
    char ch;

    printf("\nWould you like to Continue?\n");
    printf("(Y/n): ");
    ch = getchar();
    getchar();

    if(ch == 'Y' || ch == 'y')  return 1;
    if(ch == 'N' || ch == 'n')  return 0;
}

unsigned NumbersBetween(int x, int y)
{
    if(x > y)   return (unsigned) x-y;
    else        return (unsigned) y-x;
}

_Bool EqualToPrevious(int x, int y)
{
    static volatile int prevX=0, prevY=0;

    if(x == prevX && y == prevY)    return 1;

    prevX = x;
    prevY = y;

    return 0;
}

int main(void)
{
    time_t t;
    srand((unsigned) time(&t));

    do
    {
        printf("rand-> %d\n", rand() - (rand()));
    } while(Continue());
    puts("");
    
    FILE *file = fopen("intervale.txt", "r");

    int x, y;

    while(!feof(file))
    {
        fscanf(file, "%d%d", &x, &y);

        if(EqualToPrevious(x, y))   break;

        printf("Numere in intervalul -> [%d,%d] -> %u\n", x, y, NumbersBetween(x,y));
    }

    fclose(file);
    return 0;
}