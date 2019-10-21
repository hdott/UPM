#pragma once
#ifndef BANCA_H
#define BANCA_H
#include <iostream>
#include <vector>
#include "Client.h"


class Banca{
    private:
        std::vector<Client> clienti;
        std::string codBanca;
    public:
        Banca(std::string codBanca, Client client);
        Banca(const Banca&);
        ~Banca();

        inline std::vector<Client> getClienti(){return clienti;}
        inline std::string getCodBanca(){return codBanca;}
        void addClient(Client client);
        inline void setCodBanca(std::string codBanca){this->codBanca = codBanca;}
};

#endif