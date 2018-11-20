//fahirmdz GitHub

#include"pch.h"
#include "MergeSort.h"

using namespace std;


void main() {
	//testing functions


	int A[] = { 25,14,7,76,10,64,20,30,9,2,6,77,83,12,56,46,61,51,33,26 }; 
	int	B[] = { 25,14,7,76,10,64,20,30,9,2,6,77,83,12,56,46,61,51,33,26 };


	cout << "--BEFORE--\n";
	for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
		cout << A[i] << " ";

	MergeSort(B, A, 0, sizeof(A) / sizeof(A[0]),0);
	cout << "\n--AFTER--\n";
	for (int i = 0; i < sizeof(B) / sizeof(B[0]); i++)
		cout << B[i] << " ";

}