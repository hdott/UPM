/*
 * Sa se scrie un program care citeste caractere de la tastatura pana la apasarea
 *  CTRL+Z si le salveaza intr-un fisier text.
 */

#include <stdio.h>

int main(void)
{
    FILE *file = fopen("mynewfile.txt","w");
    int caracter;

    while((caracter = getchar()) != EOF)
    {
        fputc(caracter,file);
    }

    fclose(file);
    return 0;
}