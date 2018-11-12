//fahirmdz GitHub

#include"pch.h"
#include"StackLinked.h"
#include<cstdlib>
using namespace std;  


void main() {
	//testing functions

	StackLinked<int> sl;

	sl.add(0);
	sl.add(0);
	sl.add(3);
	sl.add(4);

	sl.print();

	while (!sl.isEmpty())
		cout << "\n\nRemoved -> " << sl.remove() << " from stack..\n";
		

}