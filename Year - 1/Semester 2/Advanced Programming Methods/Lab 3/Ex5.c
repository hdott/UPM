/* Sa se implementeze functia myprintf si myscanf, care functioneaza la fel ca
 *  printf si scanf din C.
 */

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#define MAX 30
#define MAXL 200

char string[MAX];

char *NumberToString(const void *nr, const char *type)
{
    strcpy(string, "");

    if(!strcmp(type, "int") || !strcmp(type, "long int") || !strcmp(type, "long long int") ||
        !strcmp(type, "short"))
    {
        int a = *(int *)nr;
        int index=-1;
        char _aux[MAX];
        _Bool negative = 0;

        if(a < 0)
        {
            a = abs(a);
            negative = 1;
        }

        while((a/10) || (a%10))
        {
            _aux[++index] = (a%10) + '0';
            a /= 10;
        }

        if(negative)    _aux[++index] = '-';

        int i=0, j=index;
        for(i=0; i<=index; ++i, --j)    string[i]=_aux[j];
        string[i] = '\0';

        return string;
    }

    if(!strcmp(type, "unsigned") || !strcmp(type, "unsigned short") ||
        !strcmp(type, "unsigned long") || !strcmp(type, "unsigned long long"))
    {
        unsigned a = *(unsigned *)nr;
        int index=-1;
        char _aux[MAX];

        while((a/10) || (a%10))
        {
            _aux[++index] = a%10 + '0';
            a /= 10;
        }

        int i=0, j=index;
        for(i=0; i<=index; ++i, --j)    string[i]=_aux[j];
        string[i] = '\0';

        return string;
    }

    if(!strcmp(type, "float") || !strcmp(type, "double"))
    {
        double a = *(double *)nr;
        int index = -1;
        char _aux[MAX];

        int parteIntreaga = (int) a;
        double _auxNr = a - (int) a;
        int sizeParteFractionara = 10;
        long long int parteFractionara = 1;

        for(int i=0; i<sizeParteFractionara; ++i)
            parteFractionara *= 10;

        parteFractionara = (int) (parteFractionara * _auxNr);

        while((parteFractionara/10) || (parteFractionara%10))
        {
            _aux[++index] = parteFractionara%10 + '0';
            parteFractionara /= 10;
        }
        _aux[++index] = '.';
        while((parteIntreaga/10) || (parteIntreaga%10))
        {
            _aux[++index] = parteIntreaga%10 + '0';
            parteIntreaga /= 10;
        }

        int i=0, j=index;
        for(i=0; i<=index; ++i, --j)    string[i]=_aux[j];
        string[i] = '\0';

        return string;
    }
}

int ReturnType(const char *type)
{
    if(type[0] == 'd')          return 1;   //int

    if(type[0] == 'u')          return 2;   //unsigned

    if(type[0] == 'f')          return 3;   //float

    if(type[0] == 'l')
    {
        if(type[1] == 'd')      return 4;   //long int

        if(type[1] == 'u')      return 5;   //unsigned long

        if(type[1] == 'f')      return 6;   //double

        if(type[1] == 'l')
        {
            if(type[2] == 'd')  return 7;   //long long int

            if(type[2] == 'u')  return 8;   //unsigned long long
        }
    }
}

int myprintf(char *string, ...)
{
    int nrd;
    unsigned nru;
    long int nrld;
    unsigned long nrlu;
    double nrlf;
    long long int nrlld;
    unsigned long long nrllu;

    va_list format;
    va_start(format, string);

    char output[MAXL];

    int index1 = -1;
    for(int i=0; string[i] != '\0'; ++i)
    {
        char _aux[MAX];
        char _aux1[MAX];
        int index = -1;

        if(string[i] == '%')
        {
            ++i;
            while(string[i] != ' ') _aux[++index] = string[i++];
            --i;

            switch (ReturnType(_aux))
            {
                case 1:
                    nrd = va_arg(format, int);
                    strcpy(_aux1, NumberToString(&nrd, "int"));
                    break;
                case 2:
                    nru = va_arg(format, unsigned);
                    strcpy(_aux1, NumberToString(&nru, "unsigned"));
                    break;
                case 3:
                    nrlf  = va_arg(format, double);
                    strcpy(_aux1, NumberToString(&nrlf, "float"));
                    break;
                case 4:
                    nrld = va_arg(format, long int);
                    strcpy(_aux1, NumberToString(&nrld, "long int"));
                    break;
                case 5:
                    nrlu = va_arg(format, unsigned long);
                    strcpy(_aux1, NumberToString(&nrlu, "unsigned long"));
                    break;
                case 6:
                    nrlf = va_arg(format, double);
                    strcpy(_aux1, NumberToString(&nrlf, "double"));
                    break;
                case 7:
                    nrlld = va_arg(format, long long int);
                    strcpy(_aux1, NumberToString(&nrlld, "long long int"));
                    break;
                case 8:
                    nrllu = va_arg(format, unsigned long long);
                    strcpy(_aux1, NumberToString(&nrllu, "unsigned long long"));
                    break;
                default:
                    exit(EXIT_FAILURE);
                    break;
            }

            for(int i=0; i<strlen(_aux1); ++i)  output[++index1] = _aux1[i];
        }
        else    output[++index1] = string[i];
    }
    output[++index1] = '\0';

    puts(output);
    va_end(format);
}

