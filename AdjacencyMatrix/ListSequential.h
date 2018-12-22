#pragma once
#include <iostream>
#include"List.h"

using namespace  std;

template<class T>
class ListSequential: public List<T> {

private:
	int size;
	T* N;
	int counter;

	void expandArray()
	{
		T* novi = new T[size * 2];
		for (int i = 0; i < counter; i++)
		{
			novi[i] = N[i];
		}

		size = size * 2;
		delete[] N;
		N = novi;
	}


public:
	ListSequential(int s = 10) :size(s), counter(0) { N = new T[s]; }
	bool JeLiPuna()
	{
		return (counter == size);
	}



	void AddLast(T x)
	{
		if (JeLiPuna())
		{
			expandArray();
		}

		N[counter] = x;
		counter++;
	};
	void AddFirst(T x)
	{
		if (isEmpty())
		{
			expandArray();
		}

		for (int i = counter - 1; i >= 0; i--)
		{
			N[i + 1] = N[i];
		}

		counter++;

		N[0] = x;

	}
	void Print()
	{
		for (int i = 0; i < counter; i++)
		{
			cout << N[i] << endl;
		}
	};
	int getCounter()
	{
		return counter;
	}
	T RemoveLast()
	{
		if (isEmpty())
		{
			cout << "Error! Empty list..";
			return 0;
		}

		counter--;
		T x = N[counter];

		return x;
	}
	T RemoveFirst()
	{
		if (isEmpty())
		{
			cout << "Error! Empty list..";

			return 0;
		}

		T x = N[0];


		for (int i = 1; i < counter; i++)
		{
			N[i - 1] = N[i];
		}
		counter--;
		return x;
	}
	T getByIndex(int i)
	{
		if (i > counter)
			throw exception("Index is bigger then counter..\n");

		return N[i];
	}
	bool isEmpty()
	{
		return (counter == 0);
	}
};
