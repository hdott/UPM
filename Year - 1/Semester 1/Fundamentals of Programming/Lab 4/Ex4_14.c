/*
Să se scrie un program care ghicește (în maxim 8 pași) un număr ales de utilizator în intervalul [1, 100]. 
Utilzatorul va da următoare indicații programului mai mare ( > ), mai mic ( < ), ghicit ( = ).
*/

#include <stdio.h>
#include <stdlib.h>

// functia intreaba daca numarul este mai mare sau mai mic decat
// numarul aflat la jumatatea multimii
// apoi imparte multimea in 2 jumatati
// si reia verificarea trecand in jumatatea in care se afla numarul
// cat timp numarul introdus difera de numarul aflat la jumatatea multimii
void ghiceste(int x)
{
    int min = 1, max = 100, semn, counter = 0;

    while(x != (min+max)/2)
    {   
        getchar(); //captureaza enterul din introducerea numarului/caracterului
        printf("Numarul introdus este > / < decat %d?\n", (min+max)/2);
            semn = getchar(), system("clear");

        if(semn == '<')
            max = (min+max)/2 - 1;  // daca x != (min+max)/2 scadem 1 pentru a nu mai fi luat
                                    // in considerare a doua oara cand trecem in prima jumatate
        else if(semn == '>')
            min = (min+max)/2 + 1;  // la fel ca mai sus cand trecem in a doua jumatate

        ++counter;
    }

    system("clear");
    printf("Numarul introdus este %d\n", (min+max)/2);
    printf("Numarul a fost ghici in %d pasi\n", counter);
}

void main()
{
    int nr;

    printf("Introduceti un numar din intervalul [1,100]:\n");
        printf("nr = "), scanf("%d", &nr), system("clear");

    ghiceste(nr);
}
