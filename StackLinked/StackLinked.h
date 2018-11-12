//fahirmdz GitHub

#pragma once
#include"Stack.h"

template<class T>
class StackLinked :public Stack<T> {
private :
	Node<T> *first;

public:
	StackLinked() { first = nullptr; }

	void add(T x) {
		Node<T> *temp = new Node<T>(x, first);
		first = temp;
	}

	T remove() {
		if (isEmpty())
			throw exception("Stack is empty");
			Node<T> *t = first;
			first = first->getNext();
			T x = t->getInfo();
			delete t;
		return x;
		
	}

	bool isEmpty() { return first == nullptr; }

	void print() {
		cout << "\nSTACK: ";
		Node<T>* t = first;
		while (t != nullptr) {
			cout << "{" << t->getInfo() << "} ";
			t = t->getNext();
		}
	}
};