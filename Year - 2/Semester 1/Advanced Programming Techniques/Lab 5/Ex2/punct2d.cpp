#include <cmath>
#include "punct2d.h"


double Punct2D::distanta(const Punct2D & p) const{
    return (sqrt(pow(p.x - x, 2) + pow(p.y - y, 2)));
}

bool Punct2D::operator<(const Punct2D & p) const{
    return (x < p.x && y < p.y);
}

bool Punct2D::operator<=(const Punct2D & p) const{
    return (x <= p.x && y <= p.y);
}

bool Punct2D::operator>(const Punct2D & p) const{
    return (x > p.x && y > p.y);
}

bool Punct2D::operator>=(const Punct2D & p) const{
    return (x >= p.x && y >= p.y);
}

bool Punct2D::operator==(const Punct2D & p) const{
    return (x == p.x && y == p.y);
}

bool Punct2D::operator!=(const Punct2D & p) const{
    return (x != p.x || y != p.y);
}

Punct2D Punct2D::operator+(const Punct2D & p) const{
    return Punct2D(x + p.x, y + p.y);
}

Punct2D Punct2D::operator-(const Punct2D & p) const{
    return Punct2D(x - p.x, y - p.y);
}

Punct2D Punct2D::operator*(const Punct2D & p) const{
    return Punct2D(x * p.x, y * p.y);
}

Punct2D Punct2D::operator/(const Punct2D & p) const{
    return Punct2D(x / p.x, y / p.y);
}

Punct2D & Punct2D::operator+=(const Punct2D & p){
    x += p.x;
    y += p.y;

    return *this;
}

Punct2D & Punct2D::operator-=(const Punct2D & p){
    x -= p.x;
    y -= p.y;

    return *this;
}

Punct2D & Punct2D::operator*=(const Punct2D & p){
    x *= p.x;
    y *= p.y;

    return *this;
}

Punct2D & Punct2D::operator/=(const Punct2D & p){
    x /= p.x;
    y /= p.y;

    return *this;
}

Punct2D & Punct2D::operator++(){
    ++x;
    ++y;

    return *this;
}

Punct2D Punct2D::operator++(int n){
    Punct2D tmp(x, y);
    
    if(n == 0){
        x++;
        y++;
        return tmp;
    }
    x += n;
    y += n;

    return tmp;
}

Punct2D & Punct2D::operator--(){
    --x;
    --y;

    return *this;
}

Punct2D Punct2D::operator--(int n){
    Punct2D tmp(x, y);

    if(n == 0){
        x--;
        y--;
        return tmp;
    }
    x -= n;
    y -= n;

    return tmp;
}

std::ostream & operator<<(std::ostream & os, const Punct2D & p){
    os << "Punct2D (" << p.x << ", " << p.y << ")";

    return os;
}

std::istream & operator>>(std::istream & is, Punct2D & p){
    is >> p.x >> p.y;

    return is;
}