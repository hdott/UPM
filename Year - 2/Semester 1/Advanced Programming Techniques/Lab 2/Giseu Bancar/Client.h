#pragma once
// #ifndef CLIENT_H
// #define CLIENT_H
#include <iostream>
#include <vector>
#include "ContBancar.h"


class Client{
    private:
        std::string nume,
                    prenume,
                    adresa;
        std::vector<ContBancar> conturi;
    public:
        Client(std::string nume, std::string prenume,
                std::string adresa, ContBancar cont);
        Client(const Client&);
        ~Client();

        inline std::string getNume(){return nume;}
        inline std::string getPrenume(){return prenume;}
        inline std::string getAdresa(){return adresa;}
        inline std::vector<ContBancar> getConturi(){return conturi;}
        inline void setNume(std::string nume){this->nume = nume;}
        inline void setPrenume(std::string prenume){this->prenume = prenume;}
        inline void setAdresa(std::string adresa){this->adresa = adresa;}
        void addCont(ContBancar cont);
};

// #endif