/*
    Sa se implementeze Stiva statica si Stiva dinamica folosind mostenirea intre
        clase.
        Sa se implementeze operatorii =, << si >>
        Clasa nod sa fie o clasa imbricata a clasei
*/


#include <iostream>
#include "arraystack.h"
#include "liststack.h"


int main(void){
    ArrayStack arstk(10);
    for(int i = 0; i < 10; ++i){
        arstk.push(i);
    }
    // for(int i = 0; i < 10; ++i){
    //     std::cout << arstk.pop() << " ";
    // }
    // std::cout << std::endl;

    ListStack lstk(-1);
    for(int i = 0; i < 10; ++i){
        lstk.push(i);
    }
    // for(int i = 0; i < 10; ++i){
    //     std::cout << lstk.pop() << " ";
    // }
    // std::cout << std::endl;
    
    arstk.print();
    lstk.print();


    return 0;
}