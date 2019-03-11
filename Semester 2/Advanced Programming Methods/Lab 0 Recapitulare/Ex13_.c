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
#include <stdlib.h>
#define MAX 30
#define PERCENT 100

typedef struct angajat
{
    char nume[MAX], prenume[MAX];
    unsigned salariu;
} employee;

void readData_fromFile(FILE *file, employee *list, int elem)
{
    for(int i=0; i<elem; ++i)
        fscanf(file, "%s %s %u", list[i].nume, list[i].prenume, 
                &list[i].salariu);
}

void printData(employee *list, int elem)
{
    printf("Datele citite sunt:\n");

    for(int i=0; i<elem; ++i)
        printf("%s %s %d\n", list[i].nume, list[i].prenume,
                list[i].salariu);
}

double MeanAverageSalary(employee *list, int elem)
{
    double meanAverage=0;

    for(int i=0; i<elem; ++i)
        meanAverage += (double)list[i].salariu;

    return (meanAverage/(double) elem);
}

void DecreaseSalaryByPercent(employee *list, int elem, int percent)
{
    for(int i=0; i<elem; ++i)
    {
        list[i].salariu *= (PERCENT-percent);
        list[i].salariu /= PERCENT;
    }
}

int main(void)
{
    int elem;
    double averageBefore, averageAfter;

    FILE *file = fopen("mytext.txt", "r");
    fscanf(file, "%d", &elem);

    employee *list = (employee*) malloc(elem*sizeof(employee));

    readData_fromFile(file,list,elem);
    printData(list,elem);

    averageBefore = MeanAverageSalary(list,elem);
    DecreaseSalaryByPercent(list,elem,25);
    averageAfter = MeanAverageSalary(list,elem);

    printf("\nAverageBefore = %.2lf\n", averageBefore);
    printf("AverageAfter = %.2lf\n", averageAfter);
    printf("Difference in percent = %.2lf\%\n", 
            PERCENT-(averageAfter*PERCENT/averageBefore));

    free(list);
    fclose(file);
    return 0;
}