#include <iostream>
#include "lsi.h"


int main(void){
    LSI lista;

    for(int i=0; i<10; ++i){
        lista.add(new Nod(i));
    }

    std::cout << lista << std::endl;

    if(lista.remove(new Nod(5))){
        std::cout << lista << std::endl;
    }


    return 0;
}