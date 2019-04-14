/* Sa se creeze un program care citeste dintr-un fisier informatii despre n persoane,
 *  apoi le afiseaza in ordine alfabetica (nume+prenume) si in ordine descrescatoare
 *  a varstei (Varsta se obtine din CNP).
 * Ordonarea sa fie facuta cu ajutorul functiei predefininte qsort.
 * Se va declara un vector de structura, astfel:
 * struct persoana{
 * char CNP[13];
 * char nume[50];
 * char prenume[50];
 * char locnastere[100];
 * char domiciliu[100];
 * };
 * persoana vpers[100];
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CNP 14
#define MAX_NUME 50
#define MAX_LOC 100
#define ASCIINR 48

typedef struct persoana
{
    char CNP[MAX_CNP];
    char nume[MAX_NUME];
    char prenume[MAX_NUME];
    char locnastere[MAX_LOC];
    char domiciliu[MAX_LOC];
} PERSON;

PERSON vpers[MAX_LOC];

int CompareNumePrenume(const void *a, const void *b)
{
    PERSON *pa = (PERSON*) a;
    PERSON *pb = (PERSON*) b;
    
    if(strcmp(pa -> nume, pb -> nume) < 0)    return -1;

    if(strcmp(pa -> nume, pb -> nume) > 0)    return 1;

    if(strcmp(pa -> nume, pb -> nume) == 0)   
        return strcmp(pa -> prenume, pb -> prenume);
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

void PrintList(int size)
{
    for(int i=0; i<size; ++i)
    {
        printf("CNP         -> %s\n", vpers[i].CNP);
        printf("nume        -> %s\n", vpers[i].nume);
        printf("prenume     -> %s\n", vpers[i].prenume);
        printf("locnastere  -> %s\n", vpers[i].locnastere);
        printf("domiciliu   -> %s\n", vpers[i].domiciliu);
    }
}

int CompareAge(const void *a, const void *b)
{
    PERSON *pa = (PERSON*) a;
    PERSON *pb = (PERSON*) b;

    return (FindAge(pa -> CNP) - FindAge(pb -> CNP));
}

int main(void)
{
    FILE *file = fopen("myfile.txt", "r");

    int index=-1;
    while(!feof(file))
    {
        ++index;
        fscanf(file, "%s%s%s%s%s", vpers[index].CNP, vpers[index].nume,
                                vpers[index].prenume, vpers[index].locnastere,
                                vpers[index].domiciliu);
    }

    qsort(vpers, index, sizeof(PERSON), CompareNumePrenume);
    PrintList(index);

    qsort(vpers, index, sizeof(PERSON), CompareAge);
    PrintList(index);

    fclose(file);
    return 0;
}