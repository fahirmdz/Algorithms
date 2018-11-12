//fahirmdz GitHub

#include"pch.h"
#include"PriorityQueueLinked.h"
#include<cstdlib>
using namespace std;  


void main() {
	//testing functions
	
	PriorityQueue<int> *pql = new PriorityQueueLinked<int>;

	pql->add(1);
	pql->add(2);
	pql->add(7);
	pql->add(3);
	pql->add(9);
	pql->add(4);
	pql->add(6);

	pql->print();
	while (!pql->isEmpty())
		cout << "\n\nRemoved -> " << pql->remove() << " from priority queue..\n";

}