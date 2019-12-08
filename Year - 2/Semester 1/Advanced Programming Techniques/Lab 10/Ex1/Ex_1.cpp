#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <iterator>


int main(void){
    using namespace std;

    deque<int> deqA;
    for(int i = 1; i <= 10; ++i){
        if(!(i%3)){
            deqA.push_back(i);
        }
    }

    vector<int> vectA;
    for(int i = 1; i <= 10; ++i){
        if(!(i%2)){
            vectA.push_back(i);
        }
    }

    list<int> listA(10);
    int i = -10;
    for(auto & x : listA){
        x = i;
        ++i;
        // cout << x << endl;
    }

    vector<int> vectR;
    copy(deqA.begin(), deqA.end(), insert_iterator<vector<int>>(vectR, vectR.begin()));
    copy(vectA.begin(), vectA.end(), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(vectR.begin(), vectR.end(), ostream_iterator<int, char>(cout, " "));
    cout << endl;
    
    vectR.erase(vectR.begin(), vectR.end());
    copy(vectA.begin(), vectA.end(), insert_iterator<vector<int>>(vectR, vectR.begin()));
    copy(deqA.begin(), deqA.end(), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(vectR.begin(), vectR.end(), ostream_iterator<int, char>(cout, " "));
    cout << endl;

    
    vectR.erase(vectR.begin(), vectR.end());
    copy(vectA.begin(), vectA.end()-1, insert_iterator<vector<int>>(vectR, vectR.begin()));
    copy(listA.rbegin(), next(listA.rbegin(), 4), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(vectA.end()-1, vectA.end(), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(deqA.begin(), deqA.end()-1, insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(next(listA.rbegin(), 4), next(listA.rbegin(), 7), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(deqA.end()-1, deqA.end(), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(next(listA.rbegin(), 7), listA.rend(), insert_iterator<vector<int>>(vectR, vectR.end()));
    copy(vectR.begin(), vectR.end(), ostream_iterator<int, char>(cout, " "));
    cout << endl;


    return 0;
}