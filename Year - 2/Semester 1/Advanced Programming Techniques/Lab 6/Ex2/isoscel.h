#pragma once
#include "triunghi.h"


class Isoscel : virtual public Triunghi{
    private:
        // l1 == l2
    public:
        Isoscel(double l1, double l2) : Triunghi(l1, l1, l2){};

        virtual double arie(void) const;
        using Triunghi::perimetru;
};

double Isoscel::arie() const{
    double l1, l2, l3;
    l1 = l2 = Triunghi::getL1();
    l3 = Triunghi::getL3();
    
    double semiP = (l1 + l2 + l3) / 2;

    return (sqrt(semiP * (semiP - l1) * (semiP - l2) * (semiP - l3)));
}