//fahirmdz GitHub

#pragma once
#include "Stack.h"

template<class T>
class StackSequential :public Stack<T> {
private:
	int counter, max;
	T *N;

	void expandStack() {
		max *= 2;
		T *temp = new T[max];
		for (int i = 0; i < counter; i++)
			temp[i] = N[i];
		delete[] N;
		N = temp;
		cout << "\nSTACK: reconstruction - new size is " << max << endl;
	}

public:
	StackSequential(int max = 3) {
		this->max = max;
		N = new T[max];
		counter = 0;
	}

	void add(T x) {
		if (max == counter)
			expandStack();
		N[counter++] = x;
	}

	T remove() {
		if (isEmpty())
			throw exception("Stack is empty..\n");

		T temp = N[--counter];
		return temp;
	}

	bool isEmpty() { return counter == 0; }

	void print() {
		cout << "\nSTACK: ";
		int i = 0;
		while (i < counter) {
			cout << "{" << N[i++] << "} ";
		}
	}
};