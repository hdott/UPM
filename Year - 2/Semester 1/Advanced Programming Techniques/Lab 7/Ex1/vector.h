#pragma once
#include <iostream>



namespace Vector{
    template <typename T>
    T max(int size, T vector[]){
        T m = vector[0];

        for(int i = 1; i < size; ++i){
            if(m < vector[i]){
                m = vector[i];
            }
        }

        return m;
    }    

    template <typename T>
    T min(int size, T vector[]){
        T m = vector[0];

        for(int i = 1; i < size; ++i){
            if(m > vector[i]){
                m = vector[i];
            }
        }

        return m;
    }

    template <typename T>
    bool search(int size, T vector[], T key){
        for(int i = 0; i < size; ++i){
            if(key == vector[i]){
                return true;
            }
        }

        return false;
    }

    template <typename T>
    bool bsearch(int size, T vector[], T key){
        int min = 0,
            max = size-1,
            i = size / 2;

        while(i > 0 && i < size){
            if(key == vector[i]){
                return true;
            }

            if(key < vector[i]){
                max = i - 1;
                i = (min + max) / 2;
                continue;
            }

            if(key > vector[i]){
                min = i + 1;
                i = (min + max) / 2;
            }
        }

        return false;
    }

    template <typename T>
    void bubbleSort(int size, T vector[]){
        for(int i=0; i<size-1; ++i){
            for(int j=0; j<size-i-1; ++j){
                if(vector[j] > vector[j+1])
                {
                    T aux = vector[j];
                    vector[j] = vector[j+1];
                    vector[j+1] = aux;
                }
            }
        }
    }

    void bubbleSort(int size, char vector[]){
        for(int i=0; i<size-1; ++i){
            for(int j=0; j<size-i-1; ++j){
                if(vector[j] < vector[j+1])
                {
                    char aux = vector[j];
                    vector[j] = vector[j+1];
                    vector[j+1] = aux;
                }
            }
        }
    }

    template <typename T>
    void printVector(int size, T vector[]){
        std::cout << "Vector: ";
        for(int i = 0; i < size; ++i){
            std::cout << vector[i] << " ";
        }
        std::cout << std::endl;
    }
}