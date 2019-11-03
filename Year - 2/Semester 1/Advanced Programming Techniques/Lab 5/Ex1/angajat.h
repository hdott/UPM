#pragma once


class Angajat{
    private:
        double tarifOrar;
        int nrOre;

    public:
        Angajat(double tO = 5.5, int nO = 0) : tarifOrar(tO), nrOre(nO){};
        virtual double getSalar() const {return tarifOrar * nrOre;};
        double getTarifOrar() const {return tarifOrar;};
};