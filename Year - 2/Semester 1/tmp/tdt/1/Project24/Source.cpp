#include <iostream>
#include "LDI.h"
#include <fstream>
#include <string>
#include <sstream>


int main(void) {
	LDI<int> first,
		second;

	bool firstT = true;
	std::fstream file("liste.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			std::string str;
			std::getline(file, str);
			std::stringstream sstr(str);

			while (!sstr.eof()) {
				std::string nrS;
				sstr >> nrS;
				//std::cout << nrS << " ";
				int nr = std::stoi(nrS);
				if (firstT) {
					first.operator++(nr);
				}
				else {
					second.operator++(nr);
				}
			}
			firstT = false;
		}

		first.print();
		second.print();
	}
	file.close();


	second += first;
	second.print();

	std::fstream outFile("out.txt");
	if (outFile.is_open()) {
		outFile << second;
		outFile << first;
	}
	outFile.close();


	return 0;
}