/* Toate alimentele dintr-un magazin sunt identificate prin cod (1-999), denumire
 *  (20 caractere), unitate de masura, cantitate, pret si data de expirare. Sa se
 *  afiseze pentru fiecare tip de aliment codul, denumirea si valoarea stocului, iar
 *  apoi sa se afiseze alimentele expirate cu toate elementele lor de indentificare.
 * - Data expirarii este o structura cu 3 campuri: zi, luna, an. O variabila cu acest
 *      tip va fi inclusa in structura principala aliment.
 */

#include <stdio.h>
#include <time.h>
#define MAXDEN 20
#define MAX 100

typedef struct ExDate
{
    int zi;
    int luna;
    int an;    
} ExDate;

typedef struct Aliment
{
    int cod;
    char denumire[MAXDEN];
    char unitate_de_masura[MAXDEN];
    int cantitate;
    double pret;
    ExDate data_expirare;
} Aliment;

Aliment vAlimente[MAX];

_Bool CheckCode(int code)
{
    if(code > 999 || code < 1)  return 0;

    return 1;
}

double ComputeStockValue(int size, double pret)
{
    return pret* (double) size;
}

void PrintAlimente(int size)
{
    for(int i=0; i<size; ++i)
    {
        fprintf(stdout, "%d %s %lf", vAlimente[i].cod, vAlimente[i].denumire,
                ComputeStockValue(vAlimente[i].cantitate, vAlimente[i].pret));
    }
}

_Bool CheckIfExp(int day, int month, int year)
{
    time_t today;
    struct tm expDate = {0};
    double seconds;

    expDate.tm_year = year%1000;
    expDate.tm_mon = month-1;
    expDate.tm_mday = day;

    time(&today);

    seconds = difftime(today, mktime(&expDate));

    if(seconds < 0) return 1;
    else            return 0;
}

void PrintExpAlimente(int size)
{
    for(int i=0; i<size; ++i)
    {
        if(CheckIfExp(vAlimente[i].data_expirare.zi, vAlimente[i].data_expirare.luna,
                        vAlimente[i].data_expirare.an))
        {
            fprintf(stdout, "%d %s %s %d %lf %d %d %d", vAlimente[i].cod, vAlimente[i].denumire,
                    vAlimente[i].unitate_de_masura, vAlimente[i].cantitate, vAlimente[i].pret,
                    vAlimente[i].data_expirare.zi, vAlimente[i].data_expirare.luna,
                    vAlimente[i].data_expirare.an);
        }
    }
}

int main(void)
{
    int size;

    printf("Introduceti numarul de alimente dorit: ");
        scanf("%d", &size);

    printf("\nIntroduceti alimentele:\n");
    for(int i=0; i<size; ++i)
    {
        Repeat:printf("(cod denumire unitateDeMasura cantitate pret dataExpirare(zi luna an)):\n");
            fscanf(stdin, "%d %s %s %d %lf %d %d %d", vAlimente[i].cod, vAlimente[i].denumire,
                    vAlimente[i].unitate_de_masura, vAlimente[i].cantitate, vAlimente[i].pret,
                    vAlimente[i].data_expirare.zi, vAlimente[i].data_expirare.luna,
                    vAlimente[i].data_expirare.an);

        if(!CheckCode(vAlimente[i].cod))    goto Repeat;
    }

    PrintAlimente(size);
    PrintExpAlimente(size);

    return 0;
}