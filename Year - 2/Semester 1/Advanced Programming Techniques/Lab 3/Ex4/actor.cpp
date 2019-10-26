#include <iostream>
#include "actor.h"


int Actor::nrActori = 0;

        
bool Actor::operator==(const Actor &actor){
    if(nume.compare(actor.nume) == 0){
        return true;
    }

    return false;
}

std::ostream& operator<<(std::ostream &os, const Actor &actor){
    os << actor.nume << ", " << actor.prenume << " - " << actor.varsta;

    return os;
}

std::istream& operator>>(std::istream &is, Actor &actor){
    std::cout << "Introduceti numele prenume si varsta actorului:\n";
    std::cout << "Nume: ";
    getline(is, actor.nume);
    std::cout << "Prenume: ";
    getline(is, actor.prenume);
    std::cout << "Varsta: ";
    is >> actor.varsta;

    return is;
}