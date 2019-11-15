#pragma once
#include <fstream>


template <class T>
class Tablou{
    private:
        T *vect = nullptr;
        int size;
    
    public:
        Tablou(int size);
        Tablou(const Tablou<T> & t);
        ~Tablou();

        Tablou<T> & operator=(const Tablou<T> & t);
        const T & operator[](int i) const;
        T & operator[](int i);
        friend std::ostream & operator<<(std::ostream & os, const Tablou<T> & t){
            for(int i = 0; i < t.size; ++i){
                os << t[i] << " ";
            }
            return os;
        }
        friend std::istream & operator>>(std::istream & is, Tablou<T> & t){
            for(int i = 0; i < t.size; ++i){
                std::cout << "[" << i << "]: ";
                is >> t[i];
            }
            return is;
        }
};

#include "tablou.cpp"