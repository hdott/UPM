#include <iostream>
#include <fstream>
#include <list>

using namespace std;

bool cmpSize(const string & first, const string & second);


int main(void){
    list<string> lista;
    ifstream file("text.txt");

    if(file.is_open()){
        while(!file.eof()){
            string str;
            getline(file, str);
            lista.push_back(str);
        }
    }
    file.close();

    lista.sort();
    ofstream fileO("textOrdered.txt");
    if(fileO.is_open()){
        for(auto & x : lista){
            fileO << x << endl;
        }
    }
    fileO.close();

    lista.reverse();
    ofstream fileR("textReversed.txt");
    if(fileR.is_open()){
        for(auto & x : lista){
            fileR << x << endl;
        }
    }
    fileR.close();

    lista.sort(cmpSize);
    ofstream fileS("textSize.txt");
    if(fileS.is_open()){
        for(auto & x : lista){
            fileS << x << endl;
        }
    }
    fileS.close();
    
    for(auto & x : lista){
        cout << x << endl;
    }


    return 0;
}

bool cmpSize(const string & first, const string & second){
    return (first.size() < second.size());
}