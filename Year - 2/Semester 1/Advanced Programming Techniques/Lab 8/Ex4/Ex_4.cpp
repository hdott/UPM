/*
    Scrieti un program care calculeaza notele obtinute la examen de un student. Un
        student va fi caracterizat prin: CNP, nume, nota laborator, nota examen, numar
        absente.
    Programul va permite:
        salvarea listei de studenti intr-un fisier
        citirea din fisier a listei de studenti
        sortarea listei dupa numele studentului
        sortarea listei dupa nota de examen
        cautarea in lista a unui student dupa nume
        afisarea tuturor studentiilor cu nota cuprinsa intre x si . x,y se vor citi de
            la tastatura
        afisarea studentilor care au mai putin de 11 prezente
    Se va folosi o clasa Student cu operatorii =, ==, !=, <, <<, >> suprascrisi
    Se va crea un set<Student>
    Se va crea un alt set<Student, ComparaNota>
    ComparaNota este o alta clasa in care se suprascrie doar operatorul(), care
        defineste o alta relatie de comparatie intre obiecte de tip Student.
*/


#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include "student.h"
#include "cmpStudent.h"

using namespace std;

void initializeSet(set<Student> & studS, set<Student,ComparaNota> & studC);
bool searchByName(set<Student> & studS);
void printStudentsBetweenScore(set<Student,ComparaNota> & studC);


int main(void){

    set<Student> studS;
    set<Student,ComparaNota> studC;

    initializeSet(studS, studC);


    
    

    return 0;
}

void initializeSet(set<Student> & studS, set<Student,ComparaNota> & studC){
    ifstream file("studenti.txt", ifstream::in);

    if(file.is_open()){
        while(!file.eof()){
            string str;
            getline(file, str);
            stringstream sstr(str);
            Student stud;
            for(int i = 0; i < 5; ++i){
                switch(i){
                    case 0:
                        sstr >> stud.CNP();
                        break;
                    case 1:
                        sstr >> stud.Nume();
                        break;
                    case 2:
                        sstr >> stud.NotaLab();
                        break;
                    case 3:
                        sstr >> stud.NotaExam();
                        break;
                    case 4:
                        sstr >> stud.Absente();
                        break;
                }
            }

            studS.insert(stud);
            studC.insert(stud);
        }
    }

    file.close();
}

bool searchByName(set<Student> & studS){
    string str;
    cout << "Enter the name: ";
    getline(cin, str).get();

    Student stud(str);
    if(studS.find(stud) != studS.end()){
        return true;
    }

    return false;
}

void printStudentsBetweenScore(set<Student,ComparaNota> & studC){
    Student stud1,
            stud2;
    
    cout << "Nota Min: ";
    cin >> stud1.NotaExam();
    cout << "Nota Max: ";
    cin >> stud2.NotaExam();

    for(auto & x : studC){
        if(!(stud1 < x)){
            if(stud1 == x){
                break;
            }
            cout << x;
        }
    }
}

void printStudentPrezenteLessThan11(set<Student> & studS){
}