#pragma once
#include"ListSequential.h"
#include"Edge.h"
#include"AdjacencyMatrix.h"

class DijkstraAlgorithm {
private:
	AdjacencyMatrix* M;

	int *dist, *prev;
	bool* visited;

	int startVertice, endVertice;
	
	DijkstraAlgorithm(AdjacencyMatrix* M, int startV, int endV) {
		this->M = M;
		dist = new int[M->_size];
		prev = new int[M->_size];
		visited = new bool[M->_size];

		startVertice = startV;
		endVertice = endV;
	}

	int minNotVisited() {
		int minDist = INT_MAX;
		int minVertice = -1;

		for (int i = 0; i < M->_size; i++) {
			if (!visited[i] && dist[i] < minDist) {
				minVertice = i;
				minDist = dist[i];
			}
		}
		return minVertice;
	}

	ListSequential<Edge*>* _start() {
		cout << "startVertice: " << startVertice << ", endVertice: " << endVertice << endl;
		ListSequential<Edge*>* result = new ListSequential<Edge*>;

		for (int i = 0; i < M->_size; i++) {
			dist[i] = INT_MAX;
			visited[i] = false;
		}
		dist[startVertice] = 0;

		//=======================================

		for (int i = 0; i < M->_size; i++) {
			int nVertice = minNotVisited();
			visited[nVertice] = true;

			int nDist = dist[nVertice];
			for (int sVertice = 0; sVertice < M->_size; sVertice++) {
				if (M->isNeighbor(nVertice, sVertice)) {
					int nsWeight = M->weight(nVertice, sVertice);

					int xDist = nDist + nsWeight;
					if (xDist < dist[sVertice]) {
						dist[sVertice] = xDist;
						prev[sVertice] = nVertice;
					}
				}
			}
		}
		int pathDistance = 0, w = endVertice;

		while (w != startVertice) {
			int p = prev[w], weight = M->weight(p, w);
			result->add(new Edge(p, w, weight));
			pathDistance += weight;
			w = p;
		}
		cout << "Total distance is: " << pathDistance << endl;
		return result;
	}

public:

	static List<Edge*>* start(AdjacencyMatrix* M, int startVertice, int endVertice) {
		return DijkstraAlgorithm(M, startVertice, endVertice)._start();
	}
};