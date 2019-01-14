#pragma once
#include<iostream>
#include<cstring>

using namespace std;

class Edge {
	int startVertice, endVertice, weight;

public:
	Edge() {}

	Edge(int startVertice, int endVertice, int weight) {
		this->startVertice = startVertice;
		this->endVertice = endVertice;
		this->weight = weight;
	}

	friend ostream& operator<<(ostream& o, Edge* e)
	{
		return operator<<(o, *e);
	}

	friend ostream& operator<<(ostream& o, Edge& e) {
		o << "t(" << e.startVertice << "," << e.endVertice << ") = " << e.weight;
		return o;
	}
	friend bool operator>(Edge& left, Edge& right) {
		return left.weight < right.weight;
	}
};