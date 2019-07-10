#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 81

void gen_col(char **M, int row, int col)
{
    for(int i=0; i<row; ++i)
        M[i] = (char*) malloc(col*sizeof(char));
}

void freeM(char **M, int row)
{
    for(int i = 0; i<row; ++i)
        free(M[i]);
    free(M);
}

void read_sir(char **M, int row, int col)
{
    gen_col(M,row,col);
    for(int i=0; i<row; ++i)
        printf("S[%d]\t",i),fgets(M[i],MAXLEN,stdin);
}

void checkif_present(char word[], char **M, int row, int col, int length)
{
    // 1st if cauta cuvantul intr-un string
    // 2nd if verifica daca caracterul anterior a fost spatiu sau daca este primul din string
    // 3rd if verifica daca urmatorul caracter este spatiu sau newline (ulltimul din string)
    for(int j=0; j<strlen(M[row])-length; ++j)
        if(!strncmp((*(M+row)+j),word,length))
            if(M[row][j-1] == ' ' || !j)
                if(M[row][length+j] == ' ' || M[row][length+j] == '\n') 
                    printf("row[%d]\t\"%s\"\tpoz[%2d]\n",row,word,j);
}

void main()
{
    int size;
    puts("Introduceti numarul de linii");
        printf("size = "),scanf("%d",&size);
        getchar();                              //takes the extra \n

    char **sir = (char**)calloc(size,sizeof(char*));
    read_sir(sir,size,MAXLEN);
        printf("\n");

    char word[MAXLEN];
    puts("Introduceti un cuvant");
        printf("word = "),scanf("%81s",word),printf("\n");

    for(int i=0; i<strlen(word); ++i)
        if(word[i] == '\n')
            word[i] = '\0';

    for(int i=0; i<size; ++i)
        checkif_present(word,sir,i,MAXLEN,strlen(word));

    freeM(sir,size);
}
