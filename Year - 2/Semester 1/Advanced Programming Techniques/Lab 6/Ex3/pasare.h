#pragma once
#include "animal.h"


class Pasare : virtual public Animal{
    private:
        int nrPene;

    public:
        Pasare(void) : Animal(), nrPene(-1){};
        Pasare(int pene) : Animal(), nrPene(pene){};
        Pasare(const Animal & an, int pene) : Animal(an), nrPene(pene){};
        Pasare(std::string spec, int varsta, int pene) : Animal(spec, varsta), nrPene(pene){};

        const int Pene(void) const{return nrPene;}
        int & Pene(void){return nrPene;}
        void zboara(void) const;
        virtual bool heterotrof(void) const;
};

void Pasare::zboara(void) const{
    std::cout << "Zboara" << std::endl;
}

bool Pasare::heterotrof(void) const{
    return true;
}