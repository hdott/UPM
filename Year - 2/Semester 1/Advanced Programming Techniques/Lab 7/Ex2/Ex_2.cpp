/*
    Sa se implementeze lista lineara simplu inlantuita, care poate stoca orice tip.
        Sa se implementeze constructor, constructor de copiere, destructor,
        operatorul =, operatorul==, operatorul<<, operatorul>>
*/

#include <iostream>
#include "lsi.h"


int main(void){
    LSI<int> list_int;
    list_int.add(1);
    list_int.add(2);
    list_int.add(3);
    std::cout << list_int << std::endl;

    LSI<double> list_int2;
    for(int i = 0; i < 5; ++i){
        std::cin >> list_int2;
    }
    std::cout << list_int2 << std::endl;
    

    return 0;
}