#include "nod.h"


bool Nod::operator==(const Nod &nod) const{
    if(nr == nod.nr){
        return true;
    } else{
        return false;
    }
}

std::ostream& operator<<(std::ostream &os, const Nod &nod){
    os << nod.nr;

    return os;
}

std::istream& operator>>(std::istream &is, Nod &nod){
    is >> nod.nr;

    return is;
}