_Bool IsSeparator(char ch)
{
    return (ch == ' ') || (ch == '\n') || (ch == '\t') || (ch == '!') || (ch == '?') ||
            (ch == ',') || (ch == '\0');
}

int myscanf(char *string, ...)
{
    int nrd;
    float nrf;
    unsigned nru;
    long int nrld;
    unsigned long nrlu;
    double nrlf;
    long long int nrlld;
    unsigned long long nrllu;

    va_list format;
    va_start(format, string);

    for(int i=0; string[i] != '\0'; ++i)
    {
        char _aux[MAX];
        char _aux1[MAX];
        char ch;
        int index = -1;
        int index1 = -1;
        _Bool negative = 0;

        if(string[i] == '%')
        {
            ++i;
            while(!IsSeparator(string[i])) _aux[++index] = string[i++];
            --i;

            switch (ReturnType(_aux))
            {
                case 1:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';


                    nrd = 0;
                    for(int i=0; i<strlen(_aux1); ++i)
                    {
                        if(_aux1[i] == '-')
                        {
                            negative = 1;
                            continue;
                        }
                        nrd *= 10;
                        nrd += (_aux1[i] - '0');
                    }

                    if(negative)    nrd = -nrd;

                    int *d = va_arg(format, int*);
                    *d = nrd;
                    break;
                case 2:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';

                    nru = 0;
                    for(int i=0; i<strlen(_aux1); ++i)
                    {
                        nru *= 10;
                        nru += (_aux1[i] - '0');
                    }

                    unsigned *u = va_arg(format, unsigned*);
                    *u = nru;
                    break;
                case 3:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';

                    int j=0;
                    nrf = 0;
                    for(j=0; _aux1[j] != '.'; ++j)
                    {
                        nrf *= 10;
                        nrf += (_aux1[j] - '0');
                    }
                    ++j;
                    for(long double x=10.0; j<strlen(_aux1); ++j, x*=10.0)
                    {
                        nrf += (_aux1[j] - '0') / x;
                    }

                    float *f = va_arg(format, float*);
                    *f = nrf;
                    break;
                case 6:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';

                    int i=0;
                    nrlf = 0;
                    for(i=0; _aux1[i] != '.'; ++i)
                    {
                        nrlf *= 10;
                        nrlf += (_aux1[i] - '0');
                    }
                    ++i;
                    for(long double x=10.0; i<strlen(_aux1); ++i, x*=10.0)
                    {
                        nrlf += (_aux1[i] - '0') / x;
                    }

                    double *lf = va_arg(format, double*);
                    *lf = nrlf;
                    break;
                case 4:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';


                    nrld = 0;
                    for(int i=0; i<strlen(_aux1); ++i)
                    {
                        if(_aux1[i] == '-')
                        {
                            negative = 1;
                            continue;
                        }
                        nrld *= 10;
                        nrld += (_aux1[i] - '0');
                    }

                    if(negative)    nrld = -nrld;

                    long int *ld = va_arg(format, long int*);
                    *ld = nrld;
                    break;
                case 5:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';

                    nrlu = 0;
                    for(int i=0; i<strlen(_aux1); ++i)
                    {
                        nrlu *= 10;
                        nrlu += (_aux1[i] - '0');
                    }

                    unsigned long *lu = va_arg(format, unsigned long*);
                    *lu = nrlu;
                    break;
                case 7:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';


                    nrlld = 0;
                    for(int i=0; i<strlen(_aux1); ++i)
                    {
                        if(_aux1[i] == '-')
                        {
                            negative = 1;
                            continue;
                        }
                        nrlld *= 10;
                        nrlld += (_aux1[i] - '0');
                    }

                    if(negative)    nrlld = -nrd;

                    long long int *lld = va_arg(format, long long int*);
                    *lld = nrlld;
                    break;
                case 8:
                    while(!IsSeparator(ch = getchar()))
                        _aux1[++index1] = ch;
                    _aux1[++index1] = '\0';

                    nrllu = 0;
                    for(int i=0; i<strlen(_aux1); ++i)
                    {
                        nrllu *= 10;
                        nrllu += (_aux1[i] - '0');
                    }

                    unsigned long long *llu = va_arg(format, unsigned long long*);
                    *llu = nrllu;
                    break;
                default:
                    exit(EXIT_FAILURE);
                    break;
            }
        }
    }

    va_end(format);

}

int main(void)
{
    myprintf("numere %d plus %f plus %u numere", -4, 3.14, 15);

    float a;
    myscanf("%f", &a);
    printf("a -> %f\n",a);

    return 0;
}