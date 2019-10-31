#include <iostream>
#include <cmath>
#include "complex.h"


Complex::Complex(const Complex &cp){
    this->re = cp.re;
    this->im = cp.im;
}

Complex Complex::operator=(const Complex& cp){
    if(this == &cp){
        return *this;
    }

    this->re = cp.re;
    this->im = cp.im;

    return *this;
}

Complex Complex::operator+(const Complex & cp) const{
    return Complex(re + cp.im, im + cp.im);
}

Complex Complex::operator-(const Complex & cp) const{
    return Complex(re - cp.re, im - cp.im);
}

Complex Complex::operator*(const Complex & cp) const{
    return Complex((re * cp.re) - (im * cp.im),
                    (re * cp.im) + (im * cp.re));
}

Complex Complex::operator/(const Complex & cp) const{
    Complex num = *this * (~cp);
    Complex den = cp * (~cp);
    double denominator = den.re + den.im;

    return Complex(num.re / denominator, num.im / denominator);
}

Complex Complex::operator+=(const Complex& cp){
    return *this + cp;
}

Complex Complex::operator-=(const Complex& cp){
    return *this - cp;
}

Complex Complex::operator*=(const Complex& cp){
    return *this * cp;
}

Complex Complex::operator/=(const Complex& cp){
    return *this / cp;
}

Complex Complex::operator++(){
    this->re++;
    return *this;
}

Complex Complex::operator++(int n){
    Complex tmp(re, im);

    if(n == 0){
        this->re++;
    } else{
        this->re += n;
    }

    return tmp;
}

Complex Complex::operator--(){
    return *this - Complex(1);
}

Complex Complex::operator--(int n){
    Complex tmp(re, im);

    if(n == 0){
        this->re--;
    } else{
        this->re -= n;
    }

    return tmp;
}

Complex::operator int() const{
    return Complex((int) re, (int) im);
}

bool Complex::operator<(const Complex & fr) const{
    return (modul(*this) < modul(fr));
}

bool Complex::operator>(const Complex & fr) const{
    return (modul(*this) > modul(fr));
}

bool Complex::operator<=(const Complex & fr) const{
    return (modul(*this) <= modul(fr));
}

bool Complex::operator>=(const Complex & fr) const{
    return (modul(*this) >= modul(fr));
}

bool Complex::operator!=(const Complex & fr) const{
    return (modul(*this) != modul(fr));
}
    
bool Complex::operator==(const Complex & fr) const{
    return (modul(*this) == modul(fr));
}

Complex operator~(const Complex &cp){
    return Complex(cp.re, -cp.im);
}

std::ostream& operator<<(std::ostream &os, const Complex &cp){
    os << "(" << cp.re << "," <<  cp.im << " i)";

    return os;
}

std::istream& operator>>(std::istream &is, Complex &cp){
    is >> cp.re >> cp.im;

    return is;
}

double modul(const Complex &cp){
    return sqrt((pow(cp.re,2)+pow(cp.im,2)));
}