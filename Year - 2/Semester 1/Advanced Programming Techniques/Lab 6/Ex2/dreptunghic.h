#pragma once
#include "triunghi.h"


class Dreptunghic : virtual public Triunghi{
    private:
        const double unghi_l1_l2 = 90;

    public:
        Dreptunghic(double l1, double l2, double l3) : Triunghi(l1, l2, l3){};

        virtual double arie(void) const;
        using Triunghi::perimetru;
};

double Dreptunghic::arie() const{
    return ((Triunghi::getL1() * Triunghi::getL2()) / 2);
}