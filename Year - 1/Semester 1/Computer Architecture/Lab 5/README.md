## LAB 4

- [4x4_Matrix_KeyPad](./4x4_matrix_keypad.ino)
    > Se declara 2 tablouri cu numarul pinului digital pentru coloane si linii:
    >   - const int row[] = {5, 4, 3, 2}
    >   - const int col[] = {6, 7, 8, 9}
    >   - se afiseaza pe interfata seriala linia, coloana tastei apasate
    >   - o noua valoare va fi afisata numai daca s-a schimbat tasta apasata
    >   - se va afisa codul tastei afisate folosind o matrice de corespondenta static const char keymap[4][4] = { {'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'} }
    >   - definiti combinatii special de 2 taste, 3 taste
    >   - afisati un text pentru combinatia de taste aleasa