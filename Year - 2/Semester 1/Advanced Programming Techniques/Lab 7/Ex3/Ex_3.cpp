/*
    Sa se implementeze clasa Tablou unidimensional aplicabil pentru orice tip.
        Sa se specializeze aceasta clasa, astfel incat pentru tipul char sa se creeze
        un Sir care stocheaza fiecare litera.
        Se vor implementa: constructor, constructor de copiere, destructor, operatorul=,
        operatorul[], operatorul<<, operatorul>>
*/


#include <iostream>
#include "tablou.h"


int main(void){
    Tablou<int> t(10);

    for(int i = 0; i < 10; ++i){
        t[i] = i;
    }

    std::cout << t << std::endl;

    Tablou<char> ch(10);
    std::cin >> ch;
    std::cout << ch << std::endl;


    return 0;
}