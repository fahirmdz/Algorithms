#pragma once
#include<iostream>
#include"ListSequential.h"
#include"ListLinked.h"
#include<fstream>

using namespace std;

class AdjacencyMatrix {
public:

	int** matrix = new int*[20];
	int _size;
	AdjacencyMatrix(int size) :_size(size) {

		for (int i = 0; i < _size; i++) {
			matrix[i] = new int[_size];
			for (int j = 0; j < _size; j++)
				matrix[i][j] = 0;
		}
	}

	void Ucitaj(string fileName) {
		int variable;
		ifstream file(fileName);
		if (file.fail()) {
			cout << "Error! Can't open file..\n";
			return;
		}
		for (int i = 0; i < _size; i++)
			for (int j = 0; j < _size; j++) {
				file >> variable;
				matrix[i][j] = variable;
			}
		file.close();
	}

	void printMatrix() {
		for (int i = 0; i < _size; i++) {
			for (int j = 0; j < _size; j++)
				cout << matrix[i][j] << " ";
			cout << endl;
		}
	}

	bool isNeighbor(int from, int to) {
		return matrix[from][to] != 0;
	}

	ListLinked<int>* neighborTo(int x) {
		ListLinked<int>* obj = new ListLinked<int>;
		for (int i = 0; i < _size; i++) {
			if (isNeighbor(i, x))
				obj->add(i);
		}
		return obj;
	}

	ListLinked<int>* neighborFrom(int x) {
		ListLinked<int>* obj = new ListLinked<int>;
		for (int i = 0; i < _size; i++) {
			if (isNeighbor(x, i))
				obj->add(i);
		}
		return obj;
	}
	int inDegree(int j, int x = 0) {
		if (x >= _size)
			return 0;
		return matrix[j][x] + inDegree(j, x + 1);
	}

	int outDegree(int i, int x = 0) {
		if (x >= _size)
			return 0;
		return matrix[x][i] + outDegree(i, x + 1);
	}

	int weight(int from, int to) {
		return matrix[from][to];
	}

	int closestNeighborTo(int x) {

		int minI = 0;
		int minV = INT_MAX;
		List<int>* neighbors = neighborTo(x);
		while (!neighbors->isEmpty()) {

			int temp = neighbors->remove();
			int t = weight(temp, x);
			if (t < minV) {
				minV = t;
				minI = temp;
			}
		}

		return minI;
	}

	int outDegreeMax() {
		int maxI = 0;
		int maxV = outDegree(maxI);
		for (int i = 1; i < _size; i++) {
			int t = outDegree(i);
			if (maxV < t)
			{
				maxV = t;
				maxI = i;
			}
		}return maxI;
	}

	int inDegreeMax() {
		int maxI = 0;
		int maxV = inDegree(maxI);
		for (int i = 1; i < _size; i++) {
			int t = inDegree(i);
			if (maxV < t)
			{
				maxV = t;
				maxI = i;
			}
		}return maxI;
	}

	void createLinkedListAdjacency() {
		ListSequential<ListLinked<int>*>* list = new ListSequential<ListLinked<int>*>;

		for (int i = 0; i < _size; i++)
			list->add(neighborFrom(i));
	}
};