#pragma once
#include <iostream>
#include "stakcabc.h"


class ArrayStack : public StackAbstract{
    private:
        int top = 0;
        int capacitate;
        int *vect = nullptr;

    public:
        ArrayStack(int cap = 0);
        ~ArrayStack();
        ArrayStack(const ArrayStack & ar);

        ArrayStack & operator=(const ArrayStack & ar);
        void push(int x);
        int pop(void);
        int peek(void);
        bool isEmpty(void);
        bool isFull(void);
        void print(void);
        int getCap(void) const {return capacitate;};
        int * getVect(void) const {return vect;};

        friend std::ostream & operator<<(std::ostream & os, const ArrayStack & ar);
        friend std::istream & operator>>(std::istream & is, ArrayStack & ar);
};