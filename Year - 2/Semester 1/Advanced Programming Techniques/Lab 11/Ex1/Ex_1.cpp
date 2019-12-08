#include <iostream>
#include <sstream>
#include <fstream>


int main(void){
    using namespace std;

    ifstream file("text.txt");
    ofstream fileO("textO.txt");

    if(file.is_open() && fileO.is_open()){
        while(!file.eof()){
            string str;
            getline(file, str);
            stringstream sstr(str);
            
            while(!sstr.eof()){
                string str;
                sstr >> str;
                fileO << str << endl;
            }
        }
    }
    file.close();
    fileO.close();


    return 0;
}