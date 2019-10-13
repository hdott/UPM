#include "stivastatica.h"
#include <iostream>

using namespace std;

Array_Stack:: Array_Stack(int max){
    this->max = max;
    this->top = 0;
    this->vector = new int[max];
}

Array_Stack::~Array_Stack(){
    this->top = 0;
    this->max = 0;
    delete []this->vector;
}
