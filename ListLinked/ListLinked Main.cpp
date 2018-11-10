//fahirmdz GitHub

#pragma once

#include "pch.h"
#include "ListLinked.h"

void main() {
	ListLinked<int> x;
	x.addFirst(10);
	x.display();

	x.addFirst(20);
	x.display();

	x.addLast(50);
	x.display();

	cout << "Removed element --> " << x.removeFirst() << " from list..\n\n";
	x.display();

	cout << "Removed element --> " << x.removeLast() << " from list..\n\n";
	x.display();
}