/*
    Fie un fisier text. Sa se stocheze numarul de aparitii ale fiecarui cuvant linie
        cu linie. Sa se foloseasca map<int,map<string,unsigned>>
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>


int main(void){
    using namespace std;

    map<int,map<string,unsigned>> mapA;

    ifstream file("raven.txt", ifstream::in);

    int i = 1;
    if(file.is_open()){
        while(!file.eof()){
            string str;
            getline(file, str);
            stringstream line(str);

            map<string,unsigned> mapB;
            while(!line.eof()){
                string str;
                line >> str;
                mapB.insert(make_pair(str,0));
                mapB.at(str)++;
            }

            mapA.insert(make_pair(i,mapB));
            ++i;
        }
    }
    file.close();

    for(auto &x : mapA){
        cout << x.first << endl;
        for(auto &y : x.second){
            cout << "\t" << y.first << " : " << y.second << endl;
        }
    }


    return 0;
}