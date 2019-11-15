#pragma once
#include <sstream>
#include "persoana.h"


class Student : public Persoana{
    private:
        std::string email;
        double nota;

    public:
        Student(std::string nume, std::string CNP, std::string email, double nota) :
                Persoana(nume, CNP), email(email), nota(nota){};
        Student(const Persoana & p, std::string email, double nota) : Persoana(p),
                email(email), nota(nota){};

        double getNota(void) const{return nota;};
        virtual std::string detalii(void) const; 
};

std::string Student::detalii() const{
    std::ostringstream strs;
    strs << nota;
    std::string tmp = "Studentul " + Persoana::getNume() + " are nota " +
                        strs.str() + ".";

    return tmp;
}