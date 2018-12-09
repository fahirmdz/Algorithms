//fahirmdz GitHub

#pragma once
#include"ListLinked.h"

class HashTableChaining {
private:
	int max, counter;
	ListLinked<int>* Array;

	int HashFunction(int key) {
		return key % max;
	}
public:
	HashTableChaining() {
		counter = 0;
		max = 3;
		Array = new ListLinked<int>[max];
	}

	void Add(int key) {
		int p = HashFunction(key);
		Array[p].addLast(key);
		counter++;
	}
	bool Remove(int key) { return Array[HashFunction(key)].RemoveByKey(key); }

	bool Search(int key) { return Array[HashFunction(key)].Search(key); }

	bool IsEmpty() { return counter == 0; }
};