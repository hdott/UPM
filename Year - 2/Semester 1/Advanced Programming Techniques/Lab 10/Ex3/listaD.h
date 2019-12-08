#pragma once
#include "nod.h"


template<class T>
class ListaD{
    private:
        Nod *head;
        Nod *tail;

    public:
        ListaD(Nod *head = nullptr, Nod *tail = nullptr) : head(head), tail(tail){};
        ListaD(const ListaD &);
        ~ListaD();

        ListaD & operator=(const ListaD &);
        bool operator==(const ListaD &) const;
        bool operator<(const ListaD &) const;
        bool emtpy();
        T front();
        T back();
        void push_back(T);
        void push_front(T);
        T pop_back();
        T pop_front();
        void insert(T, iterator& pos = nullptr);
        void erase(T);
        void sort();
        void merge(const ListaD &);
        iterator_fw begin();
        iterator_fw end();
        iterator_rw rbegin();
        iterator_rw rend();
};