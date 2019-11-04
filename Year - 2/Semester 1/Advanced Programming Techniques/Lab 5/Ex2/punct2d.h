#pragma once
#include <iostream>


class Punct2D{
    private:
        double x,
                y;

    public:
        Punct2D(double x = 0, double y = 0) : x(x), y(y){};
        // Punct2D(const Punct2D & p);  // implicit suffices
        // ~Punct2D();                  // implicit suffices

        // Punct2D & operator=(const Punct2D & p);  // implicit suffices
        double getX(void) const {return x;};
        double getY(void) const {return y;};
        virtual double distanta(const Punct2D & p) const;
        virtual bool operator<(const Punct2D & p) const;
        virtual bool operator<=(const Punct2D & p) const;
        virtual bool operator>(const Punct2D & p) const;
        virtual bool operator>=(const Punct2D & p) const;
        virtual bool operator==(const Punct2D & p) const;
        virtual bool operator!=(const Punct2D & p) const;
        virtual Punct2D operator+(const Punct2D & p) const;
        virtual Punct2D operator-(const Punct2D & p) const;
        virtual Punct2D operator*(const Punct2D & p) const;
        virtual Punct2D operator/(const Punct2D & p) const;
        virtual Punct2D & operator+=(const Punct2D & p);
        virtual Punct2D & operator-=(const Punct2D & p);
        virtual Punct2D & operator*=(const Punct2D & p);
        virtual Punct2D & operator/=(const Punct2D & p);
        virtual Punct2D & operator++();
        virtual Punct2D operator++(int n);
        virtual Punct2D & operator--();
        virtual Punct2D operator--(int n);

        friend std::ostream & operator<<(std::ostream & os, const Punct2D & p);
        friend std::istream & operator>>(std::istream & is, Punct2D & p);
};