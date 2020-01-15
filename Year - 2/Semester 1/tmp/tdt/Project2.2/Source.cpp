#include <iostream>
#include <vector>
#include <iterator>
#include <vector>

template <typename T, class OutputIterator> void product(T a1, T a2, T b1, T b2, OutputIterator result);

int main(void) {
	using namespace std;

	vector<int> A{ 1,2,3,4,5 };
	vector<int> B{ 1,2,3,4,5,6 };
	vector<int> C;

	product(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C));

	for (auto& x : C) {
		cout << x << " ";
	}
	cout << endl;

	return 0;
}


template <typename T, class OutputIterator>
void product(T a1, T a2, T b1, T b2, OutputIterator result) {

	while (a1 != a2 && b1 != b2) {
		*result = (*a1) * (*b1);
		++a1;
		++b1;
		++result;
	}

	while (a1 != a2) {
		*result = 0;
		++a1;
		++result;
	}

	while (b1 != b2) {
		*result = 0;
		++b1;
		++result;
	}
}