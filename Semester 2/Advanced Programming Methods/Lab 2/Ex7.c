/* Se doreste creearea unei liste cu rezultatele sesiunii de examene pentru o grupa cu
 *  un numar de 30 de studenti. Pentru verificarea corectitudinii informatiilor,
 *  memorate, programul trebuie sa contina si afisarea listei. Se presupune ca un
 *  student, la sfarsitul sesiunii, poate fi intr-una din situatiile urmatoare:
 * - a luat toate examenele si i s-a putut incheia o medie pe sesiune;
 * - a luat toate examenele (sa presupunem ca acestea sunt in numar de cinci), dar
 *      nu este incheiata media;
 * - a picat cel putin un examen.
 */

#include <stdio.h>
#include <string.h>
#define MAXN 5
#define MAXNP 50
#define MAXD 30


typedef struct listaDiscipline
{
    char disciplina[MAXN][MAXD];
} listaDiscipline;

listaDiscipline *discipline = NULL;

// tip {m-medie, e-note, r-listaD}
typedef struct catalog
{
    char npr[MAXNP];
    char tip;
    union
    {
        float medie;
        int note[MAXN];
        listaDiscipline *listaD;
    };
} catalog;

catalog stud[MAXD];

// int note[MAXN];

// int medie;


int main(void)
{
    printf("Introduceti datele studentului:\n");
    for(int i=0; i<MAXD; ++i)
    {
        char nume[MAXD], prenume[MAXD];

        printf("(nume prenume): ");
        scanf("%s %s", nume, prenume);
        strcpy(stud[i].npr, nume);
        strcat(stud[i].npr, ", ");
        strcat(stud[i].npr, prenume);
        
        stud[i].listaD = discipline;
        
        printf("(tip)");
        scanf("%c", &stud[i].tip);

        switch (stud[i].tip)
        {
            case 'm':
                printf("(medie): ");
                scanf("%f", &stud[i].medie);
                break;
            case 'e':
                printf("(note): ");
                scanf("%d %d %d %d %d", stud[i].note[0],
                                        stud[i].note[1],
                                        stud[i].note[2],
                                        stud[i].note[3],
                                        stud[i].note[4]);
                break;
            case 'r':
                printf("(discipline): ");
                scanf("%s %s %s %s %s", stud[i].listaD -> disciplina[0],
                                        stud[i].listaD -> disciplina[1],
                                        stud[i].listaD -> disciplina[2],
                                        stud[i].listaD -> disciplina[3],
                                        stud[i].listaD -> disciplina[4]);
                break;
            default:
                puts("wtf");
                break;
        }
        
        printf("%s ", stud[i].npr);
        printf("%c ", stud[i].tip);
        switch (stud[i].tip)
        {
            case 'm':
                printf("%f ", stud[i].medie);
                break;
            case 'e':
                printf("%d %d %d %d %d ",   stud[i].note[0],
                                            stud[i].note[1],
                                            stud[i].note[2],
                                            stud[i].note[3],
                                            stud[i].note[4]);
                break;
            case 'r':
                scanf("%s %s %s %s %s ",    stud[i].listaD -> disciplina[0],
                                            stud[i].listaD -> disciplina[1],
                                            stud[i].listaD -> disciplina[2],
                                            stud[i].listaD -> disciplina[3],
                                            stud[i].listaD -> disciplina[4]);
                break;
            default:
                puts("wtf");
                break;
        }
    }

    return 0;
}