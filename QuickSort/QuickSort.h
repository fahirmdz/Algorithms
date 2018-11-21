#pragma once
#include<iostream>

using namespace std;

void Swap(int niz[], int i, int j) {

	cout << "rotacija: N[i=" << i << "] -> " << niz[i] << " i N[j=" << j << "] -> \t" << niz[j] << " \n";
	if (i != j) {
		int temp = niz[i];
		niz[i] = niz[j];
		niz[j] = temp;
	}
}

void QuickSort(int niz[], const int low, const int high) {
	if (low < high) {
		cout << "\nQuick sort: low=" << low << ", high=" << high << endl;
		int pivotloc = low, pivotkey = niz[low];
		for(int i=low+1;i<=high;i++)
			if (niz[i] < pivotkey) {
				pivotloc++;
				Swap(niz, pivotloc, i);
			}
		Swap(niz, low, pivotloc);
		QuickSort(niz, low, pivotloc - 1);
		QuickSort(niz, pivotloc + 1, high);
	}
}