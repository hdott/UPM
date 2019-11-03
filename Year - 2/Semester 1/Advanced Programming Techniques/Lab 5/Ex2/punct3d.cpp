#include <cmath>
#include "punct3d.h"


double Punct3D::distanta(const Punct3D & p) const{
    return (sqrt(pow(p.getX() - getX(), 2) + pow(p.getY() - getY(), 2) +
            pow(p.z - z, 2)));
}

bool Punct3D::operator<(const Punct3D & p) const{
    return (z < p.z && Punct2D::operator<(p));
}

bool Punct3D::operator<=(const Punct3D & p) const{
    return (z <= p.z && Punct2D::operator<=(p));
}

bool Punct3D::operator>(const Punct3D & p) const{
    return (z > p.z && Punct2D::operator>(p));
}

bool Punct3D::operator>=(const Punct3D & p) const{
    return (z >= p.z && Punct2D::operator>=(p));
}

bool Punct3D::operator==(const Punct3D & p) const{
    return (z == z && Punct2D::operator==(p));
}

bool Punct3D::operator!=(const Punct3D & p) const{
    return (z != z || Punct2D::operator!=(p));
}

Punct3D Punct3D::operator+(const Punct3D & p) const{
    return Punct3D(Punct2D::operator+(p), z + p.z);
}

Punct3D Punct3D::operator-(const Punct3D & p) const{
    return Punct3D(Punct2D::operator-(p), z - p.z);
}

Punct3D Punct3D::operator*(const Punct3D & p) const{
    return Punct3D(Punct2D::operator*(p), z * p.z);
}

Punct3D Punct3D::operator/(const Punct3D & p) const{
    return Punct3D(Punct2D::operator/(p), z / p.z);
}

Punct3D & Punct3D::operator+=(const Punct3D & p){
    Punct2D::operator+=(p);
    z += p.z;

    return *this;
}

Punct3D & Punct3D::operator-=(const Punct3D & p){
    Punct2D::operator-=(p);
    z -= p.z;

    return *this;
}

Punct3D & Punct3D::operator*=(const Punct3D & p){
    Punct2D::operator*=(p);
    z *= p.z;

    return *this;
}

Punct3D & Punct3D::operator/=(const Punct3D & p){
    Punct2D::operator/=(p);
    z /= p.z;

    return *this;
}

Punct3D & Punct3D::operator++(){
    Punct2D::operator++();
    ++z;

    return *this;
}

Punct3D Punct3D::operator++(int n){
    Punct3D tmp(Punct2D::operator++(n), z);
    if(n == 0){
        z++;
        return tmp;
    }
    z += n;
    
    return tmp;
}

Punct3D & Punct3D::operator--(){
    Punct2D::operator--();
    --z;

    return *this;
}

Punct3D Punct3D::operator--(int n){
    Punct3D tmp(Punct2D::operator--(n), z);
    if(n == 0){
        z--;
        return tmp;
    }
    z -= n;

    return tmp;
}

std::ostream & operator<<(std::ostream & os, const Punct3D & p){
    os << "Punct3D (" << p.getX() << ", " << p.getY() << ", " << p.z << ")";

    return os;
}

std::istream & operator>>(std::istream & is, Punct3D & p){
    is >> (Punct2D &) p >> p.z;

    return is;
}