#include <iostream>
#include "complex.h"


int main(void){
    Complex cp1(2.0, -5.0),
            cp2(3.0, 4.0),
            cp3(-3.0, 2.0);
    Complex cp4 = cp3,
            cp5;
    cp5 = cp2;

    using std::cout;
    using std::endl;
    cout << cp1 << " + " << cp2 << " = " << cp1+cp2 << endl;
    cout << cp3 << " - " << cp2 << " = " << cp3-cp2 << endl;
    cout << cp1 << " * " << cp3 << " = " << cp1*cp3 << endl;
    cout << cp1 << " / " << cp2 << " = " << cp1/cp2 << endl;
    cout << cp1 << " += " << cp2 << " = " << (cp1 += cp2) << endl;
    cout << cp1 << " -= " << cp2 << " = " << (cp1 -= cp2) << endl;
    cout << cp1 << " *= " << cp2 << " = " << (cp1 *= cp2) << endl;
    cout << cp1 << " /= " << cp2 << " = " << (cp1 /= cp2) << endl;
    cout << "++" << cp5 << " = " << ++cp5 << endl;
    cout << cp5++ << "++ = " << cp5 << endl;
    cout << "--" << cp5 << " = " << --cp5 << endl;
    cout << cp5-- << "-- = " << cp5 << endl;
    cout << cp1 << " < " << cp2 << " = " << (cp1 < cp2) << endl;
    cout << cp1 << " > " << cp2 << " = " << (cp1 > cp2) << endl;
    cout << cp1 << " <= " << cp2 << " = " << (cp1 <= cp2) << endl;
    cout << cp1 << " >= " << cp2 << " = " << (cp1 >= cp2) << endl;
    cout << cp1 << " != " << cp2 << " = " << (cp1 != cp2) << endl;
    cout << cp1 << " == " << cp2 << " = " << (cp1 == cp2) << endl;

    cout << "~" << cp1 << " = " << ~cp1 << endl;
    cout << "|" << cp2 << "| = " << modul(cp2) << endl;


    return 0;
}