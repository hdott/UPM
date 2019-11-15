#pragma once
#include <fstream>


template <class T>
class LSI{
    private:
        struct Node{
            T elem;
            struct Node *next;
        };
        Node *head = nullptr;
        Node *tail = nullptr;

        Node* getNext(Node *node) const{return node->next;}
        const T & getElem(Node *node) const{return node->elem;}
        
    public:
        LSI(void){};
        LSI(const LSI<T> & list);
        ~LSI();

        void add(T e);
        bool isEmpty(void) const;
        LSI<T> & operator=(const LSI<T> & list);
        bool operator==(const LSI<T> & list) const;
        friend std::ostream & operator<<(std::ostream & os, const LSI<T> & list){
            Node *tracer = list.head;

            os << "Lista: ";
            while(tracer){
                os << list.getElem(tracer) << " ";
                tracer = list.getNext(tracer);
            }

            return os;
        }
        friend std::istream & operator>>(std::istream & is, LSI<T> & list){
            std::cout << "el: ";
            T el;
            is >> el;
            list.add(el);

            return is;
        };
};
#include "lsi.cpp"