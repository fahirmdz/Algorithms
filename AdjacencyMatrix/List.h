#pragma once

template<class T>
class List {
public:
	virtual void AddFirst(T) = 0;
	virtual T RemoveFirst() = 0;

	virtual void AddLast(T) = 0;
	virtual T RemoveLast() = 0;
	virtual bool isEmpty() = 0;
	virtual int getCounter() = 0;
	virtual T getByIndex(int) = 0;
	virtual void Print() = 0;
};