#pragma once
#include <iostream>


template <class T>
class LDI
{
	class Node {
	public:
		friend class LDI;
	private:
		T info;
		Node* predecesor;
		Node* succesor;

		Node(T info, Node* pred = nullptr, Node* succ = nullptr) : info(info), predecesor(pred), succesor(succ) {}
	};

	Node* FRONT = nullptr;
	Node* END = nullptr;

	T getInfo(Node* n) { return n->info; }
	Node* getSuccesor(Node* n) { return n->succesor; }

public:
	LDI() {}
	LDI(const LDI&);
	~LDI();

	LDI& operator++() {}		// doesn t make sense as its required to add an 
	void operator++(T item);
	LDI& operator--() {}		// doesn t make sense as its required to add an ADT
	void operator--(T item);
	LDI& operator+=(const LDI&);
	void print();
	friend std::ostream & operator<<(std::ostream & os, LDI<T> & list) {
		Node* tracer = list.FRONT;
		while (tracer) {
			os << list.getInfo(tracer) << " ";
			tracer = list.getSuccesor(tracer);
		}
		//os << std::endl;

		return os;
	}
};

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

		END = new Node(tracer->info, tracer->predecesor, tracer->succesor);
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
void LDI<T>::operator++(T item) {
	if (!FRONT) {
		FRONT = END = new Node(item);
	}
	else {
		Node* tmp = new Node(item, END);
		END->succesor = tmp;
		END = tmp;
	}
}

template <class T>
void LDI<T>::operator--(T item) {
	if (!FRONT) {
		return;
	}

	Node* _toDelete = END;
	END = END->predecesor;
	delete[] _toDelete;
}

template <class T>
LDI<T>& LDI<T>::operator+=(const LDI& list) {
	Node* tracer = list.FRONT;
	while (tracer) {
		this->operator++(tracer->info);
		tracer = tracer->succesor;
	}

	return *this;
}

template <class T>
void LDI<T>::print() {
	Node* tracer = FRONT;
	while (tracer) {
		std::cout << tracer->info << " ";
		tracer = tracer->succesor;
	}
	putchar('\n');
}