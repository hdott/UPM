#pragma once
#include "listaD.h"


template<class T>
class Nod{
    private:
        Nod *prev;
        Nod *next;
        T value;
    public:
        friend class ListaD,
                    iterator_fw,
                    iterator_rw;

        Nod() = default;
        Nod(T value, Nod *prev, Nod *next = nullptr) : value(value), prev(prev), 
                                                    next(next){};

        // T getValue() const;
        // Nod & getPrev() const;
        // Nod & getNext() const;
};