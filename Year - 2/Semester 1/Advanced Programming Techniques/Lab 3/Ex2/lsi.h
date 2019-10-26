#pragma once
#include <iostream>
#include "nod.h"

class Nod;
class LSI{
    private:
        Nod *head;
        Nod *tail;

    public:
        LSI(Nod *head = NULL, Nod *tail = NULL):head(head), tail(tail){};
        // ~LSI();

        void add(Nod *nod);
        bool isEmpty() const;
        bool remove(Nod *nod);
        
        friend std::ostream& operator<<(std::ostream &os, const LSI &lsi);
};