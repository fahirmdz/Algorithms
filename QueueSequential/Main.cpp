//fahirmdz GitHub

#include "pch.h"
#include "QueueSequential.h"

void main() {
	//Testing functions

	QueueSequential<int> qs;
	qs.add(1);
	qs.print();
	
	qs.add(5);
	qs.print();

	qs.add(10);
	qs.print();
	int x = qs.remove();
	if (x != NULL)
		cout << "\n\nRemoved -> " << x << " from queue..";
	
	 x = qs.remove();
	if (x != NULL)
		cout << "\n\nRemoved -> " << x << " from queue..";

	 x = qs.remove();
	if (x != NULL)
		cout << "\n\nRemoved -> " << x << " from queue..";

     x = qs.remove();  //empty queue
	if (x != NULL)
		cout << "\n\nRemoved -> " << x << " from queue..";
}