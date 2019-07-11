/* Se considera un meniu principal ce contine doua optiuni:
 * - Operatii de baza
 * - Operatii extinse
 * 1. Operatii de baza
 * Sa se afiseze un meniu ce contine urmatoarele optiuni:
 * - Creare manunala a vectorului (se citesti si o valoare n reprezentand numarul de
 *      elemente)
 * - Generare automata a vectorului (se citeste si o valoare n reprezentand numarul de
 *      elemente)
 * - Afisare
 * - Cautare
 * Nota: Vectorul va contine numere intregi, iar ordonarea va fi realizata la inserare,
 *          fara a utiliza ulterior algoritmi de sortare.
 * 2. Operatii extinse
 * Scopul operatiilor extinse este de a demonstra utilitatea cautarii binare prin
 *  compararea cu cautarea secventiala. Se va utiliza un vector uzual in care elementele
 *  sunt adaugate secvential si un vector in care elementele sunt inserate astfel incat
 *  sa rezulta un vector sortat.
 * Elementele vectorilor reprezinta caractere generate aleator.
 * Sa se afiseze un meniu cu urmatoarele optiuni:
 * - Generarea automata a celor doi vectori (cu citirear in prealabil a numarului de
 *      elemente n)
 * - Afisarea elementelor de pe pozitiile n/4, n/2 si n
 * - Timpul de cautare comparativ al elementului aflat pe pozitia n/4 (din vectorul
 *      ordonat)
 * - Timpul de cautare comparativ al elementului aflat pe pozitia n/2 (din vectorul
 *      ordonat)
 * - Timpul de cautare comparativ al elementului aflat pe pozitia n (din vectorul
 *      ordonat)
 * La selectarea operatiei de generare, se va citi numarul de elemente si pentru 
 *  fiecare element se vor genera 100 de caractere aleator (terminate cu '\0').
 * Timpul de cautare va fi masurat pentru n=100, n=10000 si n=100000.
 */


#include <stdio.h>
#include "meniu.h"


int main(void)
{
    ControlMeniu(0);

    return 0;
}