#include <iostream>

const int S = 10;

template<typename T> T maxim(int size, T vector[]);
template<typename T> T minim(int size, T vector[]);
template<typename T> bool secvential(int size, T vector[], T key);
template<typename T> bool binar(int size, T vector[], T key);
template<> bool binar<std::string>(int size, std::string vector[], std::string key);
template<typename T> void ordonare(int size, T vector[]);
template<> void ordonare<std::string>(int size, std::string vector[]);
template<typename T> void printVect(int size, T vect[]);

int main(void){
    using namespace std;
    
    int vectI[S] = {5, 3, 6, 12, 2, 1, 8, 7, 25, 20};
    double vectD[S] = {5.3, 3.5, 6.2, 11.12, 2.55, 1.33, 8.1234, 6.556, 
                        20.234, 20.5123};
    string vectS[S] = {"Ssdf", "sadfe", "rered", "fdgfg", "dfdgrr", "werqre",
                        "rty", "wer", "erty", "cvb"};

    cout << "MaximI: " << maxim<int>(S, vectI) << endl;
    cout << "MaximD: " << maxim<double>(S, vectD) << endl;
    cout << "MaximS: " << maxim<string>(S, vectS) << endl;
    cout << "MinimI: " << minim<int>(S, vectI) << endl;
    cout << "MinimD: " << minim<double>(S, vectD) << endl;
    cout << "MinimS: " << minim<string>(S, vectS) << endl;
    bool existaI = secvential<int>(S, vectI, 12),
        existaD = secvential<double>(S, vectD, 6.556),
        existaS = secvential<string>(S, vectS, "cvb");
    cout << "SecventialI: " << (existaI ? "exista" : "NU exista") << endl;
    cout << "SecventialD: " << (existaD ? "exista" : "NU exista") << endl;
    cout << "SecventialS: " << (existaS ? "exista" : "NU exista") << endl;
    existaI = secvential<int>(S, vectI, 555);
    existaD = secvential<double>(S, vectD, 23.4234);
    existaS = secvential<string>(S, vectS, "abcd");
    cout << "SecventialI: " << (existaI ? "exista" : "NU exista") << endl;
    cout << "SecventialD: " << (existaD ? "exista" : "NU exista") << endl;
    cout << "SecventialS: " << (existaS ? "exista" : "NU exista") << endl;
    
    cout << "Nesortat:" << endl;
    cout << "\tVectorI: ";
    printVect<int>(S, vectI);
    cout << "\tVectorD: ";
    printVect<double>(S, vectD);
    cout << "\tVectorS: ";
    printVect<string>(S, vectS);

    ordonare<int>(S, vectI);
    ordonare<double>(S, vectD);
    ordonare<string>(S, vectS);             // string ul este sortat descrescator
    cout << "Sortat:" << endl;
    cout << "\tVectorI: ";
    printVect<int>(S, vectI);
    cout << "\tVectorD: ";
    printVect<double>(S, vectD);
    cout << "\tVectorS: ";
    printVect<string>(S, vectS);

    existaI = binar<int>(S, vectI, 12),
    existaD = binar<double>(S, vectD, 6.556),
    existaS = binar<string>(S, vectS, "cvb");
    cout << "BinarI: " << (existaI ? "exista" : "NU exista") << endl;
    cout << "BinarD: " << (existaD ? "exista" : "NU exista") << endl;
    cout << "BinarS: " << (existaS ? "exista" : "NU exista") << endl;
    existaI = binar<int>(S, vectI, 555);
    existaD = binar<double>(S, vectD, 23.4234);
    existaS = binar<string>(S, vectS, "abcd");
    cout << "BinarI: " << (existaI ? "exista" : "NU exista") << endl;
    cout << "BinarD: " << (existaD ? "exista" : "NU exista") << endl;
    cout << "BinarS: " << (existaS ? "exista" : "NU exista") << endl;



    return 0;
}


template<typename T>
T maxim(int size, T vector[]){
    T m = vector[0];

    for(int i = 1; i < size; ++i){
        if(m < vector[i]){
            m = vector[i];
        }
    }

    return m;
}

template<typename T>
T minim(int size, T vector[]){
    T m = vector[0];

    for(int i = 1; i < size; ++i){
        if(m > vector[i]){
            m = vector[i];
        }
    }

    return m;
}

template<typename T>
bool secvential(int size, T vector[], T key){
    for(int i = 0; i < size; ++i){
        if(vector[i] == key)
            return true;
    }

    return false;
}

template<typename T>
bool binar(int size, T vector[], T key){
    int start = 0,
        end = size-1,
        mid = end / 2;

    while(start < end){
        if(key == vector[mid])  return true;

        if(key < vector[mid]){
            end = mid - 1;
            mid = (start + end) / 2;
            continue;
        }

        if(key > vector[mid]){
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }

    return false;
}

template<> bool binar<std::string>(int size, std::string vector[], std::string key){
    int start = 0,
        end = size-1,
        mid = end / 2;

    while(start < end){
        if(key == vector[mid])  return true;

        if(key > vector[mid]){
            end = mid - 1;
            mid = (start + end) / 2;
            continue;
        }

        if(key < vector[mid]){
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }

    return false;
}

template<typename T>
void ordonare(int size, T vector[]){
    std::cout << "Am Sortat TEMPLATE" << std::endl;
    for(int i = 0; i < size-1; ++i){
        for(int j = 0; j < size-i-1; ++j){
            if(vector[j] > vector[j+1]){
                T aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

// specializare reversed pentru string
template<> void ordonare<std::string>(int size, std::string vector[]){
    std::cout << "Am Sortat STRING" << std::endl;
    for(int i = 0; i < size-1; ++i){
        for(int j = 0; j < size-i-1; ++j){
            if(vector[j] < vector[j+1]){
                std::string aux = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = aux;
            }
        }
    }
}

template<typename T>
void printVect(int size, T vect[]){
    for(int i = 0; i < size; ++i){
        std::cout << vect[i] << " ";
    }
    std::cout << std::endl;
}