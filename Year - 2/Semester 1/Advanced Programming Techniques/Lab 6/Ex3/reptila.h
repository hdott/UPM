#pragma once
#include "animal.h"


class Reptila : virtual public Animal{
    private:
        double lungime;

    public:
        Reptila(void) : Animal(), lungime(-1){};
        Reptila(double lung) : Animal(), lungime(lung){};
        Reptila(const Animal & an, double lung) : Animal(an), lungime(lung){};
        Reptila(std::string spec, int varst, double lung) : Animal(spec, varst),
                    lungime(lung){};

        const double Lungime(void) const{return lungime;}
        double & Lungime(void){return lungime;}
        void taraste(void) const;
        virtual bool heterotrof(void) const;
};

void Reptila::taraste(void) const{
    std::cout << "Taraste" << std::endl;
}

bool Reptila::heterotrof(void) const{
    return true;
}