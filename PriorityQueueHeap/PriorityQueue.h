#pragma once

#include"Cvor.h"

template<class T>
class PrioritetniRed {
	
virtual	void Dodaj(T) = 0;
virtual T Ukloni() = 0;
virtual bool isEmpty() = 0;
virtual	void print() = 0;
};