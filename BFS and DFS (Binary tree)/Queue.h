//fahirmdz GitHub

#pragma once
#include "Node.h"

template<class T>
class Queue {

public:
	virtual void add(T v) = 0;
	virtual T remove() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
};