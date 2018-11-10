//fahirmdz GitHub
//fahirmdz GitHub 

#pragma once
#include "Node.h"
#include <exception>


#pragma once
#include<iostream>
using namespace std;


template<class T>
class Node {
private:
	Node *next;
	T info;

public:
	Node(T info, Node<T> *next) {
		this->info = info;
		this->next = next;
	}

	Node *getNext()const { return next; }
	T getInfo()const { return info; }

	void setNext(Node<T> *next) { this->next = next; }
	void setInfo(T info) { this->info = info; }

	void print() {
		cout << "{ " << info << "} - " << "( " << next<<") \n";
	}
};