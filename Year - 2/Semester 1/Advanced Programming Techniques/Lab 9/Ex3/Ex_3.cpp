#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <set>

using namespace std;

class RandomNumber{
    private:
        int x;
    public:
        RandomNumber(int x) : x(x){};
        int operator()(){
            return (random() % x);
        }
};


int main(int argc, char **argv){
    if(argc != 2){
        cerr << "Program takes an int argument!" << endl;
        exit(EXIT_FAILURE);
    }


    int x = atoi(argv[1]);
    vector<int> vectA(x);
    vector<int> vectB(x);
    
    generate(vectA.begin(), vectA.end(), RandomNumber(x/2));
    generate(vectB.begin(), vectB.end(), RandomNumber(x/2));

    set<int> setA(vectA.begin(), vectA.end());
    set<int> setB(vectB.begin(), vectB.end());

    cout << "Set A: " << endl;
    copy(setA.begin(), setA.end(), ostream_iterator<int, char>(cout, " "));
    putchar('\n');

    cout << "Set B: " << endl;
    copy(setB.begin(), setB.end(), ostream_iterator<int, char>(cout, " "));
    putchar('\n');

    cout << "Intersaction A_B: " << endl;
    set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        ostream_iterator<int, char>(cout, " "));
    putchar('\n');

    cout << "Union A_B: " << endl;
    set_union(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        ostream_iterator<int, char>(cout, " "));
    putchar('\n');

    cout << "Difference A_B: " << endl;
    set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(),
                        ostream_iterator<int, char>(cout, " "));
    putchar('\n');


    return 0;
}

