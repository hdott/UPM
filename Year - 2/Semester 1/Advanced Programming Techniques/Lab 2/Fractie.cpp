#include <iostream>
#include "Fractie.h"


// Fractie::Fractie(int numarator, int numitor){
//     this->numarator = numarator;
//     this->numitor = numitor;
// }

Fractie::Fractie(int numarator, int numitor):numarator(numarator),numitor(numitor){};

Fractie::Fractie(const Fractie& param){
    this->numarator = param.numarator;
    this->numitor = param.numitor;
}

Fractie::~Fractie() {};


Fractie Fractie::aduna(Fractie fract){
    int tmp_numarator,
        tmp_numitor;

    tmp_numarator = this->numarator * fract.numitor + 
                    this->numitor * fract.numarator;
    tmp_numitor = this->numitor * fract.numitor;

    return Fractie(tmp_numarator, tmp_numitor);
}

Fractie Fractie::scadere(Fractie fract){
    int tmp_numarator,
        tmp_numitor;

    tmp_numarator = this->numarator * fract.numitor - 
                    this->numitor * fract.numarator;
    tmp_numitor = this->numitor * fract.numitor;

    return Fractie(tmp_numarator, tmp_numitor);
}

Fractie Fractie::inmultire(Fractie fract){
    int tmp_numarator,
        tmp_numitor;

    tmp_numarator = this->numarator * fract.numarator;
    tmp_numitor = this->numitor * fract.numitor;

    return Fractie(tmp_numarator, tmp_numitor);
}

Fractie Fractie::impartire(Fractie fract){
    int tmp_numarator,
        tmp_numitor;

    tmp_numarator = this->numarator * fract.numitor;
    tmp_numitor = this->numitor * fract.numarator;

    return Fractie(tmp_numarator, tmp_numitor);
}

int Fractie::cmmdc(int x, int y){
    int r,
        a,
        b;

    a = x;
    b = y;

    while(r != 0){
        r = a % b;
        a = b;
        b = r;
    }

    return a;
}

Fractie Fractie::simplifica(){
    int cmmdc = Fractie::cmmdc(this->numarator, this->numitor);

    return Fractie(this->numarator/cmmdc, this->numitor/cmmdc);
}

Fractie Fractie::reciproc(){
    return Fractie(this->numitor, this->numarator);
}

bool Fractie::egal(const Fractie& fract){
    if(this->numarator == fract.numarator && 
        this->numitor == fract.numitor){
            return true;
        } else{
            return false;
        }
}

void Fractie::print(){
    std::cout << this->numarator << "/" << this->numitor << std::endl;
}