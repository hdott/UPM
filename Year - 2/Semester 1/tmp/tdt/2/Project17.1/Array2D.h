#pragma once


template <class T>
class Array2D
{
	int n,
		m;
	T** arr;

public:
	Array2D(int n = 0, int m = 0, T** arr = nullptr) : n(n), m(m), arr(arr) {}
	Array2D(const Array2D&);
	~Array2D();

	Array2D<T>& operator++();
	Array2D<T>& operator++(int x);
	Array2D<T>& operator--();
	Array2D<T>& operator--(int x);
	bool operator<();
};

template<class T>
inline Array2D<T>::Array2D(const Array2D& matrix)
{
	if (arr) {
		for (int i = 0; i < n; ++i) {
			delete[] arr[i];
		}
		delete[] arr;
		arr = nullptr;
	}

	n = matrix.n;
	m = matrix.m;
	arr = new T * [n];
	for (int i = 0; i < n; ++i) {
		arr[i] = new T[m];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			arr[i][j] = matrix.arr[i][j];
		}
	}
}

template<class T>
inline Array2D<T>::~Array2D()
{
	for (int i = 0; i < n; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;
}

template<class T>
inline Array2D<T>& Array2D<T>::operator++()
{
	++n;
	T** new_arr = new T*[n];
	for (int i = 0; i < n; ++i) {
		new_arr[i] = new T[m];
	}

	int i = 0;
	for (int j = 0; j < m; ++i) {
		new_arr[i][j] = 1;
	}
	for (i = 1; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			new_arr[i][j] = arr[i][j];
		}
	}
}

template<class T>
inline Array2D<T>& Array2D<T>::operator++(int x)
{
	// TODO: insert return statement here
}

