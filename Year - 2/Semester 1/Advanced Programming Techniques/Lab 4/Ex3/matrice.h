#pragma once
#include <iostream>

class Matrice{
    private:
        int row;
        int col;
        int **vect;
    
    public:
        Matrice(int row = 0, int col = 0, int **vector = nullptr): row(row), col(col),
                                                                vect(vect){
            vect = new int*[row];
            for(int i = 0; i < row; ++i){
                vect[i] = new int[col];
            }
        };
        Matrice(const Matrice &);
        ~Matrice();

        Matrice operator+(const Matrice &) const;
        Matrice operator-(const Matrice &) const;
        Matrice operator*(const Matrice &) const;
        // Matrice operator/(const Matrice &) const;
        Matrice operator+(const int) const;
        Matrice operator-(const int) const;
        Matrice operator*(const int) const;
        Matrice operator/(const int) const;
        // bool operator<(const Matrice &) const;
        // bool operator>(const Matrice &) const;
        // bool operator<=(const Matrice &) const;
        // bool operator>=(const Matrice &) const;
        bool operator!=(const Matrice &) const;
        bool operator==(const Matrice &) const;
        Matrice operator+=(const Matrice &) const;
        Matrice operator-=(const Matrice &) const;
        Matrice operator*=(const Matrice &) const;
        Matrice operator/=(const Matrice &) const;
        Matrice operator+=(const int) const;
        Matrice operator-=(const int) const;
        Matrice operator*=(const int) const;
        Matrice operator/=(const int) const;
        Matrice operator++();
        Matrice operator++(int);
        Matrice operator--();
        Matrice operator--(int);
        Matrice operator=(const Matrice &);
        int* operator[](int) const;

        // friend Matrice operator+(const Matrice &, const Matrice &);
        // friend Matrice operator-(const Matrice &, const Matrice &);
        // friend Matrice operator*(const Matrice &, const Matrice &);
        // friend Matrice operator/(const Matrice &, const Matrice &);
        friend Matrice operator+(const int, const Matrice &);
        friend Matrice operator-(const int, const Matrice &);
        friend Matrice operator*(const int, const Matrice &);
        // friend Matrice operator/(const int, const Matrice &);
        // friend Matrice operator+=(const Matrice &, const Matrice &);
        // friend Matrice operator-=(const Matrice &, const Matrice &);
        // friend Matrice operator*=(const Matrice &, const Matrice &);
        // friend Matrice operator/=(const Matrice &, const Matrice &);
        // friend Matrice operator+=(const int, const Matrice &);
        // friend Matrice operator-=(const int, const Matrice &);
        // friend Matrice operator*=(const int, const Matrice &);
        // friend Matrice operator/=(const int, const Matrice &);
        friend std::ostream & operator<<(std::ostream &, const Matrice &);
        friend std::istream & operator>>(std::istream &, const Matrice &);
};