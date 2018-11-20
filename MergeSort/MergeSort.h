//fahirmdz GitHub

#pragma once
#include<iostream>

using namespace std;

void Merge(int Temp[], int Element[], const int list1, const int size1, const int list2, const int size2, int brojac) {
	int i = list1, j = list2, k = list1;
	
	while (i < list1 + size1 && j < list2 + size2) {
		
		if (Temp[i] < Temp[j])  
			Element[k++] = Temp[i++];  
		else   
			Element[k++] = Temp[j++]; }

	while (i < list1 + size1)  
		Element[k++] = Temp[i++]; 
	while (j < list2 + size2)  
		Element[k++] = Temp[j++];  
	for (k = list1; k < list1 + size1 + size2; k++)
		Temp[k] = Element[k];

}

void MergeSort(int Temp[], int Element[], const int list1, const int size,int brojac) {
	int list2, size1, size2;
	
	if (size > 1) { 
		list2 = list1 + size / 2; 
	size1 = list2 - list1;  
	size2 = size - size1; 
	MergeSort(Temp, Element, list1, size1,brojac); 
	MergeSort(Temp, Element, list2, size2,brojac); 
	Merge(Temp, Element, list1, size1, list2, size2,0); 
	}
}
