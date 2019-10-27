#include <iostream>
#include <cmath>
#include "complex.h"


Complex::Complex(const Complex &cp){
    this->re = cp.re;
    this->im = cp.im;
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