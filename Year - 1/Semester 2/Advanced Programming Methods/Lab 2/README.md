## LAB 2

- [Ex1](./Ex1.c)
    > Se dau doua puncte din spatiul oarecare A0(x1, y1, z1) si A1(x2, y2, z2) prin coordonatele lor reale. Sa se calculeze distanta dintre cele doua puncte. Distanta sa fie implementata cu ajutorul unui subprogram.
- [Ex2](./Ex2.c)
    > Sa se creeze un tip Punct2D, avand 2 campuri abscisa(x) si ordonata(y) unui plan.
    >   - sa se citeasca 3 puncte de la tastatura, si sa se calculeze distanta intre oricare doua puncte.
    >   - sa se afiseze centrul de greutate al punctelor.
    >   - sa se citeasca varfurile unui poligon de N laturi (N+1) varfuri. Sa se afiseze centrul de greutate al acestor puncte.
    >   - sa se ordoneze punctele dupa abscisa, iar in caz de egalitate si dupa ordonata.
- [Ex3](./Ex3.c)
    > Sa se creeze un program care citeste de la tastatura informatii despre n persoane, apoi le afiseaza in ordine alfabetica (nume+prenume) si in ordinea descrescatoare varstei (Varsta se obtine din CNP).
- [Ex4](./Ex4.c)
    > Sa se creeze un program care citeste de la tastatura n studenti si pentru fiecare k discipline cu notele corespunzatoare. Sa se afiseze studentii in ordinea mediei lor. (Media este media aritmetica a tuturor notelor unui student).
- [Ex5](./Ex5.c)
    > Toate alimentele dintr-un magazin sunt identificate prin cod (1-999), denumire (20 char), unitate de masura, cantitate, pret si data de expirare. Sa se afiseze pentru fiecare tip de aliment codul, denumirea si valoare stocului, iar apoi sa se afiseze alimentele expirate cu toate elementele lor de identificare. Data expirarii este o structura cu 3 campuri: zi, luna, an. O variabila cu acest tip va fi inclusa in structura principala aliment.
- [Ex6](./Ex6.c)
    > Fie o matrice rara, adica o matrice, avand majoritatea elementelor nule. Elementele acestor matrici se memoreaza sub forma unui triplet (i, j, val). Sa se implementeze functii pentru urmatoarele:
    >   - citirea unei matrici rare
    >   - afisarea sub forma matriceala (cu linii si coloane)
    >   - adunarea a doua matrici rare
    >   - inmultirea a doua matrici rare
- [Ex7](./Ex7.c)
    > Se doreste creearea unei liste cu rezultatele sesiunii de examene pentru o grupa cu un numar de 30 de studenti. Pentru verificarea corectitudinii informatiilor, memorate, programul trebuie sa continue si afisarea listei. Se presupune ca un student, la sfarsitul sesiunii, poate fi intr-una din situatiile urmatoare:
    >   - a luat toate examenele si i s-a putut incheia o medie pe sesiune
    >   - a luat toate examenele (sa presupunem ca acestea sunt in numar de cinci), dar nu este incheiata media
    >   - a picat cel putin un examen
- [Ex8](./Ex8.c)
    > Sa se implementeze o functie care schimba octetul inferior si octetul superior al unui numar intreg reprezentat pe 2 octeti (short). In main sa se ceara un numar, sa se afiseze numarul care se obtine prin inversarea octetilor, sa se afiseze reprezentarile binare ale celor 2 numere. Sa se apeleze functia de 2 ori ca sa se obtina numarul initial.
- [Ex9](./Ex9.c)
    > Se citesc de la tastatura n numere naturale pe 2 biti, reprezentand datele de nastere ale unor persoane. Ele sunt codificate astfel pe 7 biti reprezinta ultimele 2 cifre ale anului nasterii, 4 biti luna si 5 ziua.
    >   - sa se afiseze datele de nastere din luna mai.
    >   - sa se afiseze datele pentru persoanele minore (avand varsta sub 18 ani).
    >   - sa se afiseze anul cu cea mai mica natalitate
- [Ex10](./Ex10.c)
    > Fie orarul specializarii Informatica anul 1. Datele nu se citesc de la tastatura, ci se dau in program prin initializare. Se creeaza lista disciplinelor. Orarul va fi reprezentat sub forma unei matrici. Zilele saptamanii se vor defini prin enum. Cerinte:
    >   - sa se afiseze cea mai usoara si cea mai grea zi a studentilor (ziua se va afisa in litere - switch case)
    >   - sa se afiseze pentru fiecare zi numarul de ferestre
    >   - sa se afiseze ziua cu cele mai multe ferestre
- [Ex11](./Ex11.c)
    > Fie un text dat intr-un fisier. Sa se numere cate cuvinte, cate propozitii si cate litere contine textul. Sa se foloseasca instructiunea `continue`.
- [Ex12](./Ex12.c)
    > Sa se citeasca numere intregi pana la 0. Sa se ordoneze numerele pozitive si numerele negative. Pentru oprirea generarii se va folosi `break`, iar pentru ordonare algoritmul de sortare prin selectie directa.
- [Ex13](./Ex13.c)
    > Sa se caute cea mai mica pereche de numere prietene intr-un interval (citit).
- [Ex14](./Ex14.c)
    > Sa se genereze numere intregi aleatoare in intervalul [-RAND_MAX, RAND_MAX]. Dupa fiecare generare utilizatorul sa fie intrebat daca doreste sa continue sau nu. Sa se verifice cate numere sunt in fiecare interval dat (intervalele nu se suprapun). Lista intervalelor se da intr-un fisier. Nu se precizeaza numarul total de linii in fisier. Sa se foloseasca `continue` si `break` so `goto`.
- [Ex15](./Ex15.c)
    > Sa se implementeze citirea cu validare, numarul citit sa fie in intervalul dat [a,b]. Sa se citeasca numere pana cand se va da o valoare din interval. Sa se foloseasca instructiuni de salt.
- [Ex16](./Ex16.c)
    > Sa se citeasca litere pana se da o litera citita anterior