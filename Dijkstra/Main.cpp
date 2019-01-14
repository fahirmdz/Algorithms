//fahirmdz GitHub
#include"DijkstraAlgorithm.h"
using namespace std;  

void main() {
	AdjacencyMatrix M(9);
	M.Ucitaj("MatricaTest.txt");
	DijkstraAlgorithm::start(&M, 0, 8);

}