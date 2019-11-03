/*
    Sa se creeze clasa Angajat cu:
        - proprietatea tarifOrar de tip double si valoarea initiala 5.5
        - proprietatea nrOre de tip int
        - metoda getSalar care intoarce tarifOrar * nrOre
        - metoda getTarifOrar care intoarce valoarea proprietatii tarifOrar
        Sa se creeze main care sa contina metoda main in care sa se intantieze un obiect
        din clasa Angajat si sa afiseze tariful orar si salarul angajatului.
        Sa se creeze o clasa Manager care sa mosteneasca Angajat si sa aiba o metoda
        getSalar care sa adauge un bonus de 50% fata de salarul unui Angajat. Tot in
        clasa Main sa se instantieze un obiect din clasa Manager si sa se afiseze
        tariful orar si salarul managerului.
*/

#include <iostream>
#include "manager.h"


int main(void){
    using namespace std;
    
    Angajat emp1(5.5, 120);
    cout << "Tarif Orar: " << emp1.getTarifOrar() << endl;
    cout << "Salar: " << emp1.getSalar() << endl;    

    Manager emp2(5.5, 120);
    cout << "Tarif Orar: " << emp2.getTarifOrar() << endl;
    cout << "Salar: " << emp2.getSalar() << endl;  


    return 0;
}