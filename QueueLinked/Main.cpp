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
	while (!ql.isEmpty())
		cout << "\nRemoved -> " << ql.remove() << "from queue..\n";
	
}
