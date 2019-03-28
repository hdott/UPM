/* Se considera un meniu principal ce contine doua optiuni:
 * - Operatii de baza
 * - Operatii extinse
 * 1. Operatii de baza
 * Sa se afiseze un meniu ce contine doua optiuni corespunzatoare tipului de stiva
 *  implementata:
 * - Stiva statica uzuala
 * - Stiva statica extensibila
 * Din selectarea oricarei optiuni se va afisa meniul ce permite construirea stivei:
 * - push (adaugare)
 * - pop (scoaterea elementului cu afisarea elementelor)
 * - clear (cu afisarea elementelor)
 * Ambele tipuri de stiva vor contine numere naturale!
 * 2. Operatii extinse
 * Sa se afiseze un meniu ce contine doua optiuni corespunzatoare tipului de stiva
 *  implementata:
 * - Stiva statica uzuala
 * - Stiva statica extensibila
 * Din selectarea oricarei optiuni se va afisa meniul ce permite construirea a doua
 *  stive:
 * - push1
 * - push2
 * - pop1 (cu afisarea elementelor)
 * - pop2 (cu afisarea elementelor)
 * - clear1 (cu afisarea elementelor)
 * - clear2 (cu afisarea elementelor)
 * - Generare stiva3
 * - pop3  (cu afisarea elementelor) - pentru stiva3
 * - clear3 (cu afisarea elementelor) - pentru stiva3
 * Stiva 1 va contine: cod produs si cantitate
 * Stiva 2 va contine: cod produs si pret
 * La selectarea operatiei "Generare stiva3" se va construi automat o a treia stiva
 *  pe baza stivelor 1 si 2 (prin apelul succesiv al functiei "pop" aplicata asupra
 *  celor doua stive). Se considera ca elementele stivelor 1 si 2 sunt sortate dupa
 *  cod (la introducere).
 * Fiecare element al stivei 3 va contine: cod produs, cantitate si pret.
 * Daca un cod produs nu se regaseste in stiva pereche, campul corespunzator se va
 *  completa cu -1.
 */

#include <stdio.h>
#include "meniu.h"

int main(void)
{
    MeniuPrincipal(0, 0);

    return 0;
}