
//fahirmdz GitHub

#pragma once
#include"List.h"
#include "Node.h"
#include <exception>


template<class T>
class ListLinked : public List<T> {
	int counter;
	Node<T> *first;

public:
	ListLinked() :counter(0), first(nullptr) {}
	ListLinked(T* niz, int size)
	{
		counter = 0;
		for (int i = 0; i < size; i++)
			add(niz[i]);
	}
	ListLinked(List<T>* list)
	{
		for (int i = 0; i < list->getCounter(); i++)
		{
			add(list->get(i));
		}
	}
	ListLinked(List<T>& list) :ListLinked(&list) {}
	
	void add(T x) {
		Node<T> *temp = new Node<T>(x, first);
		first = temp;
		counter++;
	}

	T remove() {
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
	bool remove(T key) {
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
	
	bool isEmpty() { return first == nullptr; }
	int getCounter() { return counter; }
	void print() {
		if (isEmpty())
			throw exception("List is empty..\n");
		Node<T>* x = first;

		while (x != nullptr) {
			x->print();
			x = x->getNext();
		}
		cout << endl << endl;
	}
	void set(int i, T v)
	{
		get(i) = v;
	}

	T& get(int i)
	{
		if (i > counter)
			throw exception("Error");

		Node<T>* t = first;
		for (int j = 0; j < (counter - i - 1); j++)
		{
			t = t->next;
		}
		return t->info;
	}

	T& operator[](int i)
	{
		return get(i);
	}


	bool consist(T v)
	{
		Node<T>* t = first;
		while (t != nullptr)
		{
			if (t->info == v)
				return true;
			t = t->next;
		}
		return false;
	}

	T* createArray()
	{
		T* niz = new T[this->counter];

		int b = 0;
		Node<T>* t = first;
		while (t != nullptr)
		{
			niz[b++] = t->info;
			t = t->next;
		}
		return niz;
	}
};