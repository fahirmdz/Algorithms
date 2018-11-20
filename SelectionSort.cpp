//fahirmdz GitHub

#include"pch.h"
#include<iostream>

using namespace std;

template<class T>
void selectionSort(T Niz[], int n) { 
	
	int i, j, minIndex, pom; 
	
	for (i = 0; i < n - 1; i++) {
		minIndex = i;   
		for (j = i + 1; j < n; j++)  
			if (Niz[j] < Niz[minIndex]) 
				minIndex = j; 
		if (minIndex != i) {
			pom = Niz[i];  
			Niz[i] = Niz[minIndex];  
			Niz[minIndex] = pom; 
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
	selectionSort<int>(niz, 9);
	printArray(niz, sizeof(niz) / sizeof(niz[0]));

}