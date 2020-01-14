#include "LDI.h"
#include <iostream>

template <class T>
LDI<T>::LDI(const LDI<T>& list) {
	if (FRONT) {
		Node* tracer = FRONT;
		while (tracer != nullptr) {
			Node* _toDelete = tracer;
			tracer = tracer->succesor;
			delete[] _toDelete;
		}
	}

	FRONT = nullptr;
	END = nullptr;

	Node* tracer = list.FRONT;
	bool first = true;
	while (tracer != nullptr) {
		if (first) {
			FRONT = new Node(tracer->info, tracer->predecesor, tracer->succesor);
			first = false;

			tracer = tracer->succesor;
			continue;
		}

		END = new Node(tracer->info, tracer->predecsor, tracer->succesor);
		tracer = tracer->succesor;
	}
}

template <class T>
LDI<T>::~LDI() {
	Node* tracer = FRONT;
	while (tracer != nullptr) {
		Node* _toDelete = tracer;
		tracer = tracer->succesor;
		delete[] _toDelete;
	}

	FRONT = nullptr;
	END = nullptr;
}

template <class T>
LDI<T> LDI<T>::operator++(T item) {
	if (!FRONT) {
		FRONT = END = new Node(item);
	}
	else {
		END = new Node(item, END);
	}

	return this;
}

template <class T>
LDI<T> LDI<T>::operator--(T item) {
	if (!FRONT) {
		return;
	}

	Node* _toDelete = END;
	END = END->predecesor;
	delete[] _toDelete;

	return this;
}

template <class T>
LDI<T> LDI<T>::operator+=(const LDI& list) {
	if (!FRONT) {
		this = list;
		return this;
	}

	Node* tracer = list.FRONT;
	while (tracer) {
		END = new Node(tracer->info, END);
		tracer = tracer->succesor;
	}

	return this;
}

template <class T>
void LDI<T>::print() {
	Node* tracer = FRONT;
	while (tracer) {
		std::cout << tracer->info << std::endl;
		tracer = tracer->succesor;
	}
}