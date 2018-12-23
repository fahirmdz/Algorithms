#pragma once

#include "Node.h"

template<class T>
class Stack {
public:
	virtual void add(T x) = 0;
	virtual T remove() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};