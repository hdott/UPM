#pragma once
#include <cmath>


class Triunghi{
    private:
        double l1,
                l2,
                l3;

    protected:
        double getL1(void) const{return l1;}
        double getL2(void) const{return l2;}
        double getL3(void) const{return l3;}

    public:
        Triunghi(double l1, double l2, double l3) : l1(l1), l2(l2), l3(l3){};

        virtual double arie(void) const = 0;
        virtual double perimetru(void) const;
};

double Triunghi::arie() const{
    double semiP = (l1 + l2 + l3) / 2;

    return (sqrt(semiP * (semiP - l1) * (semiP - l2) * (semiP - l3)));
}

double Triunghi::perimetru() const{
    return (l1 + l2 + l3);
}