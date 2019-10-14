#include <iostream>
#include "Fractie.h"


int main(void){
    int x,
        y;

    std::cout << "Introduceti 2 numere intregi: ";
    std::cin >> x >> y;

    Fractie fract = Fractie(x, y);
    fract.print();

    return 0;
}