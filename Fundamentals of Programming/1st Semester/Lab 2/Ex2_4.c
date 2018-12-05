/*
Să se implementeze un program cu următoarele funcţionalităţi: 
- Sa se afişeze mesajul "Laborator de programare" la mijlocul ecranului 
- La apăsarea unei taste să se ştearga ecranul 
- Să se genereze un sunet 
- Să se afişeze acelaşi mesaj cu o poziţie deplasată la dreapta şi o poziţie deplasată în jos
- Să se repete ultimele două cerinţe de 3 ori
*/

#include <stdio.h>
#include <stdlib.h>

void main()
{
    printf("%34s \n", "Laborator de Programare");
    getchar(), system("clear"), printf("\a"); //system("cls") ~ windows
    
    printf("%35s \n", "Laborator de Programare");
    getchar(), printf("\a");

    printf("%36s \n", "Laborator de Programare");
    getchar(), printf("\a");

    printf("%37s \n", "Laborator de Programare");
    getchar(), printf("\a");

    printf("%38s \n", "Laborator de Programare");
    getchar(), printf("\a");
}
