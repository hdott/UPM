#include <iostream>
#include "Client.h"


Client::Client(std::string nume, std::string prenume, std::string,
                std::string adresa, ContBancar cont){
    this->nume = nume;
    this->prenume = prenume;
    this->adresa = adresa;
    conturi.push_back(cont);
}

Client::Client(const Client& client){
    this->nume = client.nume;
    this->prenume = client.prenume;
    this->adresa = client.adresa;
    this->conturi = client.conturi;
}

Client::~Client(){
    conturi.clear();
}

void Client::addCont(ContBancar cont){
    conturi.push_back(cont);
}