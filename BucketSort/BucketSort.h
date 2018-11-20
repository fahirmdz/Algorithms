//fahirmdz GitHub

#pragma once
#include "PriorityQueueLinked.h"

template<class T>
int GetMax(T* a, int max) {
	int maxV = a[0];
	for (int i = 1; i < max; i++) {
		if (a[i] > maxV)
			maxV = a[i];
	}
	return maxV;
}
template<class T>
void Sortiraj(T A[], int n) {
	PriorityQueueLinked<T>* X = new PriorityQueueLinked<T>[n];
	int maxV = GetMax(A, n);
	for (int i = 0; i < n; i++) {
		int value = A[i];
		int p = value * n / (maxV + 1);
		X[p].add(value);
	}
	int counter = n - 1;
	for (int i = n - 1; i >= 0; --i) {
		PriorityQueueLinked<T>& x = X[i];
		while (!x.isEmpty()) {
			int value = x.remove();
			//Priority Queue
			A[counter--] = value;
		}
	}
}