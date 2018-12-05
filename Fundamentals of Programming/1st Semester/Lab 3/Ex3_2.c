/*
Se citesc două numere întregi de la tastatură (a și b). Să se afișeze: 
- Valoarea pre-decrementată, post-decrementată, pre și post-incrementata a celor două variabile 
- Valoarea rezultată din adăugarea valorii 10, scăderea valorii 10, înmulțirii cu 10 și împărțirii cu 10 
- Câtul și restul împărțirii întregi 
- Valoarea împărțirii reale cu preciziile 3, 5 și 10 
- Valoarea expresiei: (n1^3-n2^2-n1*n2+10)
*/

#include <stdio.h>
#define next printf("\n");

int pre_decrement(int x)
{
    int aux_x = x;

    return --aux_x;
}

int post_decrement(int x)
{
    int aux_x = x;

    return aux_x--;
}

int pre_increment(int x)
{
    int aux_x = x;

    return ++aux_x;
}

int post_increment(int x)
{
    int aux_x = x;

    return aux_x++;
}

void subpoint_2(int x, char s)
{
    printf("[%c + 10] = %d\n", s, x+10);
    printf("[%c - 10] = %d\n", s, x-10);
    printf("[%c * 10] = %d\n", s, x*10);
    printf("[%c / 10] = %d\n", s, x/10);
}

int power(int x, int y)
{
    int pow_x = 1;
    for(int i = 0; i < y; ++i)
        pow_x = pow_x * x;
    
    return pow_x;
}

void main()
{
    int a, b;

    printf("Introduceti un numar intreg:\n");
        printf("a = "), scanf("%d", &a);
    printf("Introduceti un numar intreg:\n");
        printf("b = "), scanf("%d", &b), next;

    printf(" ~~Subpoint 1~~\n\n");
    printf("Valoarea pre-decrementata este:  [--a] = %d\t[--b] = %d\n", pre_decrement(a), pre_decrement(b));
    printf("Valoarea post-decrementata este: [a--] = %d\t[b--] = %d\n", post_decrement(a), post_decrement(b));
    printf("Valoarea pre-incrementata este:  [++a] = %d\t[++b] = %d\n", pre_increment(a), pre_increment(b));
    printf("Valoarea post-incrementata este: [a++] = %d\t[b++] = %d\n", post_increment(a), post_increment(b));
    next;

    printf(" ~~Subpoint 2~~\n\n");
        subpoint_2(a, 'a'), next;
        subpoint_2(b, 'b'), next;

    printf(" ~~Subpoint 3~~\n\n");
        printf("[a / b] = %d\t[a % b] = %d\n", a/b, a%b);
        printf("[b / a] = %d\t[b %% a] = %d\n", b/a, b%a);
    next;

    printf(" ~~Subpoint 4~~\n\n");
        printf("[a / b].3  = %.3f\t\t[b / a].3  = %.3f\n", (float)a/b, (float)b/a);
        printf("[a / b].5  = %.5f\t\t[b / a].5  = %.5f\n", (float)a/b, (float)b/a);
        printf("[a / b].10 = %.10f\t[b / a].10 = %.10f\n", (float)a/b, (float)b/a);
    next;

    printf(" ~~Subpoint 5~~\n\n");
        printf("a^3 - b^2 - a * b + 10 = %d\n", power(a,3)-power(b,2)-a*b+10);
}
