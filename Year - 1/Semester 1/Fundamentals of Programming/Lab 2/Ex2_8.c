/*
Să se implementeze un program cu următoarele funcţionalităţi: 
- Să se afişeze mesajul "Numele şi prenumele" la mijlocul ecranului 
- La apăsarea a două taste să se şteargă ecranul 
- Să se afişeze acelaşi mesaj cu o poziţie deplasată în jos 
- Să se genereze două sunete 
- Să se repete ultimele două cerinţe de 5 ori
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <windows.h> 

void main() 
{ 
    printf("%34s \n", "Nuta Horia-Catalin"); 
    getch() && getch(), system("cls"), printf("\n"); 
    
    printf("%34s \n", "Nuta Horia-Catalin"); 
    printf("\a"), Sleep(1000), printf("\a"), Sleep(1000); 

    printf("%34s \n", "Nuta Horia-Catalin"); 
    printf("\a"), Sleep(1000), printf("\a"), Sleep(1000); 

    printf("%34s \n", "Nuta Horia-Catalin"); 
    printf("\a"), Sleep(1000), printf("\a"), Sleep(1000); 
    
    printf("%34s \n", "Nuta Horia-Catalin"); 
    printf("\a"), Sleep(1000), printf("\a"), Sleep(1000); 

    printf("%34s \n", "Nuta Horia-Catalin"); 
    printf("\a"), Sleep(1000), printf("\a"), Sleep(1000); 
}
