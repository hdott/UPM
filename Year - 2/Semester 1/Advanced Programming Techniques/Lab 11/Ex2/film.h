#pragma once
#include <iostream>
#include <vector>
#include "actor.h"


class Film{
    private:
        std::string nume,
                    director;
        double buget;
        std::vector<Actor*> listaActori;
        int nrActori = 0;

    public:
        Film(std::string nume="nume", std::string director="director",
            double buget=0.0): nume(nume), director(director), buget(buget){};
        // ~Film();

        void setNume(std::string nume){this->nume = nume;};
        void setDirector(std::string producator){this->director = producator;};
        void setBuget(double buget){this->buget = buget;};
        std::string getNume() const{return nume;};
        std::string getDirector() const{return director;};
        double getBuget() const{return buget;};

        void addActor(Actor *actor);
        
        friend void sortFilme(std::vector<Film*> filme);
        friend int compara(const Film &film1, const Film &film2);
        friend void aflaActoriComuni(const Film &film1, const Film &film2);
        friend std::ostream& operator<<(std::ostream &os, const Film &film);
};