/* Fie orarul specializarii Informatica anul 1.
 * Datele nu se citesc de la tastatura, ci se dau in program prin initializare.
 * Se creeaza lista disciplinelor: 
 *  char discipline [14][100];
 * Orarul va fi reprezentat sub forma unei matrice astfel:
 *  Orele de luni se dau prin initializare unsigned short orar [5][12] = 
 *      {0, 0, 0, 1, 1, 3, 3}, {-1, 4, 4, 4, 5, 5, -1, -1, 6, 6};
 * -1 reprezinta fereastra in orar.
 * Zilele saptamanii se vor defini prin enum.
 * Cerinte:
 * - Sa se afiseze cea mai usoara si cea mai grea zi a studentilor (ziua se va afisa
 *      in litere- switch case);
 * - Sa se afiseze pentru fiecare zi numarul de ferestre
 * - Sa se afiseze ziua cu cele mai multe ferestre
 */

#include <stdio.h>
#define MAXNR 14
#define MAXL 100


char discipline[MAXNR][MAXL] = {"Programare Orientata pe Obiect (lab)",
                                "Programare Orientata pe Obiect (Curs)",
                                "Algebra si Geometrie Analitica (seminar)",
                                "Algebra si Geometrie Analitica (Curs)",
                                "Structuri de Date (lab)",
                                "Stricturi de Date (Curs)",
                                "Metode Avansate de Programare (lab)",
                                "Metode Avansate de Programare (Curs)",
                                "Pedagogie I (seminar)",
                                "Pedagogie I (Curs)",
                                "Educatie Fizica",
                                "Engleza"};


enum zi {Luni, Marti, Miercuri, Joi, Vineri};

char zile[5][40] = {"Luni", "Marti", "Miercuri", "Joi", "Vineri"};

unsigned short orar[5][12] =   {{-1, -1, -1, -1, 2, 0},
                                {5, 7, 6, 9, 8},
                                {3, 4},
                                {1},
                                {-1, -1, -1, -1, 11, 10}};
                                
void PrintDay(char *string, short day)
{
    printf(" -> %s\n", string, zile[day]);
}

void PrintFerestre()
{
    int count;
    
    for(int i=0; i<5; ++i)
    {
        count = 0;
        for(int j=0; j<12; ++j)
            if(orar[i][j] == -1)    count++;
        
        printf("%s -> %d\n", zile[i], count);
    }
}

int main(void)
{
    PrintDay("Cea mai usoara zi a Studentilor este ", 3);
    puts("");
    PrintFerestre();
    puts("");
    PrintDay("Ziua cu cele mai multe ferestre este ", 0);

    return 0;
}