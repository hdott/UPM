#include <stdio.h>

void ToH(int disk, char source, char dest, char spare)
{
    if(!disk)
    {
        printf("Move disk from %c -> %c\n", source, dest);
        return;
    }

    ToH(disk-1, source, spare, dest);
    printf("Move disk from %c -> %c\n", source, dest);
    ToH(disk-1, spare, dest, source);
}

int main(void)
{
    int n;
    printf("Introduceti numarul de discuri: ");
    scanf("%d", &n);

    ToH(n, 'A', 'B', 'C');

    return 0;
}