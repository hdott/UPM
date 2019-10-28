#include <iostream>
#include "Fractie.h"


int main(void){
    int x,
        y;

    // std::cout << "Introduceti 2 numere intregi: ";
    // std::cin >> x >> y;

    Fractie fract1 = Fractie(24, 10),
            fract2 = Fractie(39, 9);

    // Fractie fract3 = fract1.aduna(fract2);
    // fract3.print();

    // fract3 = fract1.scadere(fract2);
    // fract3.print();

    // fract3 = fract1.inmultire(fract2);
    // fract3.print();

    // fract3 = fract1.impartire(fract2);
    // fract3.print();

    using std::cout;
    using std::cin;
    using std::endl;
    
    cout << "*** Test Adunare" << endl;
    cout << "Test[1] -> " << fract1 << " + " << fract2 << " = "
        << fract1+fract2 << endl;
    cout << "Test[2] -> " << fract1 << " + " << 2 << " = "
        << fract1+2 << endl;
    cout << "Test[3] -> " << fract1 << " + " << 2.2 << " = "
        << fract1+2 << endl;
    cout << "Test[4] -> " << 2 << " + " << fract2 << " = "
        << fract1+2 << endl;
    cout << "Test[5] -> " << 2.2 << " + " << fract2 << " = "
        << fract1+2 << endl;
    cout << endl;

    cout << "*** Test Scadere" << endl;
    cout << "Test[1] -> " << fract1 << " - " << fract2 << " = "
        << fract1-fract2 << endl;
    cout << "Test[2] -> " << fract1 << " - " << 2 << " = "
        << fract1-2 << endl;
    cout << "Test[3] -> " << fract1 << " - " << 2.2 << " = "
        << fract1-2 << endl;
    cout << "Test[4] -> " << 2 << " - " << fract2 << " = "
        << fract1-2 << endl;
    cout << "Test[5] -> " << 2.2 << " - " << fract2 << " = "
        << fract1-2 << endl;
    cout << endl;

    cout << "*** Test Inmultire" << endl;
    cout << "Test[1] -> " << fract1 << " * " << fract2 << " = "
        << fract1*fract2 << endl;
    cout << "Test[2] -> " << fract1 << " * " << 2 << " = "
        << fract1*2 << endl;
    cout << "Test[3] -> " << fract1 << " * " << 2.2 << " = "
        << fract1*2 << endl;
    cout << "Test[4] -> " << 2 << " * " << fract2 << " = "
        << fract1*2 << endl;
    cout << "Test[5] -> " << 2.2 << " * " << fract2 << " = "
        << fract1*2 << endl;
    cout << endl;

    cout << "*** Test Impartire" << endl;
    cout << "Test[1] -> " << fract1 << " / " << fract2 << " = "
        << fract1/fract2 << endl;
    cout << "Test[2] -> " << fract1 << " / " << 2 << " = "
        << fract1/2 << endl;
    cout << "Test[3] -> " << fract1 << " / " << 2.2 << " = "
        << fract1/2 << endl;
    cout << "Test[4] -> " << 2 << " / " << fract2 << " = "
        << fract1/2 << endl;
    cout << "Test[5] -> " << 2.2 << " / " << fract2 << " = "
        << fract1/2 << endl;
    cout << endl;

    cout << "*** Test operatori +=, -=, *=, /=" << endl;
    Fractie fract3;
    cout << "Test[1]" << fract3 << " + " << fract1 << " = "
        << (fract3+=fract1) << endl;
    cout << "Test[2]" << fract3 << " - " << fract1 << " = "
        << (fract3-=fract1) << endl;
    fract3 = Fractie(3,4);
    cout << "Test[3]" << fract3 << " * " << fract1 << " = "
        << (fract3*=fract1) << endl;
    cout << "Test[4]" << fract3 << " / " << fract1 << " = "
        << (fract3/=fract1) << endl;
    cout << endl;

    cout << "*** Test increment/decrement" << endl;
    cout << "Test[1]" << fract1++ << "++ = " << fract1 << endl;
    cout << "Test[2]" << " ++" << fract1 << " = " << ++fract1 << endl;  
    cout << "Test[3]" << fract1-- << "-- = " << fract1 << endl;
    cout << "Test[4]" << " --" << fract1 << " = " << --fract1 << endl;
    cout << endl;

    cout << "*** Test conversie tip" << endl;
    cout << "Test[1]" << "double (" << fract1 << ") = " << double(fract1) << endl;
    cout << endl;


    std::cout << "cmmdc(24,10) = " << Fractie::cmmdc(24, 10) << std::endl;

    // fract3 = fract1.simplifica();
    // fract3.print();

    // fract3 = fract1.reciproc();
    // fract3.print();

    // std::cout << fract1.egal(fract2) << std::endl;

    


    return 0;
}