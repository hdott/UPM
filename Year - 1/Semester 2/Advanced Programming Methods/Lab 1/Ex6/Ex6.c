/*
 * Sa se scrie un program care concateneaza continutul unui fisier (fisier1.txt)
 *  dupa un alt fisier (fisier2.txt).
 * Obs: Al doilea fisier se deschide cu a.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void)
{
    char *input_string = (char*) malloc(MAX);

    FILE *file1 = fopen("fisier1.txt", "r");
    FILE *file2 = fopen("fisier2.txt", "a");

    if(file1 && file2)
    {
        while(!feof(file1))
        {
            fscanf(file1,"%s",input_string);
            fprintf(file2,"%s\n",input_string);
        }
    }

    fclose(file1);
    fclose(file2);
    free(input_string);
    return 0;
}