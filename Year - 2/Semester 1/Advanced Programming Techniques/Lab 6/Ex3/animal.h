#pragma once
#include <iostream>


class Animal{
    private:
        std::string specie;
        int varsta;

    public:
        Animal(void) : specie("tmp_spece"), varsta(-1){};
        Animal(std::string specie, int varsta) : specie(specie), varsta(varsta){};

        // std::string getSpecie(void) const{return specie;}
        // void setSpecie(std::string specie){this->specie = specie;}
        // int getVarsta(void) const{return varsta;}
        // void setVarsta(int varsta){this->varsta = varsta;}
        const std::string Specie(void) const{return specie;}
        std::string & Specie(void){return specie;}
        const int Varsta(void) const{return varsta;}
        int & Varsta(void){return varsta;}
        virtual bool heterotrof(void) const = 0;
};