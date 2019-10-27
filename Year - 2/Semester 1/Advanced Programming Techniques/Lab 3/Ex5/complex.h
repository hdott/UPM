#pragma once
#include <iostream>


class Complex{
    private:
        double re,
                im;

    public:
        Complex(double re=0.0, double im=0.0): re(re), im(im){};
        Complex(const Complex &cp);
        // ~Complex();

        Complex operator+(const Complex& cp) const;
        Complex operator-(const Complex& cp) const;
        Complex operator*(const Complex& cp) const;
        friend Complex operator~(const Complex &cp);
        friend std::ostream& operator<<(std::ostream &os, const Complex &cp);
        friend std::istream& operator>>(std::istream &is, Complex &cp);

        friend double modul(const Complex &cp);
};