/* Luand in considerare exercitiile 6,7,8 sa se scrie un program care poate sa
 *  contina argumente optionale: -c -l -p
 * -c afiseaza numarul de cuvinte
 * -l afiseaza lungimea propozitiilor
 * -p afiseaza numarul propozitiilor
 */

#include <stdio.h>
#include <string.h>


typedef struct present
{
    _Bool presentC;
    _Bool presentL;
    _Bool presentP;
} PRESENT;

int ArgumenteIdentice(int argc, char* argv[])
{
    int count = 1;
    char *s = argv[0];

    for(int i=1; i<argc; ++i)
        if(!strcmp(s, argv[i])) ++count;
    
    printf("Argumente identice cu primul -> %d\n", count);

    return 0;
}

int LungimeaSirului(int argc, char* argv[])
{
    long size = 0;

    for(int i=0; i<argc; ++i)
        size += strlen(argv[i]);

    printf("Lungimea sirului de caractere -> %ld\n", size);

    return 0;
}

_Bool isSeparator(char ch)
{
    return (ch == '.') || (ch == '!') || (ch == '?');
}

int NumarPropozitii(int argc, char* argv[])
{
    int sentences = 0;

    for(int i=0; i<argc; ++i)
        for(int j=0; j<strlen(argv[i]); ++j)
            if(isSeparator(argv[i][j])) ++sentences;

    printf("Numarul de propozitii introduse in linia de comanda -> %d\n", sentences);
}

int isOptional(char *arg)
{
    if(!strcmp(arg, "-c"))  return 1;
    if(!strcmp(arg, "-l"))  return 2;
    if(!strcmp(arg, "-p"))  return 3;

    return 0;
}

int main(int argc, char* argv[])
{
    PRESENT ToBeExecuted;

    int i;
    for(i=1; i<argc; ++i)
    {
        switch (isOptional(argv[i]))
        {
            case 1:
                ToBeExecuted.presentC = 1;
                break;
            case 2:
                ToBeExecuted.presentL = 1;
                break;
            case 3:
                ToBeExecuted.presentP = 1;
                break;
            default:
                goto OutOfSwitch;
                break;
        }
    }

    OutOfSwitch:
    if(ToBeExecuted.presentC)   ArgumenteIdentice(argc-i, argv+i);
    if(ToBeExecuted.presentL)   LungimeaSirului(argc-i, argv+i);
    if(ToBeExecuted.presentP)   NumarPropozitii(argc-i, argv+i);

    return 0;
}