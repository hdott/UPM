/*
    Fie clasa Punct2D si clasa Punct3D care mosteneste Punct2D.
        Fie clasa Punct2D care va avea 2 proprietati x si y (abscisa si ordonata)
        - Se vor defini 2 constructori si 1 destructor, operator=
        - Sa se suprascrie operatorii <, <=, >, >=, ==, !=, +, -, *, /, +=, -=, *=,
        /=, ++, --, <<, >>
        - In main sa se creeze n instante ale clasei Puncte2D, intr-un vector de 
        Puncte2D. n se citeste de la tastatura
        - In clasa Punct2D se va defini o functie numita distanta, care va calcula
        distanta intre doua puncte date in 2D
        Fie clasa Punct3D care mosteneste clasa Punct2D si va avea o proprietate z in
        plus
        - Se vor defini 2 constructori si 1 destructor, operator=
        - Sa se suprascrie operatorii <, <=, >, >=, ==, !=, +, -, *, /, +=, -=, *=,
        /=, ++, --, <<, >>
        - In main sa se creeze n instante ale clasei Puncte3D, intr-un vector de 
        Puncte3D. m se citeste de la tastatura
        - In clasa Punct3D se va defini o functie numita distanta, care va calcula
        distanta intre doua puncte date in 3D
*/

#include <iostream>
#include "punct3d.h"


int main(void){
    using namespace std;

    int sizeP2D;
    cout << "Enter the size of an array of Point2D: ";
    cin >> sizeP2D;

    Punct2D **arP2D = new Punct2D*[sizeP2D];
    for(int i = 0; i < sizeP2D; ++i){
        cout << "Enter x and y for a Point2D: ";
        arP2D[i] = new Punct2D[1];
        cin >> *arP2D[i];
    }

    // cout << "Distance between " << *arP2D[0] << " & " << *arP2D[1]
    //     << "is: " << arP2D[0]->distanta(*arP2D[1]) << std::endl;

    // free mem of arP2D
    for(int i = 0; i < sizeP2D; ++i){
        delete[] arP2D[i];
    }
    delete[] arP2D;

    int sizeP3D;
    cout << "Enter the size of an array of Point3D: ";
    cin >> sizeP3D;

    Punct3D **arP3D = new Punct3D*[sizeP3D];
    for(int i = 0; i < sizeP3D; ++i){
        cout << "Enter x and y and z for a Point3D: ";
        arP3D[i] = new Punct3D[1];
        cin >> *arP3D[i];
    }

    // cout << "Distance between " << *arP3D[0] << " & " << *arP3D[1]
    //     << "is: " << arP3D[0]->distanta(*arP3D[1]) << std::endl;

    // free mem of arP3D
    for(int i = 0; i < sizeP3D; ++i){
        delete[] arP3D[i];
    }
    delete[] arP3D;


    return 0;
}