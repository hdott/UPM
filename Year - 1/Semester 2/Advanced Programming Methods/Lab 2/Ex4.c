/* Sa se creeze un program care citeste de la tastatura n studenti si pentru fiecare
 *  k discipline cu notele corespunzatoare. Sa se afiseze studentii in ordinea
 *  descrescatoare mediei lor. (Media este media aritmetica a tuturor notelor unui
 *  student).
 * struct Disciplina{
 * char denumire[100];
 * int note;
 * };
 * struct Student{
 * char nume[50];
 * char prenume[40];
 * Disciplina d[10];
 * float medie;
 * };
 * Student vectorStud[30];
 */

#include <stdio.h>
#define MAXD 100
#define MAXN 50
#define MAXP 40
#define MAXDV 10
#define MAXVS 30


typedef struct Disciplina
{
    char denumire[MAXD];
    int note;
} Disciplina;

typedef struct Student
{
    char nume[MAXN];
    char prenume[MAXP];
    Disciplina d[MAXDV];
    float medie;
} Student;

Student vectorStud[MAXVS];

float FindAverage(int index, int size)
{
    float tempAverage = 0;

    for(int i=0; i<size; ++i)
        tempAverage += (float) vectorStud[index].d[i].note;

    return tempAverage/size;
}

int main(void)
{
    int n, k;

    printf("Introduceti un numar de studenti:\n");
        printf("n = ");
        scanf("%d", &n);

    printf("\nIntroduceti un numar de discipline:\n");
        printf("k = ");
        scanf("%d", &k);

    printf("\nIntroduceti studentii:\n");

    for(int i=0; i<n; ++i)
    {
        printf("(nume prenume): ");
        fscanf(stdin, "%s %s", vectorStud[i].nume, vectorStud[i].prenume);
        
        for(int j=0; j<k; ++j)
        {
            printf("(disciplina nota): ");
            fscanf(stdin, "%s %d", vectorStud[i].d[j].denumire,
                                vectorStud[i].d[j].note);
        }

        vectorStud[i].medie = FindAverage(i, k);
    }

    return 0;
}