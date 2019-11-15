#include "tablou.h"


template <class T>
Tablou<T>::Tablou(int size) : size(size){
    vect = new T[size];
}

template <class T>
Tablou<T>::Tablou(const Tablou<T> & t){
    size = t.size;
    vect = new T[size];

    for(int i = 0; i < size; ++i){
        this[i] = t[i];
    }
}

template <class T>
Tablou<T>::~Tablou(){
    delete[] vect;
}

template <class T>
Tablou<T> & Tablou<T>::operator=(const Tablou<T> & t){
    if(this == &t){
        return *this;
    }

    delete[] vect;
    size = t.size;
    vect = new T[size];

    for(int i = 0; i < size; ++i){
        this[i] = t[i];
    }
    return *this;
}

template <class T>
const T & Tablou<T>::operator[](int i) const{
    return vect[i];
}

template <class T>
T & Tablou<T>::operator[](int i){
    return vect[i];
}


template<> Tablou<char>::Tablou(int size){
    vect = new char[size];
    vect[0] = '\0';
    vect[size-1] = '\0';
}

// std::ostream & operator<<(std::ostream & os, const Tablou<char> & t){
//     os << t;

//     return os;
// }

// std::istream & operator>>(std::istream & is, Tablou<char> & t){
//     is.getline(t.vect, t.size);

//     return is;
// }