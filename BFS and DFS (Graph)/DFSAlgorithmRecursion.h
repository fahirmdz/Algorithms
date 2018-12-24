#pragma once

#include"ListSequential.h"
#include"AdjacencyMatrix.h"
using namespace std;

class DFSAlgorithmRecursion {
private:
	int starTop;
	AdjacencyMatrix* M;
	List<int>* visited;

	DFSAlgorithmRecursion(AdjacencyMatrix* M, int starTop) {
		this->M = M;
		this->visited = new ListSequential<int>;
		this->starTop = starTop;
	}

	List<int>* _start() {
		Recursion(starTop);
		return visited;
	}

	void Recursion(int v) {
		visited->add(v);
		for (int i = 0; i < M->_size; i++)
			if (M->isNeighbor(v, i) && !visited->consist(i))
				Recursion(i);
	}


public:

	static List<int>* start(AdjacencyMatrix* M, int starTop = 0) {
		return DFSAlgorithmRecursion(M, starTop)._start();
	}
};