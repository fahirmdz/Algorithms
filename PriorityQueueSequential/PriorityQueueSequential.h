//fahirmdz GitHub

#pragma once
#include "PriorityQueue.h"

using namespace std;

template<class T>
class PriorityQueueSequential : public PriorityQueue<T> {
	T* N;
	int counter, max;

	void expandPQ() {
		max *= 2;
		T* temp = new T[max];
		for (int i = 0; i < counter; i++)
			temp[i] = N[i];
		delete[] N;
		N = temp;
		cout << "\nPQ: reconstruction - new size is " << max << endl;
	}

public:
	PriorityQueueSequential(int max = 3) {
		this->max = max;
		N = new T[max];
		counter = 0;
	}
	void add(T x) {
		if (counter == max)
			expandPQ();
		N[counter++] = x;
	}

	T remove() {
		if (isEmpty())
			throw exception("Error. Priority queue is empty..\n");
		int maxI = 0;
		T maxV = N[0];
		for (int i = 1; i < counter; i++) {
			if (N[i] > maxV) {
				maxV = N[i];
				maxI = i;
			}
		}
		N[maxI] = N[counter - 1];
		counter--;
		return maxV;
	}

	bool isEmpty() { return counter == 0; }
	
	void print() {
		cout << "\nPRIORITY QUEUE: ";
		int i = 0;
		while (i < counter) {
			cout << "{" << N[i++] << "}";
		}
	}
};