#pragma once
#include"QueueLinked.h"
#include"QueueSequential.h"
#include"ListLinked.h"
#include"ListSequential.h"
#include"AdjacencyMatrix.h"

class BFSAlgorithmIteration {
private:
	int starTop;
	AdjacencyMatrix* M;

	BFSAlgorithmIteration(AdjacencyMatrix* M, int starTop) {
		this->M = M;
		this->starTop = starTop;
	}

	List<int>* _start() {
		this->M = M;
		List<int>* visited = new ListSequential<int>(M->_size);
		QueueLinked<int> queue;
		queue.add(starTop);

		while (!queue.isEmpty()) {
			int v = queue.remove();

			if (!visited->consist(v)) {
				visited->add(v);

				for (int i = 0; i < M->_size; i++) {
					if (M->isNeighbor(v, i)) {
						if (!queue.consist(i) && !visited->consist(i))
							queue.add(i);
					}
				}
			}
		}
		return visited;

	}

public:

	static List<int>* start(AdjacencyMatrix* M, int starTop = 0) {
		return BFSAlgorithmIteration(M, starTop)._start();
	}
};
