#pragma once


class StackAbstract{
    public:
        virtual void push(int) = 0;
        virtual int pop(void) = 0;
        virtual int peek(void) = 0;
        virtual bool isEmpty(void) = 0;
        virtual void print(void) = 0;
};