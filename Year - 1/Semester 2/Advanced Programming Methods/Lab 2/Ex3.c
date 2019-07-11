/* Sa se creeze un progrm care citeste de la tastatura informatii despre n persoane,
 *  apoi le afiseaza in ordine alfabetica (nume+prenume) si in ordinea descrescatoare
 *  a varstei (Varsta se obtine din CNP). Se va declara un vector de structura astfel:
 * struct persoana{
 * char CNP[14];
 * char nume[50];
 * char prenume[50];
 * char locnastere[100];
 * char domiciliu[100];
 * };
 * persoana vpers[100];
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define MAX_CNP 14
#define MAX_NUME 50
#define MAX 100
#define ASCIINR 48


typedef struct persoana
{
    char CNP[MAX_CNP];
    char nume[MAX_NUME];
    char prenume[MAX_NUME];
    char locnastere[MAX];
    char domiciliu[MAX];
} persoana;

persoana vpers[MAX];

void SortVector(int size)
{
    for(int i=0; i<size-1; ++i)
        for(int j=i+1; j<size; ++j)
        {
            if(strcmp(vpers[i].nume, vpers[j].nume) > 0)
            {
                persoana temp = vpers[i];
                vpers[i] = vpers[j];
                vpers[j] = temp;
                continue;
            }

            if(strcmp(vpers[i].prenume, vpers[j].prenume) > 0)
            {
                persoana temp = vpers[i];
                vpers[i] = vpers[j];
                vpers[j] = temp;
            }
        }
}

void PrintVector(int size)
{
    for(int i=0; i<size; ++i)
        printf("%s %s %s %s %s\n", vpers[i].CNP, vpers[i].nume, vpers[i].prenume,
                                vpers[i].locnastere, vpers[i].domiciliu);
}

int FindAge(char *cnp)
{
    time_t timer;
    struct tm year = {0};
    double seconds;

    year.tm_hour = 0;
    year.tm_min = 0;
    year.tm_sec = 0;
    
    if(cnp[0] == 5 || cnp[0] == 6)
        year.tm_year = 100 + (cnp[1]-ASCIINR)*10 + (cnp[2]-ASCIINR);
    else if(cnp[0] == 1 || cnp[0] == 2)
        year.tm_year = (cnp[1]-ASCIINR)*10 + (cnp[2]-ASCIINR);
    
    year.tm_mon = (cnp[3]-ASCIINR)*10 + (cnp[4]-ASCIINR) - 1;
    year.tm_mday = (cnp[5]-ASCIINR)*10 + (cnp[6]-ASCIINR);

    time(&timer);

    seconds = difftime(timer, mktime(&year));


    double minutes = seconds / 60;
    double hours = minutes / 60;
    double days = hours / 24;
    int years = (int) days / 365;

    return years;
}

void SortVectorByAge(int size)
{
    for(int i=0; i<size-1; ++i)
        for(int j=i+1; j<size; ++j)
        {
            if(FindAge(vpers[i].CNP) < FindAge(vpers[j].CNP))
            {
                persoana temp = vpers[i];
                vpers[i] = vpers[j];
                vpers[j] = temp;
            }
        }
}

void PrintVectorAndAge(int size)
{
    for(int i=0; i<size; ++i)
        printf("%s %s %s %s %s %d\n", vpers[i].CNP, vpers[i].nume, vpers[i].prenume,
                                vpers[i].locnastere, vpers[i].domiciliu,
                                FindAge(vpers[i].CNP));
}

int main(void)
{
    int size;

    printf("Introduceti un numar de elemente al vectorului: ");
        scanf("%d", &size);

    printf("\nIntroduceti elementele vectorlui in forma:\n");
    for(int i=0; i<size; ++i)
    {
        printf("(CNP nume prenume locnastere domiciliu): ");
        scanf("%s %s %s %s %s", vpers[i].CNP, vpers[i].nume, vpers[i].prenume,
                                vpers[i].locnastere, vpers[i].domiciliu);
    }

    SortVector(size);
    PrintVector(size);

    SortVectorByAge(size);
    PrintVectorAndAge(size);
    

    return 0;
}