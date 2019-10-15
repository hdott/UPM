/* Se citesc doua numere intregi (a,b) din fisierul in.txt. Sa se scrie un program
    +comenzi linie de comanda care sa:
    - afiseze continutul directorului curent, daca a>b
    - creeze un nou director cu numele obtinut din string-ul "test" si concatenarea
        rezultatului sumei celor doua numere daca a=b
        - afiseze calea curenta, daca a<b
*/

// Programul se ruleaza cu comanda:
// ./Ex2 < in.txt | bash
#include <stdio.h>

int main(int argc, char **argv){
    int a,
        b;

    scanf("%d %d", &a, &b);

    if(a>b){
        printf("ls -al");
    }
    if(a==b){
        printf("mkdir %s\\ %d/", "test", a+b);
    }
    if(a<b){
        printf("pwd");
    }

    return 0;
}