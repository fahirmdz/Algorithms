//fahirmdz GitHub

#include"pch.h"
#include"DFSAlgorithmRecursion.h"
#include"DFSAlgorithmIteration.h"
#include"BFSAlgorithmIteration.h"
using namespace std;  

void main() {

	AdjacencyMatrix matrix(9);
	matrix.Ucitaj("MatricaTest.txt");
	matrix.printMatrix();

	cout << "\n\nDFS (recursion): ";
	DFSAlgorithmRecursion::start(&matrix,0)->print();

	cout << "\n\nDFS (iteration, stack): ";
	DFSAlgorithmIteration::start(&matrix, 0)->print();

	cout << "\n\nBFS (iteration, queue): ";
	BFSAlgorithmIteration::start(&matrix, 0)->print();


}