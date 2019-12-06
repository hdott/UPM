#pragma once
#include <iostream>

using namespace std;

class Student{
    private:
        string cnp;
        string nume;
        double notaLab;
        double notaExam;
        int absente;

    public:
        Student(){};
        Student(string nume) : nume(nume){};
        Student(string cnp, string nume) : cnp(cnp), nume(nume){};
        Student(string cnp, string nume, double lab, double exam, int abs) :
                    cnp(cnp), nume(nume), notaLab(lab), notaExam(exam), absente(abs){};

        string& CNP(){return cnp;}
        string& Nume(){return nume;}
        double& NotaLab(){return notaLab;}
        double& NotaExam(){return notaExam;}
        int& Absente(){return absente;}

        bool operator==(const Student & stud) const;
        bool operator!=(const Student & stud) const;
        bool operator<(const Student & stud) const;

        friend ostream& operator<<(ostream & os, const Student & stud);
        friend istream& operator>>(istream & is, Student & stud);
};


bool Student::operator==(const Student & stud) const{
    return (cnp == stud.cnp);
}

bool Student::operator!=(const Student & stud) const{
    return (cnp != stud.cnp);
}

bool Student::operator<(const Student & stud) const{
    return (nume < stud.nume);
}

ostream& operator<<(ostream & os, const Student & stud){
    os << "CNP: " << stud.cnp << endl;
    os << "Nume: " << stud.nume << endl;
    os << "Lab: " << stud.notaLab << " Exam: " << stud.notaExam << " Absente: "
            << stud.absente << endl;

    return os;
}

istream& operator>>(istream & is, Student & stud){
    cout << "Nume: ";
    getline(is, stud.nume);
    cout << "CNP: ";
    is >> stud.cnp;
    cout << "Nota Lab: ";
    is >> stud.notaLab;
    cout << "Nota Exam: ";
    is >> stud.notaExam;
    cout << "Absente: ";
    is >> stud.absente;

    return is;
}