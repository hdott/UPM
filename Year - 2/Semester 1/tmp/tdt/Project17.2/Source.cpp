#include <iostream>
#include <list>

template <typename T>
int comparaLista(T aBegin, T aLast, T bBegin, T bLast);


int main(void) {
	using namespace std;

	list<float> A{ 1.1, 2.2, 3.3, 4.4, 5.5 };
	list<float> B{ 1.1, 2.2, 3.3, 4.4 };

	int rez = comparaLista<list<float>::iterator>(A.begin(), A.end(), B.begin(), B.end());

	cout << rez << endl;


	return 0;
}


template <typename T>
int comparaLista(T aBegin, T aLast, T bBegin, T bLast) {
	auto aRez = *aBegin;
	auto bRez = *bBegin;
	aRez = 0;
	bRez = 0;

	while (aBegin != aLast) {
		aRez += *aBegin;
		++aBegin;
	}

	while (bBegin != bLast)
	{
		bRez += *bBegin;
		++bBegin;
	}

	if (aRez > bRez) {
		return 1;
	}
	else if (aRez < bRez) {
		return -1;
	}
	else {
		return 0;
	}
}