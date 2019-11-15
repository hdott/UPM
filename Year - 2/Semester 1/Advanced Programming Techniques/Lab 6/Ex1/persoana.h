#pragma once
#include <iostream>


class Persoana{
    private:
        std::string nume,
                    CNP;

    protected:
        std::string getNume(void) const{return nume;};

    public:
        Persoana(std::string nume, std::string CNP) : nume(nume), CNP(CNP){};

        virtual std::string detalii(void) const = 0;                
};

std::string Persoana::detalii() const{
    std::string tmp;
    tmp = nume;
    tmp += " - ";
    tmp += CNP;

    return tmp;
}