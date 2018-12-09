//fahirmdz GitHub

#pragma once
#include "Node.h"
#include <exception>


template<class T>
class ListLinked {
	Node<T> *first;

public:
	ListLinked() { first = nullptr; }

	void addFirst(T x) {
		Node<T> *temp = new Node<T>(x, first);
		first = temp;
	}

	T removeFirst() {
		if (isEmpty())
			throw exception("List is empty..\n");
		Node<T> *temp = first;
		first = first->getNext();
		T value = temp->getInfo();
		delete temp;
		temp = nullptr;
		return value;
	}
	bool RemoveByKey(T key) {
		Node<T> *z = first, *y = nullptr;

		while (z != nullptr) {
			if (z->getInfo() == key) {
				if (y != nullptr)
					y->setNext(z->getNext());
				delete z;
				z = nullptr;
				return true;
			}
			y = z;
			z = z->getNext();
		}
		return false;
	}
	bool Search(T key) {
		Node<T>* z = first;

		while (z != nullptr) {
			if (z->getInfo() == key)
				return true;
			z = z->getNext();
		}
		return false;
	}
	void addLast(T x) {
		Node<T> *temp = new Node<T>(x, nullptr);
		if (isEmpty()) {
			first = temp;
			return;
		}
		Node<T> *z = first;

		while (z->getNext() != nullptr) {
			z = z->getNext();
		}
		z->setNext(temp);
	}

	T removeLast() {
		if (isEmpty())
			throw exception("List is empty..\n");
		Node<T> *x = first;
		Node<T> *xy = nullptr;
		while (x->getNext() != nullptr)
		{
			xy = x;
			x = x->getNext();
		}
		T value = x->getInfo();
		delete x;
		x = nullptr;
		if (xy == nullptr)
			first = nullptr;
		else
			xy->setNext(nullptr);
		return value;
	}
	bool isEmpty() { return first == nullptr; }

	void display() {
		if (isEmpty())
			throw exception("List is empty..\n");
		Node<T>* x = first;

		while (x != nullptr) {
			x->print();
			x = x->getNext();
		}
		cout << endl << endl;
	}
};