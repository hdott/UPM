/*
    Sa se implementeze o clasa abstracta Persoana cu atributele CNP, nume, o metoda detalii
        fara parametrii si care returneaza toate datele obiectului.
    - Sa se creeze o clasa Student care mosteneste clasa Persoana. Un obiect de tip Student
        trebuie sa stocheze urmatoarele informatii: email si nota. Nota va fi accesibila
        doar prin intermediul functiei getNota.
    - Implementarea metodei detalii returneaza un string de genul "Student [nume] are nota
        [nota].", unde [numele] si [nota] reprezinta valorile campurilor. Sa se instantieze
        un obiect din clasa Student si sa se foloseasca functia detalii.
    - Sa se creeze o clasa Profesor care mosteneste clasa Persoana. Un obiect de tip Profesor
        trbebuie sa stocheze urmatoarele informatii: email si materie. Materia va fi accesibila
        doar prin intermediul functiei getMaterie. Implementarea metodei detalii returneaza un
        string de genul: "Profesorul [nume] preda [materia].", unde [numele] si [materia]
        reprezinta valorile campurilor. Sa se instantieze un obiect din clasa Profesor si sa se
        foloseasca functia detalii.
    - Sa se creeze o clasa Angajat care mosteneste Persoana. Un obiect de tip Angajat trebuie
        sa stocheze urmatoarele informatii: email si departament. Materia va fi accesibila
        doar prin intermediul functiei getDepartament. Implementarea functiei detalii returneaza
        un string de genul "Angajatul [nume] face parte din departamentul [departament].", unde
        [numele] si [departament] reprezinta valorile campurilor. Sa se instantieze un obiect din
        clasa Angajat si sa se foloseasca functia detalii.
*/

#include <iostream>
#include "student.h"
#include "profesor.h"
#include "angajat.h"



int main(void){
    using namespace std;

    // Student student("nume", "CNP", "email", 9.99);
    // cout << student.detalii() << endl;

    // Profesor prof("nume_prof", "CNP_prof", "email", "materie");
    // cout << prof.detalii() << endl;

    Angajat angajat("nume_angajat", "CNP_angajat", "email", "departament");
    cout << angajat.detalii() << endl;
    

    return 0;
}