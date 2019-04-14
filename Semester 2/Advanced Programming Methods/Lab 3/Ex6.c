/* Sa se scrie un program(folosind subrutine) care afiseaza numarul de aparitii al 
 *  primului argument in textul care urmeaza:
 * Exemplu: rulam programul aparitii cu parametrii:
 * limbaj limbajul c este cel mai raspandit limbaj de programare dintre toate
 *  limbajele
 * Rezultat: 3?
 */

#include <stdio.h>
#include <string.h>


int main(int argc, char* argv[])
{
    int count = 1;
    char *s = argv[1];

    for(int i=2; i<argc; ++i)
        if(!strcmp(s, argv[i])) ++count;

    printf("Argumente identice cu primul -> %d\n", count);

    return 0;
}