#include <iostream>
#include <map>
#include <fstream>
#include <sstream>


int main(void) {
	using namespace std;

	map<int, string> mapA;

	fstream file("dictionar.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string str;
			getline(file, str);

			stringstream sstr(str);

			int x = 0;
			while (!sstr.eof()) {
				string tmp;
				sstr >> tmp;
				++x;
			}

			mapA.insert(make_pair(x, str));
		}
	}
	file.close();


	for (auto& x : mapA) {
		cout << x.second << endl;
	}

	return 0;
}