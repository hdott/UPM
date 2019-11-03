#include "arraystack.h"


ArrayStack::ArrayStack(int cap) : capacitate(cap){
    vect = new int[capacitate];
}

ArrayStack::~ArrayStack(){
    delete[] vect;
}

ArrayStack::ArrayStack(const ArrayStack & ar){
    vect = new int[ar.capacitate];
    for(int i = 0; i < ar.top; ++i){
        vect[i] = ar.vect[i];
    }
    capacitate = ar.capacitate;
    top = ar.top;
}

ArrayStack & ArrayStack::operator=(const ArrayStack & ar){
    if(this == &ar){
        return *this;
    }

    delete[] vect;
    vect = new int[ar.capacitate];
    for(int i = 0; i < ar.top; ++i){
        vect[i] = ar.vect[i];
    }
    capacitate = ar.capacitate;
    top = ar.top;

    return *this;
}

void ArrayStack::push(int x){
    if(!isFull()){
        vect[top++] = x;
    }
}

int ArrayStack::pop(void){
    if(!isEmpty()){
        return vect[--top];
    }
    return 0;
}

int ArrayStack::peek(void){
    if(!isEmpty()){
        return vect[top-1];
    }
    return 0;
}

bool ArrayStack::isEmpty(void){
    if(top == 0){
        return true;
    }
    return false;
}

bool ArrayStack::isFull(void){
    if(top >= capacitate){
        return true;
    }
    return false;
}

void ArrayStack::print(void){
    for(int i = 0; i < top; ++i){
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}

std::ostream & operator<<(std::ostream & os, ArrayStack & ar){
    int * vect = ar.getVect();
    for(int i = 0; i < ar.getCap(); ++i){
        os << vect[i] << " ";
    }

    return os;
}

std::istream & operator>>(std::istream & is, ArrayStack & ar){
    for(int i = 0; i < ar.getCap(); ++i){
        std::cout << "Enter int: ";
        int tmp;
        is >> tmp;
        ar.push(tmp);
    }

    return is;
}