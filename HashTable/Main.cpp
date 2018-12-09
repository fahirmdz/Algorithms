//fahirmdz GitHub

#pragma once
#include<iostream>
using namespace std;

class HashTable {
private:
	int max = 10, counter = 0;
	int *Array = new int[max];
	bool* Busy = new bool[max];

	int HashFunction(int key) {
		return key % max;
	}
public:
	HashTable() {
		for (int i = 0; i < max; i++)
			Busy[i] = false;
	}
	void Add(int key) {
		if (IsFull())
		{
			cout << "Array is full!\n";
			return;
		}
		int p = HashFunction(key);
		while (Busy[p]) {
			p++;
			if (p == max)
				p = 0;
		}
		Array[p] = key;
		Busy[p] = true;
		counter++;
		
	}
	
	bool Remove(int key) {
		int x = Search(key);
		if (x!=-1) {
			Busy[x] = false;
			counter--;
			return true;
		}
		return false;
	}
	int Search(int key) {
		if (IsEmpty())
		{
			cout << "Array is empty!\n";
			return -1;
		}
		int p = HashFunction(key);
		int temp = p;
		while (true) {
			if (Busy[p] && Array[p] == key)
				return key;
			p++;
			if (p == max)
				p = 0;

			if (temp == p)
				return -1;
		}
		return -1;
	}

	bool IsEmpty() { return counter == 0; }
	bool IsFull() { return counter == max; }


};