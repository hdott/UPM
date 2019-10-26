#include "carte.h"


// !!! this only checks whether the authors are equal
bool Carte::operator==(const Carte &carte){
    if(autor.compare(carte.autor) == 0){
        return true;
    }

    return false;
}

ostream& operator<<(ostream &os, const Carte &carte){
    os << carte.nume << ", " << carte.autor << " ["
        << carte.ISBN << "] - " << carte.pret;

    return os;
}

istream& operator>>(istream &is, Carte &carte){
    std::cout << "Nume: ";
    is >> carte.nume;
    std::cout << "Autor: ";
    is >> carte.autor;
    std::cout << "ISBN: ";
    is >> carte.ISBN;
    std::cout << "Pret: ";
    is >> carte.pret;

    return is;
}