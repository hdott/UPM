#pragma once
#include <iostream>
using namespace std;


class Carte{
    private:
        string autor,
                nume,
                ISBN;
        double pret;

    public:
        Carte(string autor="autor", string nume="nume", string ISBN="isbn", double pret=0.0):
                autor(autor), nume(nume), ISBN(ISBN), pret(pret){};
        // ~Carte();

        void setAutor(const string autor){this->autor = autor;};
        void setNume(const string nume){this->nume = nume;};
        void setISBN(const string ISBN){this->ISBN = ISBN;};
        void setPret(double pret){this->pret = pret;};
        string getAutor()const{return autor;};
        string getNume()const{return nume;};
        string getISBN()const{return ISBN;};
        double getPret()const{return pret;};
        // !!! this only checks whether the authors are equal
        bool operator==(const Carte &carte);

        friend ostream& operator<<(ostream &os, const Carte &carte);
        friend istream& operator>>(istream &is, Carte &carte);
};