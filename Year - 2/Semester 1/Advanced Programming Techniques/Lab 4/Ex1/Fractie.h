#pragma once
#include <iostream>


class Fractie{
    private:
        int numitor,
            numarator;
    public:
        Fractie(int numarator=0, int numitor=1): numarator(numarator), numitor(numitor){};
        Fractie(const Fractie&);
        ~Fractie();

        // virtual Fractie aduna(Fractie);
        // virtual Fractie scadere(Fractie);
        // virtual Fractie inmultire(Fractie);
        // virtual Fractie impartire(Fractie);
        static int cmmdc(int, int);
        Fractie simplifica();
         Fractie reciproc();
        // virtual bool egal(const Fractie&);
        // virtual void print();

        Fractie operator+(const Fractie & fr) const;
        template <typename T> Fractie operator+(const T nr) const{
            return Fractie(numarator * 1 + numitor * nr, numitor * 1);
        }
        template <typename T> friend Fractie operator+(const T nr, const Fractie & fr){
            return fr + nr;
        }

        Fractie operator-(const Fractie & fr) const;
        template <typename T> Fractie operator-(const T nr) const{
            return Fractie(numarator * 1 - numitor * nr, numitor * 1);
        }
        template <typename T> friend Fractie operator-(const T nr, const Fractie & fr){
            return Fractie(nr * fr.numitor - 1 * fr.numarator, 1 * fr.numitor);
        }

        Fractie operator*(const Fractie & fr) const;
        template <typename T> Fractie operator*(const T nr) const{
            return Fractie(numarator * nr, numitor * 1);
        }
        template <typename T> friend Fractie operator*(const T nr, const Fractie & fr){
            return fr * nr;
        }

        Fractie operator/(const Fractie & fr) const;
        template <typename T> Fractie operator/(const T nr) const{
            return Fractie(numarator * 1, numitor * nr);
        }
        template <typename T> friend Fractie operator/(const T nr, const Fractie & fr){
            return Fractie(nr * fr.numitor, 1 * fr.numarator);
        }

        Fractie operator+=(const Fractie & fr) const{
            return *this+fr;
        }
        template <typename T> Fractie operator+=(const T nr){
            return *this+nr;
        }

        Fractie operator-=(const Fractie & fr){
            return *this-fr;
        }
        template <typename T> Fractie operator-=(const T nr){
            return *this-nr;
        }

        Fractie operator*=(const Fractie & fr){
            return *this*fr;
        }
        template <typename T> Fractie operator*=(const T nr){
            return *this*nr;
        }

        Fractie operator/=(const Fractie & fr){
            return *this/fr;
        }
        template <typename T> Fractie operator/=(const T nr){
            return *this/nr;
        }

        Fractie operator=(const Fractie & fr);
        Fractie operator++();
        Fractie operator++(int n);
        Fractie operator--();
        Fractie operator--(int n);
        template <typename T>
        operator T() const{
            return (T) (double(numarator) / numitor);
        }

        bool operator<(const Fractie & fr) const;
        bool operator>(const Fractie & fr) const;
        bool operator<=(const Fractie & fr) const;
        bool operator>=(const Fractie & fr) const;
        bool operator!=(const Fractie & fr) const;
        bool operator==(const Fractie & fr) const;

        friend std::ostream & operator<<(std::ostream & os, const Fractie & fr);
        friend std::istream & operator>>(std::istream & is, Fractie & fr);
        
};