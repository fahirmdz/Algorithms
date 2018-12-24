//fahirmdz GitHub


#pragma once
#include <exception>
#include<iostream>
#include<cstdlib>
using namespace std;


template<class T>
class Node {
public:
	Node *next;
	T info;

	Node(T info, Node<T> *next) {
		this->info = info;
		this->next = next;
	}

	Node *getNext()const { return next; }
	T getInfo()const { return info; }

	void setNext(Node<T> *next) { this->next = next; }
	void setInfo(T info) { this->info = info; }

	void print() {
		cout << "{ " << info << "} - " << "( " << next << ") \n";
	}
};