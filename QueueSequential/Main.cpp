//fahirmdz GitHub

#include "pch.h"
#include "QueueSequential.h"

void main() {
	//Testing functions

	Queue<int> *qs=new QueueSequential<int>;
	qs->add(1);
	qs->print();
	
	qs->add(5);
	qs->print();

	qs->add(10);
	qs->print();
	

	while (!qs->isEmpty())
		cout << "Removed -> " << qs->remove() << " from queue..\n";
}