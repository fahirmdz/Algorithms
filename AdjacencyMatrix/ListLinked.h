//fahirmdz GitHub

#pragma once
#include"List.h"
#include "Node.h"
#include <exception>


template<class T>
class ListLinked: public List<T> {
	int counter;
	Node<T> *first;

public:
	ListLinked():counter(0),first(nullptr){}
	void AddFirst(T x) {
		Node<T> *temp = new Node<T>(x, first);
		first = temp;
		counter++;
	}

	T RemoveFirst() {
		if (isEmpty())
			throw exception("List is empty..\n");
		Node<T> *temp = first;
		first = first->getNext();
		T value = temp->getInfo();
		delete temp;
		temp = nullptr;
		counter--;
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
				counter--;
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
	void AddLast(T x) {
		Node<T> *temp = new Node<T>(x, nullptr);
		if (isEmpty()) {
			first = temp;
			return;
		}
		Node<T> *z = first;

		while (z->getNext() != nullptr) {
			z = z->getNext();
		}
		counter++;
		z->setNext(temp);
	}

	T RemoveLast() {
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
		counter--;

		return value;
	}

	T GetByIndex(T i) {
		
		Node<T>* t = first;
		while (i > 0) {
			t = t->next;
			i--;
		}
		return t -> info;
	}
	T getByIndex(int i)
	{
		if (i > counter)
			throw exception("Index is bigger then counter..\n");

		Node<T>* t = first;
		for (int j = 0; j < (counter - i - 1); j++)
		{
			t = t->next;
		}
		return t->info;
	}
	bool isEmpty() { return first == nullptr; }
	int getCounter() { return counter; }
	void Print() {
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