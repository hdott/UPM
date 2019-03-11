// O functie care ordoneaza alfabetic n cuvinte citite dintr-un fisier

#include <stdio.h>
#include <string.h>
#define MAXR 1000
#define MAXL 30

void order_words_alphabetically(char lista[][MAXL], int size)
{
    char aux[MAXL];
    for(int i=0; i<size-1; ++i)
        for(int j=i+1; j<size; ++j)
            if(strcmp(lista[i],lista[j]) > 0)
            {
                strcpy(aux,lista[i]);
                strcpy(lista[i],lista[j]);
                strcpy(lista[j],aux);
                puts("error");
            }
}

int main(void)
{
    FILE *file = fopen("myfile.txt","r");
    char *pch, lista[MAXR][MAXL];
    int size = 0;

    // reads all the words within the file and place them into lista[MAXR][MAXL]
    while(!feof(file))  
        fscanf(file, "%s", lista[size++]);
    fclose(file);
    
    order_words_alphabetically(lista,size);

    // writes the words alphabetically ordered in the same file
    file = fopen("myfile.txt", "w");
        for(int i=0; i<size; ++i)
            fprintf(file, "%s\n", lista[i]);
    fclose(file);

    return 0;
}