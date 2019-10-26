#pragma once
#include <iostream>
#include "lsi.h"


class Nod{
    public:
        friend class LSI;

    private:
        int nr;
        Nod *next;

    public:
        Nod(int nr=0, Nod *next=NULL):nr(nr), next(next){};
        ~Nod(){delete next;};

        void setNr(int nr){this->nr = nr;};
        void setNext(Nod *next){this->next = next;};
        int getNr() const{return nr;};
        Nod* getNext() const{return next;};
        bool operator==(const Nod &nod) const;

        friend std::ostream& operator<<(std::ostream &os, const Nod &nod);
        friend std::istream& operator>>(std::istream &is, Nod &nod);
};