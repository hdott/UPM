#include <iostream>
// #include <vector>
#include "carte.h"


int main(void){
    Carte vect[3];

    std::cout << "Introduceti detalii a 3 carti:" << std::endl;
    for(int i=0; i<3; ++i){
        std::cin >> vect[i];
    }

    std::cout << "Introduceti un autor: ";
    std::string autor;
    std::cin >> autor;
    Carte _tmp(autor);

    int count=0;
    for(int i=0; i<3; ++i){
        if(vect[i] == _tmp){
            count++;
        }
    }
    if(count > 1 || count == 0){
        std::cout << autor << " apare de " << count << " ori" << std::endl;
    } else{
        std::cout << autor << " apare " << count << " data" << std::endl;
    }    


    return 0;
}