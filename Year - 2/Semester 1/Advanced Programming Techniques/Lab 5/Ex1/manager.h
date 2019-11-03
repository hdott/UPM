#pragma once
#include "angajat.h"


class Manager : public Angajat{
    public:
        Manager(double tO = 5.5, int nO = 0) : Angajat(tO, nO){};
        double getSalar() const {
            return Angajat::getSalar() + Angajat::getSalar() * .5;
        }
};