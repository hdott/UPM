#include <cmath>
#include "punct.h"


Dreapta Punct::dreapta;
int Punct::punct1_poz,
            Punct::punct2_neg,
            Punct::punct3_dr;

Punct::Punct(double x, double y){
    this->x = x;
    this->y = y;

    if(Punct::dreapta.m * x + Punct::dreapta.n == y){
        Punct::punct3_dr++;
    } else if(Punct::dreapta.m * x + Punct::dreapta.n - y > 0){
        Punct::punct1_poz++;
    } else{
        Punct::punct2_neg++;
    }
}

Punct::Punct(const Punct& pct){
    this->x = pct.x;
    this->y = pct.y;
}

Punct::~Punct(){
    if(Punct::dreapta.m * x + Punct::dreapta.n == y){
        Punct::punct3_dr--;
    } else if(Punct::dreapta.m * x + Punct::dreapta.n - y > 0){
        Punct::punct1_poz--;
    } else{
        Punct::punct2_neg--;
    }
}

double distanta(const Punct pct1, const Punct pct2){
    return sqrt(pow(pct2.x-pct1.x, 2) + pow(pct2.y-pct1.y, 2));
}
