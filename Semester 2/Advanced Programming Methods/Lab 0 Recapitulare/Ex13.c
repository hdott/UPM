/*
 * Se considera urmatorul tip definit de utilizator:
 *  typedef struct angajat{
 *  char nume[30], prenume[30];
 *  unsigned salariu;
 *  };
 *  a. Sa se citeasca dintr-un fisier urmatoarele date:
 *      - 4(numarul elementelor)
 *      - Popescu Andrei 1000
 *      - Ionescu Alexandru 800
 *      - Constantinescu Mircea 1500
 *      - Stefanescu Ion 1200
 *  b. Sa se afiseze datele citite
 *  c. Sa se diminueze cu 25% salariul fiecarui angajat;
 *  d. Sa se calculeze media aritmetica a salariilor inainte si dupa diminuare. Sa se
 *      exprime diferenta intre cele doua in procente.
 */

#include <stdio.h>
#include <string.h>
#define MAX 30
#define ROWL 10
#define PERCENT 100

typedef struct angajat
{
    char nume[MAX], prenume[MAX];
    unsigned salariu;
} employee;

void readData_fromFile(FILE *file, char nume[ROWL][MAX], char prenume[ROWL][MAX],
                        int salariu[], int elem)
{
    employee angajat;
    for(int i=0; i<elem; ++i)
    {
        fscanf(file, "%s %s %d", angajat.nume, angajat.prenume, &angajat.salariu);
        strcpy(nume[i],angajat.nume);
        strcpy(prenume[i],angajat.prenume);
        salariu[i] = angajat.salariu;
    }
}

void printData(char nume[ROWL][MAX], char prenume[ROWL][MAX], int salariu[ROWL],
                int elem)
{
    printf("Datele citite sunt:\n");

    for(int i=0; i<elem; ++i)
        printf("%s %s %d\n", nume[i], prenume[i], salariu[i]);
}

double MeanAverageSalary(int salariu[], int elem)
{
    double meanAverage=0;

    for(int i=0; i<elem; ++i)
        meanAverage += (double)salariu[i];

    return (meanAverage/(double) elem);
}

void DecreaseSalaryByPercent(int salariu[], int elem, int percent)
{
    for(int i=0; i<elem; ++i)
    {
        salariu[i] *= (PERCENT-percent);
        salariu[i] /= PERCENT;
    }
}

int main(void)
{
    char nume[ROWL][MAX], prenume[ROWL][MAX];
    int salariu[ROWL], elem;
    double averageBefore, averageAfter;

    FILE *file = fopen("mytext.txt", "r");
    fscanf(file, "%d", &elem);

    readData_fromFile(file,nume,prenume,salariu,elem);
    printData(nume,prenume,salariu,elem);

    averageBefore = MeanAverageSalary(salariu,elem);
    DecreaseSalaryByPercent(salariu,elem,25);
    averageAfter = MeanAverageSalary(salariu,elem);

    printf("\nAverageBefore = %lf.2\n", averageBefore);
    printf("AverageAfter = %.2lf\n", averageAfter);
    printf("Difference in percent = %.2lf\%\n", 
            PERCENT-(averageAfter*PERCENT/averageBefore));


    fclose(file);
    return 0;
}