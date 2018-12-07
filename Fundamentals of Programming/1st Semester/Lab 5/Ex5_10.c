/*
Se citește n, un număr întreg. 
Să se determine toate numerele pitagorice mai mici sau egale cu n (i.e. numere ce satisfac teorema lui Pitagora).
*/

#include <stdio.h>
#include <math.h>

//loop ce verifica si printeaza numerele pitagoreice
//conditia fiind ca numarul gasit utilizand teorema lui pitagora sa fie intreg
//si mai mic decat numarul introdus de la tastatura
void nr_pitag(int x)
{
    for(int i = 1; i < x; ++i)
        for(int j = i+1; j <= x; ++j)
            if((sqrt(pow(i,2)+pow(j,2)) <= x) && (sqrt(pow(i,2)+pow(j,2)) == (int)(sqrt(pow(i,2)+pow(j,2)))))
                printf("%d %d %d\n", i, j, (int)(sqrt(pow(i,2)+pow(j,2))));
}

void main()
{
    int n;

    printf("Introduceti un numar intreg pentru a afla toate numerele Pitagoreice mai mici sau egale cu el:\n");
        printf("n = "), scanf("%d", &n);

    printf("\nNumerele Pitagoreice mai mici sau egale cu %d sunt:\n", n);
        nr_pitag(n);
}
