#include <iostream>
#include "ContBancar.h"


ContBancar::ContBancar(std::string numarCont, float suma, std::string moneda){
    this->numarCont = numarCont;
    this->suma = suma;
    this->moneda = moneda;
}

ContBancar::ContBancar(const ContBancar& cb){
    this->numarCont = cb.numarCont;
    this->suma = cb.suma;
    this->moneda = cb.moneda;
}

float ContBancar::getSumaTotala(){
    return suma+getDobanda();
}

float ContBancar::getDobanda(){
    if(this->moneda.compare("RON") == 0){
        if(suma < 500){
            return zile*0.3;
        } else{
            return zile*0.8;
        }
    } else if(this->moneda.compare("EUR")){
        return zile*0.1;
    }
}

void ContBancar::depunere(ContBancar contDest, float suma){
    contDest.suma += suma;
}

void ContBancar::extragere(ContBancar contDest, float suma){
    contDest.suma -= suma;
}

void ContBancar::transfer(ContBancar contDest, float suma){
    if(this->moneda.compare("RON") == 0 && 
        contDest.moneda.compare("RON") == 0){
        if(this->suma > suma){
            this->suma -= suma;
            contDest.suma += suma;
        }
    }
}