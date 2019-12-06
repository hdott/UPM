/*
    Fie un fisier text. Sa se stocheze numarul de aparitii ale fiecarui cuvant din
        text. Se va folosi map<string, unsigned>
*/

#include <iostream>
#include <fstream>
#include <map>


int main(void){
    using namespace std;

    map<string, int> mapA;

    ifstream file("raven.txt", ifstream::in);

    if(file.is_open()){
        while(!file.eof()){
            string str;
            file >> str;
            auto x = mapA.insert(make_pair(str,1));
            if(!x.second){
                mapA.at(str)++;
            }
        }
    }
    file.close();

    for(auto &x : mapA){
        cout << x.first << " : " << x.second << endl;
    }


    return 0;
}