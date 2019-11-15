/*
    Sa se implementeze urmatoarea ierarhie de clase. Sa se implementeze functiile arie,
        perimetru, avand la dispozitie valorile celor 3 laturi, ca atribute.
*/

#include <iostream>
#include "dreptunghic_isoscel.h"
#include "echilateral.h"



int main(void){
    using namespace std;

    Dreptunghic tr_dr(4, 5, 6);
    cout << "Dreptunghic:" << endl;
    cout << "\tArie: " << tr_dr.arie() << endl;
    cout << "\tPerimetru: " << tr_dr.perimetru() << endl;

    Isoscel tr_is(4, 5);
    cout << "Isoscel:" << endl;
    cout << "\tArie: " << tr_is.arie() << endl;
    cout << "\tPerimetru: " << tr_is.perimetru() << endl;

    Dreptunghic_Isoscel  tr_dr_is(4, 5);
    cout << "Dreptunghic Isoscel:" << endl;
    cout << "\tArie: " << tr_dr_is.arie() << endl;
    cout << "\tPerimetru: " << tr_dr_is.perimetru() << endl;
    
    Echilateral tr_ech(5);
    cout << "Echilateral:" << endl;
    cout << "\tArie: " << tr_ech.arie() << endl;
    cout << "\tPerimetru: " << tr_ech.perimetru() << endl;


    return 0;
}