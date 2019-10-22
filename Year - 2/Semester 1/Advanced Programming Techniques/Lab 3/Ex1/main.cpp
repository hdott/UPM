#include <iostream>
#include "punct.h"
#include "dreapta.h"

Punct centruDeGreutate(Punct n[], int size);


int main(void){
    using namespace std;

    Dreapta dr(2,3);

    int n;
    cout << "Introduceti numarul de puncte: ";
    cin >> n;
    Punct *vPunct = new Punct[n];

    double x,
            y;
    for(int i=0; i<n; ++i){
        cout << "Introduceti un punct (x,y): ";
        cin >> x >> y;
        vPunct[i].setXY(x, y);
    }


    return 0;
}


Punct centruDeGreutate(Punct n[], int size){
    Punct _pct(0,0);
    for(int i=0; i<size; ++i){
        _pct.setX(_pct.getX()+n[i].getX());
        _pct.setY(_pct.getY()+n[i].getY());
    }

    _pct.setXY(_pct.getX()/size, _pct.getY()/size);

    return _pct;
}
