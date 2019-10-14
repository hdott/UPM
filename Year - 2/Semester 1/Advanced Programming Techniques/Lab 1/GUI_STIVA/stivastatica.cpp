#include "stivastatica.h"
#include <iostream>

using namespace std;


Array_Stack::Array_Stack(int max){
    this->max = max;
    this->top = 0;
    this->vector = new int[max];
}

Array_Stack::~Array_Stack(){
    this->top = 0;
    this->max = 0;
    delete []this->vector;
}

void Array_Stack:: push(int x){
    vector[top++] = x;
}

int Array_Stack:: pop(){
    return vector[top--];
}

int Array_Stack:: peek(){
    return vector[top-1];
}

bool Array_Stack:: isEmpty(){
    if(top == 0){
        return true;
    } else{
        return false;
    }
}

bool Array_Stack:: isFull(){
    if(top == max){
        return true;
    } else{
        return false;
    }
}

void Array_Stack:: print(){
    for( ; top>=0; --top){
        std::cout << vector[top] << std::endl;
        vector[top] = 0;
    }
}

int Array_Stack:: PeekItem(int i){
    return vector[i];
}

int Array_Stack:: Iterator(){
    return top-1;
}
