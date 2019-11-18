#pragma once
#include "reptila.h"
#include "pasare.h"


class Ornitorinc : public Reptila, public Pasare{
    private:

    public:
        Ornitorinc() : Animal(), Reptila(), Pasare(){};
        Ornitorinc(std::string spec, int varsta, double lung, int pene) : Animal(spec, varsta),
                        Reptila(lung), Pasare(pene){};
        Ornitorinc(const Animal & an, double lung, int pene) : Animal(an), Reptila(lung),
                        Pasare(pene){};

        void amfibiu(void) const;
        virtual bool heterotrof(void) const;
};

void Ornitorinc::amfibiu(void) const{
    std::cout << "Amfibiu" << std::endl;
}

bool Ornitorinc::heterotrof(void) const{
    return true;
}