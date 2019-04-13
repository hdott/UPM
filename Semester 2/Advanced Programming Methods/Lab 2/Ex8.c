/* Sa se implementeze o functie care schimba octetul inferior si octetul superior ai
 *  unui numar intreg reprezentat pe 2 octeti (short).
 * In main sa se ceara un numar; sa se afiseze numarul care se obtine prin inversarea
 *  octetilor; sa se afiseze reprezentarile binare ale celor doua numere.
 * Sa se apeleze functia de 2 ori ca sa se obtina numarul initial.
 */

#include <stdio.h>


short SwitchBytes(short nr)
{
    char firstByte, secondByte, *pByte;
    pByte = (char*) &nr;

    firstByte = *(pByte+0);
    secondByte = *(pByte+1);

    *(pByte+0) = secondByte;
    *(pByte+1) = firstByte;

    short *pShort = (short*) pByte;

    return *pShort;
}

void PrintBinary(short nr)
{
    for(int i=sizeof(short)*8-1; i>=0; --i)
        if(nr & (1<<i))
            putc('1', stdout);
        else
            putc('0', stdout);
    puts("");
}

int main(void)
{
    short nr, nrSwitched;

    printf("Introduceti un numar: ");
        scanf("%d", &nr);
    PrintBinary(nr);

    nrSwitched = SwitchBytes(nr);
    printf("bytes inversati = %d\n", nrSwitched);
    PrintBinary(nrSwitched);

    printf("\nIntroduceti un numar: %d\n", nrSwitched);
    PrintBinary(nrSwitched);

    nrSwitched = SwitchBytes(nrSwitched);
    printf("bytes inversati = %d\n", nrSwitched);
    PrintBinary(nrSwitched);

    return 0;
}