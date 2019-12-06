/*
    Fie un fisier text. Sa se stocheze intr-un alt fisier cuvintele in ordine
        alfabetica, sa se elimine duplicatele. Se va folosi set<string>.
*/

#include <iostream>
#include <fstream>
#include <set>
#include <vector>


int main(void){
    using namespace std;

    set<string> setA;
    ifstream file("raven.txt", ifstream::in);
    
    if(file.is_open()){
        while(!file.eof()){
            string str;
            file >> str;
            setA.insert(str);
        }
    }
    file.close();

    ofstream outFile("orderedWords.txt", ofstream::out);
    for(auto i = setA.begin(); i != setA.end(); ++i){
        cout << *i << endl;
        outFile << *i << endl;
    }

    return 0;
}