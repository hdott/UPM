## LAB 8

- [Ex_8-1](./Ex8_1.c)
    > Se citeşte un număr natural pe 8 biţi de la tastatură. Să se afişeze: 
    >   - Valorea bitului al 3-lea (k=3) 
    >   - Valoarea bitului de paritate 
    >   - Numărul rezultat după resetarea (=0) bitului 2 (k=2) 
    >   - Numărul rezultat după setarea bitului 4 (k=4)
- [Ex_8-2](./Ex8_2.c)
    > Se citeşte un număr natural pe 8 biţi de la tastatură. Să se afişeze reprezentarea binară a acestuia folosind operatorul de deplasare.
- [Ex_8-3](./Ex8_3.c)
    > Se citeşte un număr întreg de la tastatură. Dacă valoarea bitului 2 este 1 atunci şa se seteze bitul 5, altfel să se reseteze bitul 7.
- [Ex_8-4](./Ex8_4.c)
    > Se citesc două numere naturale de la tastatură, n şi m. n este stocat pe 32 de biţi, iar m este stocat pe 8 biţi. Să se modifice starea bitului al m-lea pe 1 şi starea bitului al 32-m-lea pe 0.
- [Ex_8-5](./Ex8_5.c)
    > Se citeşte un număr natural stocat pe 16 biţi de la tastatură. Să se interschimbe octetul inferior cu octetul superior.
- [Ex_8-6](./Ex8_6.c)
    > Se citeşte un număr natural pe 32 biţi (m) şi un număr natural pe 8 biţi (n) de la tastatură. Să se implementeze rotaţia pe biţi al lui n de m ori. Primul bit din stânga devine ultimul bit din dreapta - rotaţie de la stânga (sau invers - rotaţie la dreapta).
- [Ex_8-7](./Ex8_7.c)
    > Se citeşte un număr natural pe 8 biţi de la tastatură. Să se determine suma biţilor egali cu 1.
- [Ex_8-8](./Ex8_8.c)
    > Se citeşte un număr natural pe 8 biţi de la tastatură. Să se determine numărul de biţi egali cu 1 de pe poziţii pare.
- [Ex_8-9](./Ex8_9.c)
    > Se citeşte un număr natural pe 8 biţi de la tastatură. Să se determine numărul de biţi egali cu 0 de pe poziţii impare.
- [Ex_8-10](./Ex8_10.c)
    > Să se implementeze un joc de lumini utilizând deplasarea numărului 1 şi Sleep(100) pentru realizarea unei întârzieri. Codul de deplasare se va pune într-un ciclu: while(!kbhit()){…}. Ex.: 
    ```
    10000000 
    01000000 
    00100000 
    etc.
    ```
- [Ex_8-11](./Ex8_11.c)
    > Se consideră un set de 8 LED-uri legat la portull paralel. Să se implementeze un program care realizează un joc de leduri ce permite aprinderea concomitentă a două leduri şi "deplasarea" acestora în sens invers. Programul va utiliza o întârziere introdusă de la tastatură. Ex.: 
    ```
    10000001 
    01000010 
    00100100 
    …
    ```