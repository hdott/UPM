/*
 * Sa se scrie un program care citeste toate numerele intregi dintr-un fisier text
 *  si stocheaza suma si produsul numerelor respectiv sirul lor ordonat crescator
 *  intr-un fisier text de iesire.
 */

#include <stdio.h>
#include <stdlib.h>

int countElements(FILE *file)
{
    int count=0, temp_nr;

    if(file)
    {
        while(!feof(file))
        {
            fscanf(file,"%d",&temp_nr);
            count++;
        }
    }

    return count;
}

int sortVector(int *vector, int size)
{
    for(int i=0; i<size-1; ++i)
        for(int j=i+1; j<size; ++j)
            if(*(vector+i) > *(vector+j))
            {
                int aux = *(vector+i);
                *(vector+i) = *(vector+j);
                *(vector+j) = aux;
            }
}

int main(void)
{
    long unsigned suma=0;
    long long unsigned produs=1;
    int size;

    FILE *file = fopen("myfile.txt","r");
        size = countElements(file)-1;
    fclose(file);
    int *vector = (int*) malloc(size*sizeof(int));

    file = fopen("myfile.txt", "r");

    if(file)
    {
        for(int i=0; i<size || !feof(file); ++i)
        {
            fscanf(file,"%d",&(*(vector+(i))));
            
            if(*(vector+i))
            {
                suma += *(vector+i);
                produs *= *(vector+i);
            }
        }
    }
    fclose(file);

    sortVector(vector,size);
    file = fopen("newfile.txt", "w");

    if(file)
    {
        fprintf(file, "suma = %lu\n", suma);
        fprintf(file, "produs = %llu\n", produs);
        fprintf(file, "Vectorul este: ");
            for(int i=0; i<size; ++i)
                fprintf(file, "%d ", *(vector+i));
        fputs("", file);
    }
    fclose(file);

    free(vector);
    return 0;
}