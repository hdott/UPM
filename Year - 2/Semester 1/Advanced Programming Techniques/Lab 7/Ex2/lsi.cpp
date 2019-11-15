#include "lsi.h"


template <class T>
LSI<T>::LSI(const LSI<T> & list){
    head = new Node(list.head->elem);
    
    Node *tracer = list.head->next;
    while(tracer){
        tail = tail->next = new Node(tracer->elem);
        tracer = tracer->next;
    }
}

template <class T>
LSI<T>::~LSI(){
    Node *tracer = head;
    Node *_toDelete;

    while(tracer){
        _toDelete = tracer;
        tracer = tracer->next;
        delete[] _toDelete;
    }
}

template <class T>
void LSI<T>::add(T e){
    if(isEmpty()){
        head = tail = new Node{e, nullptr};
    } else{
        tail = tail->next = new Node{e, nullptr};
    }
}

template <class T>
bool LSI<T>::isEmpty(void) const{
    if(!head){
        return true;
    }
    
    return false;
}

template <class T>
LSI<T> & LSI<T>::operator=(const LSI<T> & list){
    if(this == &list){
        return *this;
    }

    Node *_toDelete;
    while(head){
        _toDelete = head;
        head = head->next;

        delete[] _toDelete;
    }


    head = new Node(list.head->elem);
    
    Node *tracer = list.head->next;
    while(tracer){
        tail = tail->next = new Node(tracer->elem);
        tracer = tracer->next;
    }

    return *this;
}

template <class T>
bool LSI<T>::operator==(const LSI<T> & list) const{
    Node *tr1 = head,
        *tr2 = list.head;

    while(tr1 && tr2){
        if(tr1->elem != tr2->elem){
            return false;
        }
        
        tr1 = tr1->next;
        tr2 = tr2->next;
    }
    
    return true;
}