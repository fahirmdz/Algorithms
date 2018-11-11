//fahirmdz GitHub

#include"pch.h"
#include"QueueLinked.h"

void main() {

	//testing functions

	QueueLinked<int> ql;

	ql.add(1);
	ql.print();
	cout << endl;
	ql.add(5);
	ql.print();
	cout << endl;
	ql.add(8);
	ql.print();
	cout << endl;
	int x = ql.remove();
	if (x != NULL)
		cout << "\nRemoved -> " << x << "from queue..\n";
	x = ql.remove();
	if (x != NULL)
		cout << "Removed -> " << x << " from queue..\n";
	x = ql.remove();
	if (x != NULL)
		cout << "Removed -> " << x << " from queue..\n";
	x = ql.remove(); //empty queue
	if (x != NULL)
		cout << "Removed -> " << x << " from queue..\n";
	x = ql.remove(); //empty queue
	if (x != NULL)
		cout << "Removed -> " << x << " from queue..\n";
	x = ql.remove(); //empty queue
	if (x != NULL)
		cout << "Removed -> " << x << " from queue..\n";

	ql.print();
}
