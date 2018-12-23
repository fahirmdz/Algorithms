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
	virtual T GetByIndex(int) = 0;
	virtual void Print() = 0;
	virtual T& get(int) = 0;
	virtual T& operator[](int) = 0;
	virtual void set(int,T) = 0;
	virtual bool consist(T) = 0;
	virtual T* createArray() = 0;
};