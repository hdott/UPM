#include <iostream>
#include <set>

template <typename T> bool isEqual(T a1, T a2, T b1, T b2);

int main(void) {
	std::multiset<int> A{ 1, 2, 3, 4, 5 };
	std::multiset<int> B{ 1, 2, 3, 4, 5, 6 };

	bool rez = isEqual<std::multiset<int>::iterator>(A.begin(), A.end(), B.begin(), B.end());
	std::cout << (rez ? "true" : "false") << std::endl;


	return 0;
}


template <typename T>
bool isEqual(T a1, T a2, T b1, T b2) {
	T tracerA = a1;
	T tracerB = b1;
	
	while (tracerA != a2 && tracerB != b2) {
		if (*tracerA != *tracerB) {
			return false;
		}

		tracerA++;
		tracerB++;
	}

	while (tracerA != a2) {
		return false;
	}
	while (tracerB != b2) {
		return false;
	}

	return true;
}