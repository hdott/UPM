#include <iostream>
#include "film.h"


void Film::addActor(Actor *actor){
    listaActori.push_back(actor);
    ++nrActori;
}

void sortFilme(std::vector<Film*> filme){
    for(int i=0; i<filme.size(); ++i){
        for(int j=i+1; j<filme.size(); ++j){
            if(compara(*filme[i], *filme[j]) == 1){
                std::swap(*filme[i], *filme[j]);
            }
        }
    }
}


int compara(const Film &film1, const Film &film2){
    if(film1.buget > film2.buget){
        return 1;
    } else if(film1.buget == film2.buget){
        if(film1.nrActori > film2.nrActori){
            return 1;
        } else if(film1.nrActori == film2.nrActori){
            return 0;
        } else{
            return -1;
        }

        return 0;
    } 

    return -1;
}

void aflaActoriComuni(const Film &film1, const Film &film2){
    std::cout << "*** " << film1.nume << " *** " << film2.nume << " ***"
        << std::endl;
    for(Actor *f1 : film1.listaActori){
        for(Actor *f2 : film2.listaActori){
            if(*f1 == *f2){
                std::cout << *f1 << std::endl;
            }
        }
    }
}

std::ostream& operator<<(std::ostream &os, const Film &film){
    os << "*** " << film.nume << " ***\n";
    os << "Director: " << film.director << std::endl;
    os << "Buget: " << film.buget << std::endl;
    os << "Nr Actori: " << film.nrActori << std::endl;
    for(Actor* x: film.listaActori){
        os << "~ " << *x << std::endl;
    }

    return os;
}