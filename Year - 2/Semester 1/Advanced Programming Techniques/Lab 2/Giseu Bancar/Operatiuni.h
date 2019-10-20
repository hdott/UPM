#pragma once
// #ifndef OPERATIUNI_H
// #define OPERATIUNI_H
// #include "ContBancar.h"
// class ContBancar;

class Operatiuni{
    protected:
        // int zile{1};
    public:
        // Operatiuni(){};
        // ~Operatiuni();

        virtual float getSumaTotala();
        virtual float getDobanda();
        // virtual void depunere(ContBancar contDest&, float suma);
        // virtual void extragere(ContBancar contDest&, float suma);
        // virtual void transfer(ContBancar contDest&, float suma);
};

// #endif