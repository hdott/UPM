/* Sa se scrie un program (folosind subrutine) care afiseaza lungimea sirului de
 *  caractere dat prin argumentele liniei de comanda.
 */

#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    long size = 0;

    for(int i=1; i<argc; ++i)
        size += strlen(argv[i]);

    printf("Lungimea sirului de caractere -> %ld\n", size);

    return 0;
}