//fahirmdz GitHub

#pragma once
#include "Queue.h"
#include<exception>

template<class T>
class QueueSequential :public Queue<T> {
private:
	int max = 100, counter, start, end;
	T *N;

	void expandQueue() {
		max *= 2;
		T *temp = new T[max];
		for (int i = 0; i < counter; i++)
			temp[i] = N[i];
		delete[] N;
		N = temp;
		cout << "\nQUEUE: reconstruction - new size is " << max << endl;
	}

public:
	QueueSequential(int max = 3) {
		this->max = max;
		N = new T[max];
		counter = start = end = 0;
	}
	
	void add(T x) {
		if (counter == max)
			expandQueue();
		N[end++] = x;
		if (end == max)
			end = 0;
		counter++;
	}

	T remove() {
		if (isEmpty()) {
			throw exception("Queue is empty..\n");

		T value = N[start++];
		counter--;
		if (start == max)
			start = 0;
		return value;
	}
	bool isEmpty() { return counter == 0; }

	void print() {
		cout << "\nQUEUE: ";
		if (isEmpty())
			cout << "--EMPTY--\n";
		else {
			int i = start, b = 0;
			while (b < counter) {
				cout << "{" << N[i++] << "} ";
				b++;
				if (i == max)
					i = 0;
			}
		}
	}
};