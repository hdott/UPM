#pragma once
#include "listaD.h"
#include "iterator_bi.h"


template<class T>
class Nod{
    private:
        Nod *prev;
        Nod *next;
        T value;
    public:
        friend class ListaD;
        friend class iterator_bi;

        Nod() = default;
        Nod(T value, Nod *prev, Nod *next = nullptr) : value(value), prev(prev), 
                                                    next(next){};

        // T getValue() const;
        // Nod & getPrev() const;
        // Nod & getNext() const;
};