#include <iostream>
#include <vector>
#include "actor.h"
#include "film.h"


int main(void){
    std::vector<Film*> filme;

    filme.push_back(new Film("Maleficent: Mistress of Evil", "Joachim Ronning", 185000000));
    filme[0]->addActor(new Actor("Jolie", "Angelina", 44));
    filme[0]->addActor(new Actor("Fanning", "Elle", 21));
    filme[0]->addActor(new Actor("Dickinson", "Harris", 23));
    filme[0]->addActor(new Actor("Pfeiffer", "Michelle", 61));
    filme[0]->addActor(new Actor("Riley", "Sam", 39));

    filme.push_back(new Film("Joker", "Todd Phillips", 55000000));
    filme[1]->addActor(new Actor("Phoenix", "Joaquin", 44));
    filme[1]->addActor(new Actor("De Niro", "Robert", 76));
    filme[1]->addActor(new Actor("Beetz", "Zazie", 28));
    filme[1]->addActor(new Actor("Conroy", "France", 65));

    filme.push_back(new Film("Zombieland: Double Tap", "Ruben Fleischer", 42000000));
    filme[2]->addActor(new Actor("Harrelson", "Woody", 58));
    filme[2]->addActor(new Actor("Eisenberg", "Jesse", 36));
    filme[2]->addActor(new Actor("Stone", "Emma", 30));
    filme[2]->addActor(new Actor("Breslin", "Abigail", 23));
    filme[2]->addActor(new Actor("Deutch", "Zoey", 24));

    filme.push_back(new Film("Maleficent", "Robert Stromberg", 180000000));
    filme[3]->addActor(new Actor("Jolie", "Angelina", 44));
    filme[3]->addActor(new Actor("Fanning", "Elle", 21));
    filme[3]->addActor(new Actor("Copley", "Sharlto", 45));
    filme[3]->addActor(new Actor("Manville", "Lesley", 63));

    for(Film* x : filme){
        std::cout << *x << std::endl;
    }

    sortFilme(filme);

    for(Film* x : filme){
        std::cout << *x << std::endl;
    }

    for(int i=0; i<filme.size(); ++i){
        for(int j=i+1; j<filme.size(); ++j){
            aflaActoriComuni(*filme[i], *filme[j]);
        }
    }

    std::cout << "\nNumar total de actori: " << Actor::nrActori << std::endl;

    return 0;
}