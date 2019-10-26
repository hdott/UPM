#pragma once
#include <iostream>


class Actor{
    public:
        static int nrActori;

    private:
        std::string nume,
                    prenume;
        int varsta;
    
    public:
        Actor(std::string nume, std::string prenume, int varsta):
            nume(nume), prenume(prenume), varsta(varsta){nrActori++;};
        // ~Actor();

        void setNume(std::string nume){this->nume = nume;};
        void setPrenume(std::string prenume){this->prenume = prenume;};
        void setVarsta(int varsta){this->varsta = varsta;};
        std::string getNume() const{return nume;};
        std::string getPrenume() const{return prenume;};
        std::string getFullName() const{return nume + ", " + prenume;};
        int getVarsta() const{return varsta;};

        bool operator==(const Actor &actor);
        friend std::ostream& operator<<(std::ostream &os, const Actor &actor);
        friend std::istream& operator>>(std::istream &is, Actor &actor);
};