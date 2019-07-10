/* Se citesc de la tastatura n numere naturale pe 2 biti, reprezentand datele de
 *  nastere ale unor persoane.
 * Ele sunt codificate astfel 7 biti reprezinta ultimele doua cifre ale anului nasterii,
 *  4 biti luna si 5 ziua.
 * Sa se afiseze datele de nastere din luna mai.
 * Sa se afiseze datele pentru persoanele minore (avand varsta sub 18 ani).
 * Sa se afiseze anul cu cea mai mare natalitate.
 */

#include <stdio.h>
#include <time.h>
#define MAX 30


typedef struct Birthday
{
    unsigned lastTwoDigitsYear  : 7;
    unsigned month              : 4;
    unsigned day                : 5;
} Birthday;

Birthday zileDeNastere[MAX];

void PrintMayDates(int size)
{
    for(int i=0; i<size; ++i)
        if(zileDeNastere[i].month == 5)
            printf("%u %u %u\n", zileDeNastere[i].lastTwoDigitsYear,
                            zileDeNastere[i].month,
                            zileDeNastere[i].day);
}

int FindAge(unsigned lastTwoDigitsYear, unsigned month, unsigned day)
{
    time_t today;
    struct tm birthday = {0};
    double seconds;

    birthday.tm_hour = 0;
    birthday.tm_min = 0;
    birthday.tm_sec = 0;

    if(lastTwoDigitsYear > 19)
        birthday.tm_year = 100 + lastTwoDigitsYear;
    else
        birthday.tm_year = lastTwoDigitsYear;

    birthday.tm_mon = month-1;
    birthday.tm_mday = day;

    time(&today);

    seconds = difftime(today, mktime(&birthday));


    double minutes = seconds / 60;
    double hours = minutes / 60;
    double days = hours / 24;
    int years = (int) days / 365;

    return years;
}

void PrintUnderAged(int size)
{
    for(int i=0; i<size; ++i)
        if(FindAge(zileDeNastere[i].lastTwoDigitsYear, zileDeNastere[i].month,
                    zileDeNastere[i].day) < 18)
            printf("%u %u %u\n", zileDeNastere[i].lastTwoDigitsYear,
                            zileDeNastere[i].month,
                            zileDeNastere[i].day);

}

// void PrintMostBirthsYear(int size)
// {

//     for(int i=0; i<size-1; ++i)
//         for(int j=i+1; j<size; ++j)

// }

int main(void)
{
    int size;

    printf("Introduceti un numar de zile de nastere: ");
        scanf("%d", &size);

    printf("Introduceti zilele de nastere:\n");
    for(int i=0; i<size; ++i)
    {
        printf("(ultimele_2_cifre_ale_anului luna ziua): ");
        scanf("%u %u %u", zileDeNastere[i].lastTwoDigitsYear,
                            zileDeNastere[i].month,
                            zileDeNastere[i].day);
    }

    return 0;
}