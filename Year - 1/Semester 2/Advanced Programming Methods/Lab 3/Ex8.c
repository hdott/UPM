/* Sa se scrie un program (folosind subrutine) care numara propozitiile transmise
 *  prin linia de comanda.
 * Delimitatorii propozitiilor sunt .?!
 */

#include <stdio.h>
#include <string.h>

_Bool isSeparator(char ch)
{
    return (ch == '.') || (ch == '!') || (ch == '?');
}

int main(int argc, char* argv[])
{
    int sentences = 0;

    for(int i=1; i<argc; ++i)
        for(int j=0; j<strlen(argv[i]); ++j)
            if(isSeparator(argv[i][j])) ++sentences;

    printf("Numarul de propozitii introduse in linia de comanda -> %d\n", sentences);

    return 0;
}