//fahirmdz GitHub

#pragma once
#include "PriorityQueue.h"

template<class T>
class PriorityQueueLinked : public PriorityQueue<T> {
private:
	Node<T> *first;

public:
	void add(T x) {
		Node<T> *temp = new Node<T>(x, first);
		if (first == nullptr) {
			first = temp;
			first->setNext(nullptr);
			return;
		}
		Node<T> *t = first;
		Node<T> *p = nullptr;
		while (t != nullptr) {
			if (temp->getInfo() > t->getInfo())
				break;
			p = t;
			t = t->getNext();
		}
		temp->setNext(t);
		if (p == nullptr)
			first = temp;
		else p->setNext(temp);
	}

	T remove() {
		if (isEmpty())
			throw exception("Priority queue is empty..\n");

		Node<T> *t = first;
		first = first->getNext();
		T x = t->getInfo();
		delete t;
		return x;
	}

	bool isEmpty() { return first == nullptr; }

	void print() {
		cout << "\nPRIORITY QUEUE: ";
		Node<T> *t = first;
		while (t != nullptr) {
			cout << "{" << t->getInfo() << "} ";
			t = t->getNext();
		}
	}
};