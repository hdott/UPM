/*
    Sa se scrie functii sablon care pot prelua un vector unidimensional de orice tip si
        calculeaza si returneaza:
    - maximul din vector
    - minimul din vector
    - cautare secventiala
    - cautare binara
    - ordonare prin metoda bulelor
    - sa se specializeze functia ordonare pentru vectorii de caractere a.i. sa fie
        sortate in ordine invera alfabetica
*/


#include <iostream>
#include "vector.h"


int main(void){
    using namespace Vector;

    int vector[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    std::cout << "Max: " << max<int>(10, vector) << std::endl;
    std::cout << "Min: " << min<int>(10, vector) << std::endl;
    std::cout << "Search True: " << search<int>(10, vector, 5) << std::endl;
    std::cout << "Search False: " << search<int>(10, vector, -1) << std::endl;
    std::cout << "BSearch True: " << bsearch<int>(10, vector, 10) << std::endl;
    std::cout << "BSearch False: " << bsearch<int>(10, vector, -1) << std::endl;

    char vect[10] {'a', 'z', 'y', 'm', 'c', 'd', 't', 'o', 'g', 'e'};
    std::cout << "Bubble Sort: ";
    bubbleSort<char>(10, vect);
    printVector(10, vect);
    std::cout << "Reverse Sort: ";
    reverseSort(10, vect);
    printVector(10, vect);

    return 0;
}