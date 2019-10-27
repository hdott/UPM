#include <iostream>
#include "complex.h"


int main(void){
    Complex cp1(2.0, -5.0),
            cp2(3.0, 4.0),
            cp3(-3.0, 2.0);

    std::cout << cp1 << " + " << cp2 << " = " << cp1+cp2 << std::endl;
    std::cout << cp3 << " - " << cp2 << " = " << cp3-cp2 << std::endl;
    std::cout << cp1 << " * " << cp3 << " = " << cp1*cp3 << std::endl;
    std::cout << "~" << cp1 << " = " << ~cp1 << std::endl;
    std::cout << "|" << cp2 << "| = " << modul(cp2) << std::endl;


    return 0;
}