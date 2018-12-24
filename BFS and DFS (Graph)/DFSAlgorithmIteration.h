#pragma once
#include"StackLinked.h"
#include"ListLinked.h"
#include"ListSequential.h"
#include"AdjacencyMatrix.h"
#include"QueueLinked.h"

class DFSAlgorithmIteration {
private:
	int starTop;
	AdjacencyMatrix* M;

	DFSAlgorithmIteration(AdjacencyMatrix* M, int starTop = 0) {
		this->M = M;
		this->starTop = starTop;
	}


	List<int>* _start() {
		this->M = M;
		List<int>* visited = new ListSequential<int>(M->_size);
		
		StackLinked<int> stack;
		stack.add(starTop);

		while (!stack.isEmpty()) {
			int v = stack.remove();
			if (!visited->consist(v)) {
				visited->add(v);

				for (int i = M->_size - 1; i >= 0; i--) {
					if (M->isNeighbor(v, i))
						if (!visited->consist(i))
							stack.add(i);
				}
			}
		}
		
		return visited;
	}

public:
	static List<int>* start(AdjacencyMatrix* M, int starTop = 0) {
		return DFSAlgorithmIteration(M, starTop)._start();
	}
};