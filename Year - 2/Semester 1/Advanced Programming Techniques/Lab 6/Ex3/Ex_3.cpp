/*
    Sa se creeze o ierarhie de clase care contine o clasa abstracta Animal cu proprietatile
        specie, varsta. Cu metoda abstracta heterotrof si metode neabstracte get-set pentru
        atribute. Din aceasta clasa sa se extinda doua clase Reptila si Pasare cu cate o
        metoda proprie taraste si zboara si cate un atribut propriu lungime respective
        nrPene. Get-Set pentru aceste atribute.
    - Apoi sa se creeze clasa Ornitorinc care mosteneste atat clasa Reptila cat si clasa
        Pasare cu o metoda proprie amfibiu.
    - In metoda principala sa se creeze un individ din aceasta specie, apoi sa se apeleze
        toate metodele obiectului definit.
*/

#include <iostream>
#include "ornitorinc.h"


int main(void){
    using namespace std;

    Ornitorinc orn("specie", 10, 12.2, 0);

    cout << orn.Specie() << endl;
    cout << orn.Varsta() << endl;
    cout << orn.Lungime() << endl;
    cout << orn.Pene() << endl;
    
    if(orn.heterotrof()){
        orn.taraste();
        orn.zboara();
        orn.amfibiu();
    }
    

    return 0;
}