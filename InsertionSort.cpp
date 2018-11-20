//fahirmdz GitHub

#include"pch.h"
#include<iostream>

using namespace std;

template<class T>
void insertionSort(T Niz[], int n) { 
	
	int i, j, pom;
	
	for (i = 1; i < n; i++) {
		j = i; 
		while (j > 0 && Niz[j - 1] > Niz[j]) {
			swap(Niz[j - 1], Niz[j]);
			j--;
		}
	} 
}
template<class T>
void printArray(T arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void main() {
	//testing functions

	int niz[] = { 5,4,3,2,1,9,8,7,6 };
	insertionSort<int>(niz, 9);
	printArray(niz, sizeof(niz) / sizeof(niz[0]));

}