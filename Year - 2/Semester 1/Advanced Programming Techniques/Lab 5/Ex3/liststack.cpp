#include "liststack.h"


ListStack::ListStack(int x, Node *t){
    if(t == nullptr){
        top = new Node(x);
    } else{
        top = new Node(x);
        top->setNext(new Node(x));
    }
}

ListStack::~ListStack(){
    while(top){
        Node *tmp = top;
        top = top->getNext();
        delete tmp;
    }
}

ListStack::ListStack(const ListStack & ls){
    top = new Node(*ls.top);
    Node *tr = top,
        *trls = ls.top;

    while(trls->getNext() != nullptr){
        top->setNext(trls->getNext());
        trls = trls->getNext();
        tr = tr->getNext();
    }
}

ListStack & ListStack::operator=(const ListStack & ls){
    if(this == &ls){
        return *this;
    }
    
    Node *tmp;
    while(top != nullptr){
        tmp = top;
        top = top->getNext();
        delete tmp;
    }

    top = new Node(*ls.top);
    Node *tr = top,
        *trls = ls.top;

    while(trls->getNext() != nullptr){
        top->setNext(trls->getNext());
        trls = trls->getNext();
        tr = tr->getNext();
    }

    return *this;
}

void ListStack::push(int x){
    if(top == nullptr){
        top = new Node(x);
    } else{
        Node *tmp = new Node(x);
        tmp->setNext(top);
        top = tmp;
    }
}

int ListStack::pop(void){
    int result;
    if(top == nullptr){
        return 0;
    } else{
        result = top->getInfo();
        Node *tmp = top;
        top = top->getNext();
        delete tmp;
    }

    return result;
}

int ListStack::peek(void){
    return top->getInfo();
}

bool ListStack::isEmpty(void){
    if(top == nullptr){
        return true;
    }
    return false;
}

void ListStack::print(void){
    Node *tr = top;
    while(tr){
        std::cout << tr->getInfo() << " ";
        tr = tr->getNext();
    }
    std::cout << std::endl;
}

// std::ostream & operator<<(std::ostream & os, const ListStack & ar){
    
// }

// std::istream & operator>>(std::istream & is, ListStack & ar);