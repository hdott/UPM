#include <iostream>
#include "Banca.h"


Banca::Banca(std::string codBanca, Client client){
    this->codBanca = codBanca;
    this->clienti.push_back(client);
}

Banca::Banca(const Banca& banca){
    this->codBanca = banca.codBanca;
    this->clienti = banca.clienti;
}

Banca::~Banca(){
    // for(Client x : clienti){
    //     x.~Client();
    // }
    clienti.clear();
}

void Banca::addClient(Client client){
    clienti.push_back(client);
}