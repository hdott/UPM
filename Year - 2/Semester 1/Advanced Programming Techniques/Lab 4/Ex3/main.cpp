#include <iostream>
#include "matrice.h"


int main(void){
    using namespace std;

    Matrice m1(3, 3);
    for(int i = 0, count = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            m1[i][j] = ++count;
        }
    }
    cout << m1;

    return 0;
}