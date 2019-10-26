#include <iostream>
#include "lsi.h"


// LSI::~LSI(){
//     Nod *tracer = head;

//     while(tracer){
//         Nod *_toRemove = tracer;
//         tracer = tracer->next;

//         _toRemove->~Nod();
//     }
// }

void LSI::add(Nod *nod){
    if(isEmpty()){
        head = tail = nod;
    } else{
        tail->next = nod;
        tail = nod;
    }
}

bool LSI::isEmpty() const{
    if(head == NULL){
        return true;
    } else{
        return false;
    }
}

bool LSI::remove(Nod *nod){
    if(*head == *nod){
        head = nod->next;
    } else{
        Nod *tracer = head;

        while(tracer->next){
            if(*tracer->next == *nod){
                Nod *_toRemove = tracer->next;
                tracer->next = tracer->next->next;

                // _toRemove->~Nod();
                nod->~Nod();
                return true;
            }
            tracer = tracer->next;
        }
    }

    return false;
}

std::ostream& operator<<(std::ostream &os, const LSI &lsi){
    Nod *tracer = lsi.head;

    while(tracer){
        os << *tracer << ", ";
        tracer = tracer->getNext();
    }

    return os;
}