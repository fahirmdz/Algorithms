#pragma once

#include"List.h"

template<class T>
class ListSequential : public List<T> {
private:
	T* N;
	int counter, max;

	void expandList() {
		max *= 2;
		T* temp = new T[max];
		for (int i = 0; i < max / 2; i++)
			temp[i] = N[i];
		delete[] N;
		N = temp;
		cout << "LIST: reconstruction - new size is " << max << endl;
	}

public:

	ListSequential(int max = 10) {
		this->max = max;
		N = new T[max];
		counter = 0;
	}
	ListSequential(List<T>* list, int max = 10) :ListSequential(max) {
		for (int i = 0; i < list->getCounter(); i++)
			add(list->get(i));
	}

	void add(T v) {
		if (max == counter)
			expandList();
		N[counter++] = v;
	}
	T remove() {
		if (isEmpty())
			throw exception("ERROR!\n");
		counter--;
		return N[counter];
	}
	bool isEmpty() { return counter == 0; }
	int getCounter() {return counter;}

	void print() {
		int i = 0;
		while (i < counter) {
			cout << N[i++] << " ";
		}
		cout << endl;
	}

	T& get(int i) {
		if (i > counter - 1 || i < 0)
			throw exception("Error!\n");
		return N[i];
	}
	T& operator[](int i) {
		return get(i);
	}
	void set(int i, T v) {
		get(i) = v;
	}
	bool consist(T v) {
		for (int i = 0; i < counter; i++)
			if (N[i] == v)
				return true;
		return false;
	}
	T* getArray() {
		return N;
	}
	T* createArray() {
		T* tempArray = new T[counter];

		for (int i = 0; i < counter; i++)
			tempArray[i] = N[i];
		return tempArray;
	 }
};