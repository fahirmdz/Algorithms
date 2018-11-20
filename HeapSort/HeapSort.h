//fahirmdz GitHub

#pragma once
#include<iostream>

using namespace std;

template<class T>
void BubbleDown(T N[],int n,int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l<n && N[l]>N[largest])
		largest = l;

	if (r<n && N[r]>N[largest])
		largest = r;

	if (largest != i) {
		swap(N[i], N[largest]);
		BubbleDown(N, n, largest);
	}
}

template<class T>
void heapSort(T arr[], int n) {


	for (int i = n / 2 - 1; i >= 0; i--)
		BubbleDown(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		n--;
		BubbleDown(arr, n, 0);
	}
}
void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}