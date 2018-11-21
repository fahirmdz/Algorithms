//fahirmdz GitHub

#include"pch.h"
#include "QuickSort.h"

using namespace std;


void main() {
	//testing functions

	int	B[] = { 25,14,7,76,10,64,20,30,9,2,6,77,83,12,56,46,61,51,33,26 };


	cout << "--BEFORE--\n";
	for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
		cout << B[i] << " ";

	QuickSort(B, 0, sizeof(B) / sizeof(B[0])-1);
	cout << "\n--AFTER--\n";
	for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
		cout << B[i] << " ";

}