#pragma once
#include "persoana.h"


class Angajat : public Persoana{
    private:
        std::string email,
                    dep;

    public:
        Angajat(std::string nume, std::string CNP, std::string email, std::string dep) :
                        Persoana(nume, CNP), email(email), dep(dep){};
        Angajat(Persoana & p, std::string email, std::string dep) : Persoana(p),
                        email(email), dep(dep){};

        std::string getDepartament(void) const{return dep;};
        virtual std::string detalii(void) const;
};

std::string Angajat::detalii() const{
    return ("Angajatul " + Persoana::getNume() + " face parte din departamentul " + 
                dep + ".");
}