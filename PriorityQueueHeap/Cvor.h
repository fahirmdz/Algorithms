#pragma once
#include<iostream>
using namespace std;

template<class T>
class Cvor {
public:
	T value;
	Cvor* next;
	Cvor(T value, Cvor* next) {
		this->value = value;
		this->next = next;
	}
};