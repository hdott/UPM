#include <iostream>
#include "matrice.h"


int main(void){
    using namespace std;
    // cout.setf()

    cout << "*** Test Constructor\n";
    Matrice m1(3, 3),
            m3;
    for(int i = 0, count = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            m1[i][j] = ++count;
        }
    }
    cout << m1;

    cout << "\n*** Test Copy Constructor\n";
    Matrice m2 = m1;
    cout << m2;

    cout << "\n*** Test Assignment Operator\n";
    m3 = m1;
    cout << m3;

    cout << "\n*** Test Addition Operator\n";
    cout << m1 + m2;

    cout << "\n*** Test Substraction Operator\n";
    cout << m1 - m2;

    Matrice m4(3, 3);
    for(int i = 0, count = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            m4[i][j] = 1;
        }
    }

    cout << "\n*** Test Multipliation Operator\n";
    cout << m1 * m4;

    cout << "\n*** Test Addition Operator with Int\n";
    cout << m1 + 1;

    cout << "\n*** Test Substraction Operator with Int\n";
    cout << m1 - 1;

    cout << "\n*** Test Multiplication Operator with Int\n";
    cout << m1 * 2;

    cout << "\n*** Test Division Operator with Int\n";
    cout << m1 / 2;

    cout << "\n*** Test != Operator\n";
    cout << (m1 != m2) << endl;
    cout << (m1 != m4) << endl;

    cout << "\n*** Test == Operator\n";
    cout << (m1 == m2) << endl;
    cout << (m1 == m4) << endl;

    cout << "\n*** Test += Operator\n";
    cout << (m1 += m4);
    

    cout << "\n*** Test -= Operator\n";
    cout << (m1 -= m4);

    cout << "\n*** Test *= Operator\n";
    cout << (m1 *= m4);

    cout << "\n*** Test += Operator with Int\n";
    cout << (m1 += 1);

    cout << "\n*** Test -= Operator with Int\n";
    cout << (m1 -= 1);

    cout << "\n*** Test *= Operator with Int\n";
    cout << (m1 *= 1);

    cout << "\n*** Test /= Operator with Int\n";
    cout << (m1 /= 1);

    cout << "\n*** Test Prefix ++ Operator\n";
    cout << ++m1;

    cout << "\n*** Test Postfix ++ Operator\n";
    cout << m1++ << m1;

    cout << "\n*** Test Prefix -- Operator\n";
    cout << --m1;

    cout << "\n*** Test Postfix ++ Operator\n";
    cout << m1-- << m1;

    cout << "\n*** Test Int with Addition Operator\n";
    cout << 1 + m1;

    cout << "\n*** Test Int with Substraction Operator\n";
    cout << 1 - m1;

    cout << "\n*** Test Int with Multiplication Operator\n";
    cout << 2 * m1;


    return 0;
}