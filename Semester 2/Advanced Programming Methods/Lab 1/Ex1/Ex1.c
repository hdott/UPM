/*
 * Sa se copieze un fisier text
 *  - caracter cu caracter
 *  - linie cu linie
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(void)
{
    FILE *pFile1 = fopen("myfile.txt","r");
    FILE *pFile2 = fopen("newfile1.txt","w");
    FILE *pFile3 = fopen("newfile2.txt","w");
    char c, *line;
    line = (char*) malloc(MAX*sizeof(char));

    // copies character with character the content of myfile.txt
    if(pFile1)
        while((c=fgetc(pFile1)) != EOF)
            fputc(c,pFile2);
    else puts("ERROR");

    fclose(pFile1);
    fclose(pFile2);

    // copies line with line the content of myfile.txt
    if(pFile1 = fopen("myfile.txt","r"))
        while(!feof(pFile1))
        {
            fgets(line,MAX,pFile1);
            fputs(line,pFile3);
        }

    fclose(pFile1);
    fclose(pFile3);

    free(line);
    return 0;
}