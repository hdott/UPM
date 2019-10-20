#pragma once
// #ifndef CONTBANCAR_H
// #define CONTBANCAR_H
#include <iostream>
#include "Operatiuni.h"


class ContBancar:Operatiuni{
    private:
        std::string numarCont;
        float suma;
        std::string moneda;
        int zile{0};
    public:
        ContBancar(std::string numarCont, float suma, std::string moneda="RON");
        ContBancar(const ContBancar&);
        // ~ContBancar();

        inline std::string getNumarCont(){return numarCont;}
        inline float getSuma(){return suma;}
        inline std::string getMoneda(){return this->moneda;}
        inline void setNumarCont(std::string numarCont){this->numarCont = numarCont;}
        inline void setSuma(float suma){this->suma = suma;}
        inline void setMoneda(std::string moneda){this->moneda = moneda;}

        float getSumaTotala();
        float getDobanda();
        void depunere(ContBancar contDest, float suma);
        void extragere(ContBancar contDest, float suma);
        void transfer(ContBancar contDest, float suma);
};

// #endif