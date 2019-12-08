#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <set>


int main(void){
    using namespace std;

    map<string, set<string>> mapA;    

    ifstream file("text.txt");
    if(file.is_open()){
        while(!file.eof()){
            string str;
            file >> str;

            string strA = str;
            sort(strA.begin(), strA.end());

            set<string> set;
            while(next_permutation(strA.begin(), strA.end())){
                    set.insert(strA);
            }

            mapA.insert(make_pair(str, set));
        }
    }
    file.close();

    for(auto & x : mapA){
        cout << x.first << " -> ";
        for(auto & y : x.second){
            cout << y << " ";
        }
        cout << endl;
    }


    return 0;
}