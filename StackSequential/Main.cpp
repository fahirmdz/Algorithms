//fahirmdz GitHub

#include"pch.h"
#include"StackSequential.h"
#include<cstdlib>
using namespace std;  


void main() {
	//testing functions
	Stack<int> *ss = new StackSequential<int>;
	ss->add(1);
	cout << "Added 1..\n";
	ss->add(2);
	cout << "Added 2..\n";
	ss->add(3);
	cout << "Added 3..\n";
	ss->add(4);
	cout << "Added 4..\n";
	ss->add(5);
	cout << "Added 5..\n";
	ss->add(6);
	cout << "Added 6..\n";

	while (!ss->isEmpty())
		cout << "\nRemoved -> " << ss->remove() << " from stack..\n";

}