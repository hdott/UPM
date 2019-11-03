#pragma once
#include <iostream>
#include "stakcabc.h"


class ListStack : public StackAbstract{
    public:
        class Node{
            protected:
                int info;
                Node *next;
            
            public:
                Node(int x = 0, Node *n = nullptr) : info(x), next(n){};
                Node* getNext(void) const {return next;}
                void  setNext(Node *next) {this->next = next;};
                int getInfo(void) const {return info;};
        };

    private:
        Node *top;

    public:
        ListStack(int x = 0, Node *t = nullptr);
        ~ListStack();
        ListStack(const ListStack & ls);

        ListStack & operator=(const ListStack & ls);
        void push(int x);
        int pop(void);
        int peek(void);
        bool isEmpty(void);
        void print(void);
        Node* getTop(void) const {return top;};

        // friend std::ostream & operator<<(std::ostream & os, const ListStack & ar);
        // friend std::istream & operator>>(std::istream & is, ListStack & ar);
};