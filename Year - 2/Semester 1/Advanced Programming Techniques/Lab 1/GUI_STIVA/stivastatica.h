#pragma once
#ifndef STIVASTATICA_H
#define STIVASTATICA_H

using namespace std;

class Stack
{
public:
    Stack() {};
    virtual void push(int) = 0;
    virtual int pop() = 0;
    virtual int peek() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual void print() = 0;

    class Stack_Overflow{};
    class Stack_Underflow{};
};

class Array_Stack: public Stack
{
private:
    int *vector;
    int top;
    int max;

public:
    Array_Stack(int max=100);
    Array_Stack(const Array_Stack&);
    ~Array_Stack();

    virtual void push(int x);
    virtual int pop();
    virtual int peek();
    virtual bool isEmpty();
    virtual bool isFull();
    virtual void print();
    virtual int PeekItem(int x);
    virtual int Iterator();
};

#endif // STIVASTATICA_H
