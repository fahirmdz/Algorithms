//fahirmdz GitHub

#include"pch.h"
#include"HeapSort.h"

void main() {
	//testing functions

	int niz[] = { 5,4,3,2,1,9,8,7,6 };
	heapSort<int>(niz, 9);
	printArray(niz, sizeof(niz) / sizeof(niz[0]));

}