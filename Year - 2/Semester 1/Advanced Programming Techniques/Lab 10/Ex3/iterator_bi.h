#pragma once
#include <iterator>
#include "nod.h"


template<class T>
class iterator_bi : public iterator<bidirectional_iterator_tag, T>{
    private:
        Nod<T> 
};