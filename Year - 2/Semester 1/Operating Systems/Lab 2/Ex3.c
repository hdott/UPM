/* Pentru cazul a>b continutul sa fie afisat in ordine inversa alfabetic. Sa se
    afiseze pagina cu pagina.
*/
#include <stdio.h>

// Programul se  ruleaza cu comanda:
// ./Ex3 < in.txt | bash
int main(int argc, char **argv){
    int a,
        b;

    scanf("%d %d", &a, &b);

    if(a>b) {
        printf("sort -r Ex3.c | less");
    }

    return 0;
}