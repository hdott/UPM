#pragma once
#include "student.h"


class ComparaNota{
    public:
        bool operator()(Student s1, Student s2);
};

bool ComparaNota::operator()(Student s1, Student s2){
    return s1.NotaExam() < s2.NotaExam();
}