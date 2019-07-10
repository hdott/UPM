/*
Se citesc doua texte de la tastatura.
Sa se scrie un program care afiseaza toate cuvintele comune din cele doua teste.
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 81

void checkif_present(char *word, char string[], int length)
{
    // 1st if cauta cuvantul intr-un string
    // 2nd if verifica daca caracterul anterior a fost spatiu sau daca este primul din string
    // 3rd if verifica daca urmatorul caracter este spatiu sau newline (ulltimul din string)
    for(int i=0; i<strlen(string)-length; ++i)
        if(!strncmp(string+i,word,length))
            if(*(string+(i-1)) == ' ' || !i)
                if(*(string+(length+i)) == ' ' ||*(string+(length+i)) == '\n') 
                    puts(word);
}

void main()
{
    char string1[MAXLEN], string2[MAXLEN];
    
    puts("Introduceti Textul_1:");
        fgets(string1,MAXLEN,stdin);
    puts("Introduceti Textul_2:");
        fgets(string2,MAXLEN,stdin);

    printf("\nCuvintele din Textul_1 regasite in Textul_2 sunt:\n");

    char *pstring = strtok(string1," ,.!?/+-\n");
    while(pstring)
    {
        checkif_present(pstring,string2,strlen(pstring));

        pstring = strtok(NULL," ,.!?/+-\n");
    }
}
