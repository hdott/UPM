#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


int main(void){
    ifstream file("text.txt");
    vector<string> vect;
    vector<string> vectB;

    if(file.is_open()){
        while(!file.eof()){
            string str;
            getline(file, str);
            vect.push_back(str);
        }
    }
    file.close();
    // vectB = vect;

    int max_size = 0;
    for(auto & x : vect){
        if(x.size() > max_size){
            max_size = x.size();
        }
    }
    
    // A
    vect.emplace(vect.begin(), string(max_size+2, '_'));
    vect.emplace_back(string(max_size+1, '_'));
    for(auto x = vect.begin()+1; x != vect.end(); ++x){
        x->insert(x->begin(), '|');
        while(x->size() != max_size+2){
            x->push_back(' ');
        }
        x->push_back('|');
    }

    for(auto & x : vect){
        cout << x << endl;
    }

    // B
    vectB.push_back(vect[0]);
    for(int i = 1; i < vect.size()-1; ++i){ 
        vectB.push_back(vect[i]);

        string str(max_size+1, '_');
        str.insert(str.begin(), '|');
        str.push_back('|');
        vectB.push_back(str);
    }


    for(auto & x : vectB){
        cout << x << endl;
    }

    return 0;
}