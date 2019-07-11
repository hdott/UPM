// Sa se citeasca litere pana se da o litera citita anterior

#include <stdio.h>
#include <stdlib.h>
#define CHARS 123

int main(void)
{
    _Bool *chars = (_Bool*) calloc(CHARS, sizeof(_Bool));
    char ch;

    while(1)
    {
        printf("Introduceti o litera!\n");
        printf("(litera): ");
        scanf("%c", &ch);
        getchar();

        if(!chars[ch]) 
        {
            chars[ch] = 1;
            continue;
        }

        printf("\nLitera a fost citita anterior!\n");
        break;
    }

    printf("\nLiterele introduse afisate invers alfabetic:\n");
    for(int i=CHARS-1; i>=65; --i)
        if(chars[i])    printf("%c ", i);

    puts("");

    free(chars);
    return 0;
}