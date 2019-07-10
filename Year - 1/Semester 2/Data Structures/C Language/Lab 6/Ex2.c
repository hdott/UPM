/* Se considera un meniu principal ce contine doua optiuni:
 * - Operatii de baza
 * - Operatii extinse
 * 1. Operatii de baza
 * Sa se afiseze un meniu ce contine doua optiuni corespunzatoare tipului de coada
 *  implementata:
 * - Coada - implementare statica
 * - Coada - implementare dinamica
 * Din selectarea oricarei optiuni se va afisa meniul ce permite selectarea urmatoarelor
 *  optiuni:
 * - Enqueue (Adaugare)
 * - Dequeue (Extragere cu afisarea elementului extra)
 * - Clear (cu afisarea elementelor sterse)
 * Informatia utila corespunzatoare fiecarui element va fi formata din:
 * - Nume
 * - Prenume
 * - Serie buletin
 * 2. Operatii extinse
 * Sa se implementeze un simulator al problemei producator-consumator cu stocarea
 *  unor date binare corespunzatoare unor imagini ce asteapta a fi procesate.
 * Imaginile sunt simulate prin bufere de dimensiuni aleatoare ale caror octeti
 *  sunt initializati cu valori aleatoare.
 * Sa se afiseze un meniu ce contine doua optiuni corespunzatoare tipului de coada
 *  implementata:
 * - Coada - implementare statica
 * - Coada - implementare dinamica cu LSI si LDI
 * Din selectarea oricarei optiuni se va afisa meniul ce permite selectarea urmatoarelor:
 *  operatii:
 * - Enqueue
 * - Dequeue (cu afisarea si verificarea sumei de control)
 * - Clear (cu afisarea sumei de control)
 * Informatia utila corespunzatoare fiecarui element va fi formata din:
 * - Numarul de octeti al imaginii (numarul minim de octeti: 10KO, numarul maxim: 100KO)
 * - Pointer catre secventa de octeti alocata dinamic si initializata cu valori aleatoare
 * - Suma de control calculata prin adunarea valorii octetilor (se va utiliza un numar
 *      pe 64 de biti: __int64).
 */

#include <stdio.h>
#include "meniu.h"


int main(void)
{
    ControlMeniu(0, 0);    

    return 0;
}