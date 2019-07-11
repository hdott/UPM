/*
 * Sa se implementeze urmatoarele operatii de baza ce pot fi selectate prin
 *  intermediul unui meniu principal si mai multe sub-meniuri.
 * - Adaugare
 *      - La inceput
 *      - La sfarsit
 *      - Inaintea unui element identificat prin nume(cheie)
 *      - Dupa un element identificat prin nume(cheie)
 * - Stergerea
 *      - Primului
 *      - Ultimului
 *      - Unui element identificat prin nume si prenume(cheie)
 * - Cautare
 *      - Dupa nume(cheie)
 *      - Dupa prenume(cheie)
 *      - Dupa varsta(cheie)
 * - Afisare
 * - Distrugere
 * Sa se adauge optiunea "Operatii extinse" la meniul principal ce va permite
 *  urmatoarele:
 * - Crearea unei liste de list pornind de la lista deja creata prin intermediul
 *      meniului precedent
 * - Fiecare element al listei principale va contine:
 *      - Nume
 *      - Adresa primului element din lista atasata(secundara)
 *      - Adresa urmatorului element din lista principala
 * - Operatiile ce trebuie implementate:
 *      - Determinarea persoanei cu varsta cea mai mare(pentru un nume dat)
 *      - Determinarea numelui ce apare cel mai frecvent
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#define MAX 100



int main(void)
{
    menu(0);

    return 0;
}