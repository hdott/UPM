/*
 * Sa se scrie un subprogram care returneaza numarul de vocale continute de
 *  un  sir primit ca parametru. Afisarea se va face in programul principal.
 * Sa se apeleze aceasta functie de 3 ori cu diferite siruri. (Sirurile vor 
 *  fi citite de la tastatura)
 */

#include <stdio.h>
#include <string.h>
#define REPETITII 3
#define MAX 80

int count_vowels(char s[]); // function prototype

int main(void)
{
    char s[MAX];

    for(int i=0; i<REPETITII; ++i)
    {
        printf("Introduceti un sir de caractere / propozitie:\n");
            fgets(s,MAX,stdin);
        printf("Propozitia are %d vocale.\n\n",count_vowels(s));
    }

    return 0;
}

// counts vowels in a string
int count_vowels(char s[])
{
    static char vowels[] = {'a','e','i','o','u','A','E','I','O','U'};
    int sum=0;

    for(int i=0; i<strlen(s); ++i)
        for(int j=0; j<sizeof(vowels); ++j)
            if(s[i] == vowels[j])
            {
                sum++;
                break;
            }

    return sum;
}