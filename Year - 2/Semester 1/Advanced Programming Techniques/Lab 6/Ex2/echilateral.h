#pragma once
#include "isoscel.h"


class Echilateral : public Isoscel{
    private:

    
    public:
        Echilateral(double l) : Triunghi(l, l, l), Isoscel(l, l){};

        virtual double arie(void) const;
        using Triunghi::perimetru;
};

double Echilateral::arie() const{
    return (pow(Triunghi::getL1(), 2) * sqrt(3) / 4);
}