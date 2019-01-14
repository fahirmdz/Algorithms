#pragma once
#include<iostream>
using namespace std;

template<class T>
class List {
public:
	virtual void add(T) = 0;
	virtual T remove() = 0;
	virtual bool isEmpty() = 0;
	virtual int getCounter() = 0;
	virtual void print() = 0;
	virtual T& get(int) = 0;
	virtual T& operator[](int) = 0;
	virtual void set(int,T) = 0;
	virtual bool consist(T) = 0;
	virtual T* createArray() = 0;
};