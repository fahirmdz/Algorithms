//fahirmdz GitHub

#pragma once
#include "Queue.h"
#include<cstdlib>

template<class T>
class QueueLinked :public Queue<T> {
private:
	Node<T> *start, *end;

public:
	QueueLinked() { start = end = nullptr; }

	void add(T x) {
		Node<T> *temp = new Node<T>(x, nullptr);
		if (end != nullptr) {
			end->setNext(temp);
			end = end->getNext();
		}
		else {
			end = temp;
			start = temp;
		}
	}

	T remove() {
		if (isEmpty()){
			cout << "Queue is empty..\n";
			return NULL;
	}
			Node<T> *t = start;
			start = start->getNext();
			T x = t->getInfo();
			if (start == nullptr)
				end = nullptr;
			return x;
		
	}

	bool isEmpty() { return start == nullptr; }

	void print() {
		cout << "QUEUE: ";
		if (isEmpty())
			cout << " --EMPTY--\n";
		else {
			Node<T> *t = start;
			while (t != nullptr) {
				cout << "{" << t->getInfo() << "} ";
				t = t->getNext();
			}
		}
	}
};
