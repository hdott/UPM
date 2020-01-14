#include <iostream>
#include <fstream>
#include <map>


int main(void) {
	using namespace std;

	map<string, int> mapA;

	fstream file("text.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string str;
			file >> str;
			auto x = mapA.insert(make_pair(str, 1));

			// evaluates to false if the element already existed
			if (!x.second) {
				mapA.at(str)++;
			}
		}
	}

	for (auto& x : mapA) {
		std::cout << x.first << " : " << x.second << std::endl;
	}


	return 0;
}