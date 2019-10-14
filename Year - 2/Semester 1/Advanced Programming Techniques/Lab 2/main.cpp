#include <iostream>
#include "Fractie.h"


int main(void){
    int x,
        y;

    // std::cout << "Introduceti 2 numere intregi: ";
    // std::cin >> x >> y;

    Fractie fract1 = Fractie(24, 10),
            fract2 = Fractie(39, 9);

    Fractie fract3 = fract1.aduna(fract2);
    fract3.print();

    fract3 = fract1.scadere(fract2);
    fract3.print();

    fract3 = fract1.inmultire(fract2);
    fract3.print();

    fract3 = fract1.impartire(fract2);
    fract3.print();

    std::cout << "cmmdc(24,10) = " << Fractie::cmmdc(24, 10) << std::endl;

    fract3 = fract1.simplifica();
    fract3.print();

    fract3 = fract1.reciproc();
    fract3.print();

    std::cout << fract1.egal(fract2) << std::endl;


    return 0;
}