#pragma once
#include "punct2d.h"


class Punct3D : public Punct2D{
    private:
        double z;

    public:
        Punct3D(double x = 0, double y = 0, double z = 0) : Punct2D(x, y), z(z){};
        Punct3D(const Punct2D & p, double z = 0) : Punct2D(p), z(z){};
        // Punct3D(const Punct3D & p); // implicit suffices
        // ~Punct3D();                 // implicit suffices

        // Punct3D & operator=(const Punct3D & p); // implicit suffices
        double distanta(const Punct3D & p) const;
        bool operator<(const Punct3D & p) const;
        bool operator<=(const Punct3D & p) const;
        bool operator>(const Punct3D & p) const;
        bool operator>=(const Punct3D & p) const;
        bool operator==(const Punct3D & p) const;
        bool operator!=(const Punct3D & p) const;
        Punct3D operator+(const Punct3D & p) const;
        Punct3D operator-(const Punct3D & p) const;
        Punct3D operator*(const Punct3D & p) const;
        Punct3D operator/(const Punct3D & p) const;
        Punct3D & operator+=(const Punct3D & p);
        Punct3D & operator-=(const Punct3D & p);
        Punct3D & operator*=(const Punct3D & p);
        Punct3D & operator/=(const Punct3D & p);
        Punct3D & operator++();
        Punct3D operator++(int n);
        Punct3D & operator--();
        Punct3D operator--(int n);

        friend std::ostream & operator<<(std::ostream & os, const Punct3D & p);
        friend std::istream & operator>>(std::istream & is, Punct3D & p);
};