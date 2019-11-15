#pragma once
#include "dreptunghic.h"
#include "isoscel.h"


class Dreptunghic_Isoscel : public Dreptunghic, public Isoscel{
    private:

    public:
        Dreptunghic_Isoscel(double l1, double l2) : Triunghi(l1, l1, l2),
                            Dreptunghic(l1, l1, l2), Isoscel(l1, l2){};
        
        virtual double arie(void) const;
        using Triunghi::perimetru;
};

double Dreptunghic_Isoscel::arie() const{
    return ((Triunghi::getL1() * Triunghi::getL2()) / 2);
}