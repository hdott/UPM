#pragma once
#ifndef OPERATIUNI_H
#define OPERATIUNI_H

class ContBancar;

class Operatiuni{
    protected:
        int zile{10};
    public:
        // Operatiuni(){};
        // ~Operatiuni();

        virtual float getSumaTotala() = 0;
        virtual float getDobanda() = 0;
        virtual void depunere(ContBancar& contDest, float suma) = 0;
        virtual void extragere(ContBancar& contDest, float suma) = 0;
        virtual void transfer(ContBancar& contDest, float suma) = 0;
};

#endif