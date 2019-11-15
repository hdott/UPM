#pragma once
#include "persoana.h"


class Profesor : public Persoana{
    private:
        std::string email,
                    materie;

    public:
        Profesor(std::string nume, std::string CNP, std::string email, std::string materie) :
                    Persoana(nume, CNP), email(email), materie(materie){};
        Profesor(Persoana & p, std::string email, std::string materie) : Persoana(p),
                    email(email), materie(materie){};

        std::string getMaterie(void) const{return materie;};
        virtual std::string detalii(void) const;
};

std::string Profesor::detalii() const{
    return ("Profesorul " + Persoana::getNume() + " preda " + materie + ".");
}